#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

class Producer {
public:
    Producer(std::queue<int>& dataQueue, std::mutex& mtx, std::condition_variable& cv)
        : dataQueue(dataQueue), mtx(mtx), cv(cv) {}

    void produce(int maxItems) {
        for (int i = 0; i < maxItems; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            dataQueue.push(i);
            std::cout << "Produit : " << i << std::endl;
            cv.notify_one(); // Notifier le consommateur
        }
    }

private:
    std::queue<int>& dataQueue;
    std::mutex& mtx;
    std::condition_variable& cv;
};

class Consumer {
public:
    Consumer(std::queue<int>& dataQueue, std::mutex& mtx, std::condition_variable& cv)
        : dataQueue(dataQueue), mtx(mtx), cv(cv) {}

    void consume() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return !dataQueue.empty(); }); // Attente conditionnelle
            int value = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consommé : " << value << std::endl;
        }
    }

private:
    std::queue<int>& dataQueue;
    std::mutex& mtx;
    std::condition_variable& cv;
};

int main() {
    std::queue<int> dataQueue;
    std::mutex mtx;
    std::condition_variable cv;

    Producer producer(dataQueue, mtx, cv);
    Consumer consumer(dataQueue, mtx, cv);

    std::thread producerThread(&Producer::produce, &producer, 10);
    std::thread consumerThread(&Consumer::consume, &consumer);

    producerThread.join();
    consumerThread.detach(); // Pour cet exemple, détaché car la boucle consommateur est infinie.

    return 0;
}
