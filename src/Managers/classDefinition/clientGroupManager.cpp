//
// Created by wolverine on 12/8/24.
//

#include "../Managers/classDeclaration/clientGroupManager.h"

void ClientGroupManager::start(const size_t taskcout) {
    isRunning = true;

    for(size_t i = 0; i < taskcout; i++) {
        threadPool.enqueue([this] () {
            lock_guard<mutex> mutex(lock);
            const auto client = clientGroupFactory.createClientModel();
            clientGroupCreator.addClientGroup(client, clientGroupCreator.returnRandomClientNumber());
        });
    }
}

