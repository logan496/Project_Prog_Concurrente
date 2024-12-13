//
// Created by wolverine on 12/2/24.
//

#ifndef BUTLE_H
#define BUTLE_H
#include <vector>
#include "Table.h"
#include "ClientModel.h"
#include "../Models/CommonClass/classDeclaration/MotionLessModel.h"
#include "../Models/DinningRoom/classDeclaration/DinningRoom.h"
#include "../manageConfig/dataShared/ShareData.h"
using namespace std;

/**
 * @class Butler
 *
 * the class of the butler (he is supposed to welcome the client at thier
 * entry)
 */
class Butler : public MotionlessElementModel {
public:
    /**
     * @brief Constructor of the class Butler
     *
     * @param abscice the actual x of the butler
     * @param ordinate the actual y of the butler
     * @param client_n_umber the number of client in a group
     * @param dinning_room an instance of the class DinningRoom
     * @param mutex
     * @param cv
     * @param sharedClientGroupList the actual list of client group shared with ClientGroup.
     */

    Butler(int abscice, int ordinate, int client_n_umber,
           DinningRoom &dinning_room, ShareData &sharedData)
        : MotionlessElementModel(abscice, ordinate),
          clientNUmber(client_n_umber),
          dinningRoom(dinning_room),
          data(sharedData) {
    }




    /**
     * @brief to assign a table to a client
     */
    Table *assignTable() const;

    /**
     * @brief to notify a headwaiter tha he has to take a client
     * to his table
     *
     * @param table
     * @param client
     */
    void notifyHeadWaiter(Table table, ClientModel client);

    std::vector<ClientModel> waitForGroupOfClient() const;

    // void update(const std::unordered_map<std::string, std::any> &data) override;

private:
    mutable int clientNUmber;
    //vector<int> priorityTable;
    DinningRoom &dinningRoom;
    vector<ClientModel> clientListGroup;
    ShareData &data;
    // mutex &mutex_;
    // condition_variable &cv;
    // vector<Table> emptyTable;
};
#endif //BUTLE_H
