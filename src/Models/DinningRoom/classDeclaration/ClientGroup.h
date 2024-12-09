//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTGROUPCREATOR_H
#define CLIENTGROUPCREATOR_H
#include <vector>
#include "ClientModel.h"
// #include "mutex"

using namespace std;

/**
 * @class ClientGroupCreator
 *
 * @brief the generations of clients group
 */
class ClientGroupCreator {
public:
    ClientGroupCreator(){};

    /**
     * @brief to create group of client if they are alone no group is needed
     * @param client_group this list contains the different clients object
     * @param clientNumber
     */
    void addClientGroup(const std::shared_ptr<ClientModel> &client_group, const int clientNumber) {
        clientGroups.push_back(*client_group);
        if(i == clientNumber) {
            GroupsLists.push_back(clientGroups);
            cout << "groupe ajouter" << endl;
        }else {
            i++;
            cout << "incrémentation" << endl;
            cout << i << endl;
        }
    }

    /**
     * @brief returns the number of client of a group
     * @return  @var clientNumber the number of client of the actual group
     */
    int returnRandomClientNumber() const {
        srand(time(0));
        const int clientNumber = rand()% 10 + 1;
        return clientNumber;
    };

private:
    vector<ClientModel> clientGroups;
    vector<vector<ClientModel>> GroupsLists;
    int i = 0;
};
#endif //CLIENTGROUPCREATOR_H
