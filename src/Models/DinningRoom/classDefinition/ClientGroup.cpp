//
// Created by wolverine on 12/11/24.
//
#include "../Models//DinningRoom/classDeclaration/ClientGroup.h"

void ClientGroupCreator::addClientGroup(const std::shared_ptr<ClientModel> &client_group, const int clientNumber) {
    // clientGroups.push_back(*client_group);
    // if (i == clientNumber) {
    //     cout << "ici ça marche" << endl;
    //     sharedClientGroups.push_back(clientGroups);
    //     notify({{"actual_group", sharedClientGroups}});
    //     clientGroups.clear();
    //     cout << "groupe ajouter" << endl;
    // }else {
    //     i++;
    //     cout << "groupe num: " << i  << endl;
    // }
    clientGroups.push_back(*client_group);
    if (i == clientNumber) {
        unique_lock<mutex> lock(data.list_mutex);
        data.shared_list.push_back(clientGroups);
        data.list_condition.notify_one();
        cout << "modification lancée" << endl;
    }else {
        i++;
    }
}

int ClientGroupCreator::returnRandomClientNumber() const {
    srand(time(nullptr));
    const int clientNumber = rand() % 10 + 1;
    return clientNumber;
}



