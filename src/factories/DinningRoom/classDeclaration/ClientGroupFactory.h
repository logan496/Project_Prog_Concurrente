#ifndef CLIENTGROUPFACTORY_H
#define CLIENTGROUPFACTORY_H
#include <queue>
#include <condition_variable>
#include <memory>
#include <vector>
#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"
#include "../Models/DinningRoom/classDeclaration/ClientModel.h"
#include "../Models/CommonClass/classDeclaration/Recipe.h"
#include "../manageConfig/readEnv/EnvReader.h"

/**
 * @class ClientGroupFactory
 *
 * @brief This class is in charge of the creation of clients for the restaurant
 */
class ClientGroupFactory {
public:
    ClientGroupFactory();

    ~ClientGroupFactory();

    /**
     * @brief this function is use to randomly create clients
     * @return an instance of the class clientModel
     */
    shared_ptr<ClientModel> createClientModel();

    std::string chooseClientType() const;

    /**
     *
     * @param client_type_ the type of the client
     * @return time wait time max of the client in the .env file
     */
    int setClientWaitTime(const std::string &client_type_) const;

private:
    int clientIdCounter = 0;
    condition_variable client_created;
    std::queue<ClientModel> client_waiting_for_group;


    std::vector<string> clientType{"cool_client", "hurry_client"};
    std::vector<Recipe> client_choices;
};

#endif //CLIENTGROUPFACTORY_H
