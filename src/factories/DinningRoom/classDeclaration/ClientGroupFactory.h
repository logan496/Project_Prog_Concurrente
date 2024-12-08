//
// Created by wolverine on 12/7/24.
//

#ifndef CLIENTGROUPFACTORY_H
#define CLIENTGROUPFACTORY_H
#include <queue>
#include <mutex>
#include <condition_variable>

#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"
#include "../Models/DinningRoom/classDeclaration/ClientModel.h"
#include "../Models/CommonClass/classDeclaration/Recipe.h"


/**
 * @class ClientGroupFactory
 *
 * @brief this class is in charge of the creation of clients for the restaurant
 */
class ClientGroupFactory {
public:
    ClientGroupFactory();

    ~ClientGroupFactory();

    std::unique_ptr<ClientModel> createClientModel();

    std::string chooseClientType() const;

    int setClientWaitTime(std::string client_type_);





private:
    int clientIdCounter = 0;
    std::string clientType[] = {"cool_client", "hurry_client"};
    bool has_ordered_entree = false;
    bool has_ordered_main_course = false;
    bool has_ordered_dessert = false;
    vector<Recipe> client_choices[];
    condition_variable client_created;
    mutex client_created_mutex;
    queue<ClientModel> client_waiting_for_group;

};
#endif //CLIENTGROUPFACTORY_H
