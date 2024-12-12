//
// Created by wolverine on 12/7/24.
//

#include "../classDeclaration/ClientGroupFactory.h"

#include <random>


ClientGroupFactory::ClientGroupFactory()  {
}

ClientGroupFactory::~ClientGroupFactory() = default;

shared_ptr<ClientModel> ClientGroupFactory::createClientModel() {
    clientIdCounter++;
    const std::string random_client_type = chooseClientType();
    int clientWaitTime = setClientWaitTime(random_client_type);
    cout << "client créer" << endl;
    return std::make_shared<ClientModel>(random_client_type, clientIdCounter, false, clientWaitTime, false, false,
                                         false);
}

std::string ClientGroupFactory::chooseClientType() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size(clientType) - 1);
    return clientType[dis(gen)]; // have to check if this works
}

int ClientGroupFactory::setClientWaitTime(const std::string &client_type_) const {
    auto envVars = EnvReader::readEnv(
        "/home/wolverine/CLionProjects/Projet_Programmation_Syteme/Project_Prog_Concurrente/src/.env");
    try {
        if (client_type_ == clientType[0])
            return std::stoi(envVars["TIME_WAIT_COOL_CLIENT"]);

        return std::stoi(envVars["TIME_WAIT_HURRY_CLIENT"]);
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: invalid intefer value for client_type :" << e.what() << std::endl;
        return std::stoi(envVars["TIME_WAIT_DEFAUL"]);
    }

}
