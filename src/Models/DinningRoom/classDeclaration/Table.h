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
 * @brief the class table for the management of all the table of
 * the dinning room
 */
class Table : public MotionlessElementModel{
public:
    /**
     * @brief Constructor of the class Table
     *
     * @param parent
     * @param absciceX
     * @param ordinateY
     * @param capacity
     * @param occuped
     * @param client_list
     * @param bread_cart_needed
     */
    // Table(double abscice, double intercept, int capacity, int occuped, const vector<ClientModel> &client_list,
    //       int bread_cart_needed)
    //     : abscice(abscice),
    //       intercept(intercept),
    //       capacity(capacity),
    //       occuped(occuped),
    //       clientList(client_list),
    //       breadCartNeeded(bread_cart_needed) {
    // }

    Table(QObject *parent, int absciceX, int ordinateY, int capacity, bool occuped,
     const vector<ClientModel> &client_list, int bread_cart_needed)
     : MotionlessElementModel(parent, absciceX, ordinateY),
       abscice(absciceX),
       intercept(ordinateY),
       capacity(capacity),
       occuped(occuped),
       clientList(client_list),
       breadCartNeeded(bread_cart_needed) {
    }

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

    void setAbscice(double abscice);
    void setIntercept(double intercept);
    void setOccuped(int occuped);
    void setClientList(vector<ClientModel> clientList);


private:
    double abscice;
    double intercept;
    int capacity;
    bool occuped;
    vector<ClientModel> clientList;
    int breadCartNeeded;

};
#endif //TABLE_H
