//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTGROUPCREATOR_H
#define CLIENTGROUPCREATOR_H
#include <vector>
#include "ClientModel.h"

using namespace std;

/**
 * @class ClientGroupCreator
 *
 * @brief the generations of clients group
 */
class ClientGroupCreator {
public:
    /**
     * @brief the clientGroup class constructor
     *
     * @param client_groups
     * @param client_number
     */
    ClientGroupCreator(const vector<ClientModel> &client_groups, int client_number)
        : clientGroups(client_groups),
          clientNumber(client_number) {
    }

    /**
     * @brief to create group of client if they are alone no group is needed
     * @param client_group this list contains the different clients object
     */
    void addClientGroup(const ClientModel &client_group) {clientGroups.push_back(client_group);}

private:
    vector<ClientModel> clientGroups;
    int clientNumber; /** the number of clients in the group */
};
#endif //CLIENTGROUPCREATOR_H
