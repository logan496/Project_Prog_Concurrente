//
// Created by wolverine on 12/7/24.
//

#include "../classDeclaration/ClientGroupFactory.h"

ClientGroupFactory::ClientGroupFactory() {

}

ClientGroupFactory::~ClientGroupFactory() = default;

std::unique_ptr<ClientModel> ClientGroupFactory::createClientModel() {
    clientIdCounter++;
    const std::string random_client_type = chooseClientType();
    int clientWaitTime = setClientWaitTime(random_client_type);
}

std::string ClientGroupFactory::chooseClientType() const {
    srand(static_cast<unsigned int>(time(nullptr)));

    int Size = std::size(clientType);

    int Random = std::rand() % Size;
    return clientType[Random]; // have to check if this works
}

int ClientGroupFactory::setClientWaitTime(std::string client_type_) {
    dotenv::env.load_dotenv(dotenv_path);
    if(client_type_ == clientType[0]) {
        
    }

}
