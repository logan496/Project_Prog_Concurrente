//
// Created by wolverine on 12/2/24.
//

#ifndef HEADWAITER_H
#define HEADWAITER_H
//#include "./CommonClass/classDeclaration/Order.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include "Table.h"
#include "ClientModel.h"
#include <queue>
/**
 * @class HeadWaiter
 *
 * @brief the guys who lead the client to his table
 */
class HeadWaiter : public MobilityModel{
    //queue<Order> orderQueue;
public:
    HeadWaiter(QObject *parent, int abscice, int ordered
        )
        : MobilityModel(parent, abscice, ordered),
          //actualClientList(actual_client_list),
          actualTable(nullptr),
          isBusy(false) {
    }

    /**
     * @brief the function to lead the clients to their table
     *
     * @param table
     * @param clients
     */
    void leadClients();

    void setActualTable(const Table *table);
    /**
     * @brief the function to take order and pass it to the chief
     */
    void passOrdersTochief();
private:
    vector<ClientModel> actualClientList;
    const Table *actualTable;
    std::atomic<bool> isBusy;

};
#endif //HEADWAITER_H
