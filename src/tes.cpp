#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

class SharedData {
public:
    std::vector<int> shared_list; // Liste partagée
    std::mutex list_mutex; // Mutex pour protéger l'accès
    std::condition_variable list_condition; // Condition pour synchroniser les threads
};

class Producer {
private:
    SharedData& data; // Référence à la structure partagée
public:
    explicit Producer(SharedData& sharedData) : data(sharedData) {}

    void addToList(int value) {
        {
            std::unique_lock<std::mutex> lock(data.list_mutex);
            data.shared_list.push_back(value);
            std::cout << "Producer: Added " << value << " to list\n";
        }
        data.list_condition.notify_one(); // Notifier que la liste a changé
    }
};

class Consumer {
private:
    SharedData& data; // Référence à la structure partagée
public:
    explicit Consumer(SharedData& sharedData) : data(sharedData) {}

    void processList() {
        std::unique_lock<std::mutex> lock(data.list_mutex);
        data.list_condition.wait(lock, [this] {
            return !data.shared_list.empty(); // Attendre que la liste ne soit pas vide
        });

        int value = data.shared_list.back();
        data.shared_list.pop_back();
        std::cout << "Consumer: Processed " << value << " from list\n";
    }
};

int main() {
    SharedData sharedData; // Données partagées entre les threads
    Producer producer(sharedData);
    Consumer consumer(sharedData);

    ThreadPool pool(4); // Pool de threads avec 4 threads

    // Ajouter des tâches dans le pool de threads
    pool.enqueue(&Producer::addToList, &producer, 42);
    pool.enqueue(&Producer::addToList, &producer, 7);
    pool.enqueue(&Consumer::processList, &consumer);
    pool.enqueue(&Consumer::processList, &consumer);

    // Donner du temps aux threads pour terminer leur exécution
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}
