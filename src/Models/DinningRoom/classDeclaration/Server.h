//
// Created by wolverine on 12/2/24.
//

#ifndef SERVER_H
#define SERVER_H
// #include "../Models/CommonClass/classDeclaration/UstensilModel.h"
// #include "Table.h"
// #include "../Models/CommonClass/classDeclaration/Order.h"
// #include "../Models/KitchenClass/classDeclaration/DirtyDishesStorage.h"
#include <vector>
#include "../Models/CommonClass/classDeclaration/MobileElement.h"
#include "../Observer/Observable.h"
/**
 * @class Server
 *
 * @brief the class that manage the server
 */
class Server : public MobileElementView{
public:
    /**
     * @brief the constructor of the server class
     *
     * @param area the actual square of the server
     * @param max_ready_order
     * @param dirty_dishes_collected
     */

    // Server(int area, int max_ready_order, const vector<UstensilModel> &dirty_dishes_collected,
    //  const vector<DirtyDishesStorage> &disdisto)
    //  : area(area),
    //    maxReadyOrder(max_ready_order),
    //    dirtyDishesCollected(dirty_dishes_collected),
    //    disdisto(disdisto) {}

    Server();
    /**
     * @brief to take the ready order on the counter
     */
    void getReadyOrder();/* je pense aussi cette méthode devrait
                          * prendre des paramétres
                          * ps: on verra */

    /**
     * @brief to take all the dirty dishes on the table
     */
    //void clearTable(const UstensilModel &dish);

    /**
     * @brief the function use to serve the clients
     *
     * @param ustensilList The list of the necessary, utensil to eat the actual dishes.
     * @param table An instance of the class table where the client who  should be serve is.
     * @param order An object with the different order of the clients.
     */
    //void serveClient(vector<UstensilModel> ustensilList, Table &table, Order &order);

    /**
     * @brief to put the dirty dishes into the storage
     */
    void dropDirtyDishes();


    /**
     * @brief to help another square when he is free and the square is
     * busy
     */
    void help();/* je pense sincérement que cette fonction doit prendre
                 * des paramétres
                 * et retourner un truc */

    void move(int deltaX, int deltaY) override;


// private:
    // int area;
    // int maxReadyOrder;
    // vector<UstensilModel> dirtyDishesCollected;
    // vector<DirtyDishesStorage> disdisto;
    // TODO: add didisto (dirtyDishesStorage)

};
#endif //SERVER_H
