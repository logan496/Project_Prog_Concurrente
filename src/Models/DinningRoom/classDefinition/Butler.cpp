//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Butler.h"

Table* Butler::assignTable() const {
    // Table* bestFitTable = nullptr;
    // bool tableFound = false;
    for(Table &emptyTable : dinningRoom.getEmptyTableList()) {
        if(emptyTable.getCapacity() == clientNUmber) {
            return &emptyTable;
        }
        if (emptyTable.getCapacity() > clientNUmber) {
            return &emptyTable;
        }
    }

    throw std::runtime_error("No suitable table available.");
    // add a return statement here
}

void Butler::notifyHeadWaiter(Table table, ClientModel client) {
    /* TODO: add a condition variable for notify the headwaiter
     * add few instructions to also pass the client list/group
     */
}

// std::vector<ClientModel> Butler::waitForGroupOfClient() const {
//     // cout<< "en attente" << endl;
//     // unique_lock<mutex> lock(mutex_);
//     // cv.wait(lock, [&]() {
//     //     cout << sharedClientGroups.size() << endl;
//     //     return !sharedClientGroups.empty();
//     // });
//     // cout << "fin de l'attente" << endl;
//     // auto clientGroup = sharedClientGroups.front();
//     // sharedClientGroups.erase(sharedClientGroups.begin());
//     // clientNUmber =  clientGroup.size();
//     // cout << "Butler : Groupe reçu de taille" << clientGroup.size() << endl;
//     // return clientGroup;
//
// }

void Butler::update(const std::unordered_map<std::string, std::any> &data) {
    cout << "ici l'erreur ???" << endl;
    try {
        if (data.count("actual_group") > 0) {
            sharedClient = std::any_cast<vector<vector<ClientModel>>>(data.at("actual_group"));
            auto clientGroup = sharedClient.front();
            cout << "Butler : group received with size : " << clientGroup.size() << endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error while updating Butler list: " << e.what() << std::endl;
    }
}
