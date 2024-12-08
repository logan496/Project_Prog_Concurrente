//
// Created by wolverine on 12/8/24.
//

#include "../Managers/classDeclaration/clientGroupManager.h"

void ClientGroupManager::start(size_t taskcout) {
    isRunning = true;

    for(size_t i = 0; i < taskcout; i++) {
        threadPool.enqueue([this] () {
            auto client = clientGroupFactory.createClientModel();
            clientGroupCreator.addClientGroup(client);
        });
    }
}

