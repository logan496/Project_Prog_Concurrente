// #include <memory>
// #include <string>
// #include <chrono>
// #include <thread>
//
// class ClientModel {
// public:
//     int id;
//     std::string type;
//     explicit ClientModel(int id, const std::string& type) : id(id), type(type) {}
// };
//
// class ClientGroup {
// public:
//     void processClient(const std::shared_ptr<ClientModel>& client) {
//         std::cout << "ClientGroup: Traitement du client " << client->id
//                   << " de type " << client->type << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simuler un traitement
//     }
// };
//
// class ClientGroupFactory {
// private:
//     int clientIdCounter = 0;
//
// public:
//     std::shared_ptr<ClientModel> createClientModel() {
//         clientIdCounter++;
//         std::string clientType = (clientIdCounter % 2 == 0) ? "Cool" : "Hurry";
//         return std::make_shared<ClientModel>(clientIdCounter, clientType);
//     }
// };
//
// void factoryTask(ClientGroupFactory& factory, ThreadPool& threadPool, ClientGroup& clientGroup, int numClients) {
//     for (int i = 0; i < numClients; ++i) {
//         auto client = factory.createClientModel();
//         std::cout << "Factory: Créé le client " << client->id << " de type " << client->type << "\n";
//
//         // Envoi de la tâche au pool de threads
//         threadPool.enqueueTask([client, &clientGroup]() {
//             clientGroup.processClient(client);
//         });
//
//         std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simuler un délai entre créations
//     }
// }
//
// int main() {
//     ClientGroupFactory factory;
//     ClientGroup clientGroup;
//
//     // Crée un pool de 4 threads
//     ThreadPool threadPool(4);
//
//     int numClients = 10;
//
//     // Lancer la factory dans le thread principal
//     factoryTask(factory, threadPool, clientGroup, numClients);
//
//     std::cout << "Tous les clients ont été envoyés au pool de threads.\n";
//
//     return 0;
// }
//
// #include <iostream>
// #include <queue>
// #include <thread>
// #include <mutex>
// #include <condition_variable>
// #include <functional>
// #include <vector>
// #include <memory>
// #include <atomic>
//
// // Classe ThreadPool
// class ThreadPool {
// private:
//     std::vector<std::thread> workers;
//     std::queue<std::function<void()>> tasks;
//     std::mutex mtx;
//     std::condition_variable cv;
//     bool stop = false;
//
// public:
//     explicit ThreadPool(size_t threadCount) {
//         for (size_t i = 0; i < threadCount; ++i) {
//             workers.emplace_back([this] {
//                 while (true) {
//                     std::function<void()> task;
//                     {
//                         std::unique_lock<std::mutex> lock(this->mtx);
//                         this->cv.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
//
//                         if (this->stop && this->tasks.empty()) return;
//
//                         task = std::move(this->tasks.front());
//                         this->tasks.pop();
//                     }
//                     task();
//                 }
//             });
//         }
//     }
//
//     ~ThreadPool() {
//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             stop = true;
//         }
//         cv.notify_all();
//         for (std::thread &worker : workers) {
//             if (worker.joinable()) worker.join();
//         }
//     }
//
//     void enqueueTask(std::function<void()> task) {
//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             tasks.push(std::move(task));
//         }
//         cv.notify_one();
//     }
// };
// // Classe représentant un client
// /**
//  * ici se séparent les deux
//  */
// class ClientModel {
// public:
//     int id;
//     std::string type;
//
//     ClientModel(int id, const std::string& type) : id(id), type(type) {}
// };
//
// // Factory pour créer des clients
// class ClientGroupFactory {
// private:
//     int clientIdCounter = 0;
//
// public:
//     std::shared_ptr<ClientModel> createClientModel() {
//         clientIdCounter++;
//         std::string clientType = (clientIdCounter % 2 == 0) ? "Cool" : "Hurry";
//         return std::make_shared<ClientModel>(clientIdCounter, clientType);
//     }
// };
//
// // Classe représentant un groupe de clients
// class ClientGroup {
// public:
//     void addClient(const std::shared_ptr<ClientModel>& client) {
//         std::cout << "ClientGroup : Ajout du client " << client->id
//                   << " de type " << client->type << "\n";
//     }
// };
//
// // TaskManager : Gère l'interaction entre les composants
// // class TaskManager {
// // private:
// //     ClientGroupFactory& factory;
// //     ClientGroup& clientGroup;
// //     ThreadPool& threadPool;
// //     std::atomic<bool> running;
// //
// // public:
// //     TaskManager(ClientGroupFactory& factory, ClientGroup& clientGroup, ThreadPool& pool)
// //         : factory(factory), clientGroup(clientGroup), threadPool(pool), running(false) {}
// //
// //     void start(size_t taskCount) {
// //         running = true;
// //
// //         for (size_t i = 0; i < taskCount; ++i) {
// //             threadPool.enqueueTask([this]() {
// //                 auto client = factory.createClientModel(); // Crée un client
// //                 clientGroup.addClient(client);             // Ajoute le client au groupe
// //             });
// //         }
// //     }
// //
// //     void stop() {
// //         running = false;
// //     }
// // };
//
// // Exemple d'utilisation
// int main() {
//     ThreadPool pool(4); // Crée un pool de threads avec 4 threads
//     ClientGroupFactory factory;
//     ClientGroup clientGroup;
//
//     TaskManager taskManager(factory, clientGroup, pool);
//
//     size_t numberOfTasks = 10; // Nombre de clients à créer et traiter
//     taskManager.start(numberOfTasks);
//
//     // Laisser les threads terminer leurs tâches
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//
//     taskManager.stop();
//
//     return 0;
// }
