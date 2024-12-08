//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H
#include <iostream>
#include <vector>
#include "CommonClass/classDeclaration/Recipe.h"
#include "CommonClass/classDeclaration/MobilityModel.h"
#include "CommonClass/classDeclaration/Order.h"
using namespace std;

/**
 * @class ClientModel
 * @brief management of the different instance of the client
 *
 * the clientModel class is used to create the different instance of the client,
 * they are the one with the different methods of the client
 */
class ClientModel {
public:
    /**
     *@brief constructor of the Client class
     *
     * @param abscice the x position of the client he walks
     * @param intercept the y position of the client when he walks
     * @param type the type of client (hurry, ...)
     * @param id the unique identifier of the client
     * @param has_odered to know if the client has ordered something
     * @param order_time_left the time allowed to the client to make a choice on the card
     * @param has_ordered_entree
     * @param has_ordered_main_course
     * @param has_ordered_dessert
     */
    ClientModel(double abscice, double intercept, const string &type, int id, bool has_odered,
                int order_time_left, bool has_ordered_entree, bool has_ordered_main_course, bool has_ordered_dessert)
        : type(type),
          id(id),
          hasOdered(has_odered),
          orderTimeLeft(order_time_left),
          hasOrderedEntree(has_ordered_entree),
          hasOrderedMainCourse(has_ordered_main_course),
          hasOrderedDessert(has_ordered_dessert) {
    }

    /**
     * @brief this function is use for the client to make a choice
     *
     * @param recipes
     */

    void makeChoice(vector<Recipe> &recipes);

    /**
     * @brief change the hasOrdered state
     */
    void toogleHasOrdered();

    void toogleHasOrderedMainCourse();

    void toogleHasOrderedDessert();

    void toogleHasOrderedEntree();

    /**
     * @brief client method eat
     * @param order
     */
    void eat(vector<Order> &order);

private:
    string type;
    int id;
    bool hasOdered;
    int orderTimeLeft; /** < the time left to the user to order. */
    bool hasOrderedEntree;
    bool hasOrderedMainCourse;
    bool hasOrderedDessert;
    vector<Recipe> choices; /** <contain the different choice of the client. */
};


#endif //CLIENTMODEL_H
