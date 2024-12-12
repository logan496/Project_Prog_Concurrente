//
// Created by wolverine on 12/2/24.
//

#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>

#include "../Models/CommonClass/classDeclaration/MotionLessModel.h"
#include "ClientModel.h"

/**
 * @class Table
 *
 * @brief for the management of all the table of
 * the dinning room
 */
class Table : public MotionlessElementModel {
public:
    /**
     * @brief Constructor of the class Table
     *
     * @param capacity the number of client the table can take
     * @param occuped is the table has client on it or not
     * @param client_list the list of client on the table
     * @param bread_cart_needed the number of bread cart needed on the table by the client
     */


    Table(int abscice, int ordinate, int capacity, bool occuped,
          const vector<ClientModel> &client_list, int bread_cart_needed)
        : MotionlessElementModel(abscice, ordinate),
          capacity(capacity),
          occuped(occuped),
          clientList(client_list),
          breadCartNeeded(bread_cart_needed) {
    }

    /**
     * @brief default constructor of the class table
     */


    /**
     * @brief a function to add clients on the table
     *
     * @param clients
     */
    void addClientsToTable(vector<ClientModel> clients);

    /**
     * @brief to move the client when they have finished eating
     */
    void releaseClients();

    void toogleOccuped();

    bool returnOccupedState() const { return occuped; }

    int getCapacity() const { return this->capacity; }

private:
    int capacity;
    bool occuped;
    vector<ClientModel> clientList;
    int breadCartNeeded;
};
#endif //TABLE_H
