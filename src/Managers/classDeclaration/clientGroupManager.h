//
// Created by wolverine on 12/8/24.
//

#ifndef CLIENTGROUPMANAGER_H
#define CLIENTGROUPMANAGER_H

#include "../factories/DinningRoom/classDeclaration/ClientGroupFactory.h"
#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"
#include "../threadPool/ThreadPool.h"

/**
 * @class ClientGroupManager
 *
 * @brief this class has to link factorycliengroup, clientgroup and
 * threadpool
 */
class ClientGroupManager {
public:
    ClientGroupManager(ClientGroupFactory &client_group_factory, ClientGroupCreator &client_group_creator,
        ThreadPool &thread_pool)
        : clientGroupFactory(client_group_factory),
          clientGroupCreator(client_group_creator),
          threadPool(thread_pool),
          isRunning(false) {}

    void start(size_t taskcout);
    void stop() { isRunning = false; }

private:
    ClientGroupFactory &clientGroupFactory;
    ClientGroupCreator clientGroupCreator;
    ThreadPool &threadPool;
    std::atomic<bool> isRunning;

public:

};


#endif //CLIENTGROUPMANAGER_H
