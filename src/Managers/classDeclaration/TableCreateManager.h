//
// Created by wolverine on 12/10/24.
//

#ifndef TABLECREATEMANAGER_H
#define TABLECREATEMANAGER_H
#include <mutex>

#include "../../factories/DinningRoom/classDeclaration/TableFactory.h"
#include "../../threadPool/ThreadPool.h"

class TableCreateManager {
public:
    TableCreateManager(TableFactory &table_factory, ThreadPool &thread_pool
    )
        : tableFactory(table_factory),
          threadPool(thread_pool),
          isRunning(false) {
    }

    void start(size_t taskcout);

    void stop() { isRunning = false; };

private:
    TableFactory &tableFactory;
    ThreadPool &threadPool;
    std::atomic<bool> isRunning;
    mutex lock;
};
#endif //TABLECREATEMANAGER_H
