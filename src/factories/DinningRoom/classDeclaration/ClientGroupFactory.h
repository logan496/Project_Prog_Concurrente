#ifndef CLIENTGROUPFACTORY_H
#define CLIENTGROUPFACTORY_H
#include <queue>
#include <mutex>
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

    shared_ptr<ClientModel> createClientModel();

    std::string chooseClientType() const;

    int setClientWaitTime(const std::string &client_type_) const;

private:
    int clientIdCounter = 0;
    condition_variable client_created;
    mutex client_created_mutex;
    std::queue<ClientModel> client_waiting_for_group;


    std::vector<string> clientType{"cool_client", "hurry_client"};
    std::vector<Recipe> client_choices;
};

#endif //CLIENTGROUPFACTORY_H
