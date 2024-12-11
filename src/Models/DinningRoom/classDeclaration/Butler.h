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
using namespace std;

/**
 * @class Butler
 *
 * the class of the butler (he is supposed to welcome the client at thier
 * entry)
 */
class Butler : MotionlessElementModel {
public:
    /**
     * @brief Constructor of the class Butler
     *
     * @param abscice
     * @param ordinate
     * @param client_n_umber
     * @param priority_table
     * @param dinning_room
     */

    Butler(int abscice, int ordinate, int client_n_umber, const vector<int> &priority_table,
           DinningRoom &dinning_room)
     : MotionlessElementModel(abscice, ordinate),
       clientNUmber(client_n_umber),
       priorityTable(priority_table),
       dinningRoom(dinning_room) {
    }

    /**
     * @brief to assign a table to a client
     */
    Table* assignTable(int clientNumber) const;

    /**
     * @brief to notify a headwaiter tha he has to take a client
     * to his table
     *
     * @param table
     * @param client
     */
    void notifyHeadWaiter(Table table, ClientModel client);

private:
    int clientNUmber;
    vector<int> priorityTable;
    DinningRoom &dinningRoom;
    // vector<Table> emptyTable;
};
#endif //BUTLE_H
