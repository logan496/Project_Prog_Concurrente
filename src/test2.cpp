//
// Created by wolverine on 12/11/24.
//
#ifndef CLIENTGROUPCREATOR_H
#define CLIENTGROUPCREATOR_H

#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "ClientModel.h"

using namespace std;

class ClientGroupCreator {
public:
    /**
     * @brief Constructeur de la classe ClientGroupCreator
     * @param mutex_mutex Mutex partagé pour la synchronisation
     * @param cv Condition de variable partagée pour la notification
     * @param sharedClientGroups Liste partagée entre ClientGroupCreator et Butler
     */
    ClientGroupCreator(mutex &mutex_mutex, condition_variable &cv, vector<vector<ClientModel>> &sharedClientGroups)
        : mutex_(mutex_mutex), cv(cv), sharedClientGroups(sharedClientGroups) {}

    /**
     * @brief Ajoute un groupe de clients dans la liste partagée
     * @param client_group Instance de ClientModel
     * @param clientNumber Nombre de clients par groupe
     */
    void addClientGroup(const std::shared_ptr<ClientModel> &client_group, const int clientNumber) {
        unique_lock<mutex> lock(mutex_);
        clientGroups.push_back(*client_group); // Ajoute un client au groupe
        if (i + 1 == clientNumber) {
            // Ajout du groupe dans la liste partagée
            sharedClientGroups.push_back(clientGroups);
            clientGroups.clear();
            i = 0;

            cv.notify_one(); // Notifie le Butler
            cout << "Groupe ajouté et notification envoyée." << endl;
        } else {
            i++;
            cout << "Incrémentation : " << i << endl;
        }
    }

private:
    vector<ClientModel> clientGroups;                 // Groupe en cours de formation
    vector<vector<ClientModel>> &sharedClientGroups; // Liste partagée des groupes de clients
    int i = 0;                                       // Compteur de clients dans le groupe actuel
    mutex &mutex_;                                   // Mutex partagé
    condition_variable &cv;                          // Condition de variable partagée
};

#endif // CLIENTGROUPCREATOR_H


#include "ClientGroupCreator.h"
#include "Butler.h"

int main() {
    mutex mtx;
    condition_variable cv;
    vector<vector<ClientModel>> sharedClientGroups;

    // Création des instances
    ClientGroupCreator groupCreator(mtx, cv, sharedClientGroups);
    DinningRoom dinningRoom;
    Butler butler(0, 0, 5, {1, 2, 3}, dinningRoom, mtx, cv, sharedClientGroups);

    // Threads : un pour ajouter des groupes, l'autre pour les traiter
    thread producer([&]() {
        auto client = make_shared<ClientModel>("Client 1");
        groupCreator.addClientGroup(client, 3);

        client = make_shared<ClientModel>("Client 2");
        groupCreator.addClientGroup(client, 3);

        client = make_shared<ClientModel>("Client 3");
        groupCreator.addClientGroup(client, 3);
    });

    thread consumer([&]() {
        butler.waitForGroupOfClient();
    });

    producer.join();
    consumer.join();

    return 0;
}
#ifndef BUTLER_H
#define BUTLER_H

#include <vector>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "Table.h"
#include "ClientModel.h"
#include "../Models/CommonClass/classDeclaration/MotionLessModel.h"
#include "../Models/DinningRoom/classDeclaration/DinningRoom.h"

using namespace std;

class Butler : MotionlessElementModel {
public:
    /**
     * @brief Constructeur de la classe Butler
     * @param abscice Coordonnée x
     * @param ordinate Coordonnée y
     * @param client_n_umber Nombre de clients à gérer
     * @param priority_table Priorité des tables
     * @param dinning_room Référence à la salle à manger
     * @param mutex Mutex partagé pour la synchronisation
     * @param cv Condition de variable partagée pour la notification
     * @param sharedClientGroups Liste partagée des groupes de clients
     */
    Butler(int abscice, int ordinate, int client_n_umber, const vector<int> &priority_table,
           DinningRoom &dinning_room, mutex &mutex, condition_variable &cv,
           vector<vector<ClientModel>> &sharedClientGroups)
        : MotionlessElementModel(abscice, ordinate),
          clientNUmber(client_n_umber),
          priorityTable(priority_table),
          dinningRoom(dinning_room),
          mutex_(mutex),
          cv(cv),
          sharedClientGroups(sharedClientGroups) {}

    /**
     * @brief Attend et récupère un groupe de clients
     */
    void waitForGroupOfClient() {
        unique_lock<mutex> lock(mutex_);
        cv.wait(lock, [this]() { return !sharedClientGroups.empty(); }); // Attend une notification

        // Récupération du groupe de clients
        auto group = sharedClientGroups.front();
        sharedClientGroups.erase(sharedClientGroups.begin());
        cout << "Butler : Groupe reçu de taille " << group.size() << endl;

        // Traitement du groupe (par exemple, assigner une table)
        for (const auto &client : group) {
            cout << "Traitement du client : " << client.getName() << endl;
        }
    }

private:
    int clientNUmber;                                    // Nombre de clients à gérer
    vector<int> priorityTable;                           // Priorité des tables
    DinningRoom &dinningRoom;                            // Référence à la salle à manger
    vector<vector<ClientModel>> &sharedClientGroups;     // Liste partagée des groupes de clients
    mutex &mutex_;                                       // Mutex partagé
    condition_variable &cv;                              // Condition de variable partagée
};

#endif // BUTLER_H
