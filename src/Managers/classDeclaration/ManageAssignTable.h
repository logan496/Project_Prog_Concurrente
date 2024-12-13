//
// Created by wolverine on 12/11/24.
//

#ifndef MANAGEASSIGNTABLE_H
#define MANAGEASSIGNTABLE_H

#include "../threadPool/ThreadPool.h"
#include "../Models/DinningRoom/classDeclaration/Butler.h"
#include "../Models/DinningRoom/classDeclaration/headWaiter.h"

#include <mutex>

/**
 * @class ManageAssignTable
 *
 * @brief to link the butler and the headwaiter so that the butler will pass the
 * client group to lead and the table of that group to the headwaiter.
 */
class ManageAssignTable {
public:
    /**
     * @brief the constructor of the ManageAssignTable class
     * @param butler
     * @param thread_pool
     * @param head_waiter
     */
    ManageAssignTable(Butler &butler, ThreadPool &thread_pool, HeadWaiter &head_waiter)
        : butler_(butler), head_waiter_(head_waiter),
          threadPool(thread_pool),
          isRunning(false) {
    }

    /**
     * @brief this class is used to launch a thread to run the assign table method on it
     * @param taskcout
     */
    void start(size_t taskcout);


    void stop();

private:
    Butler &butler_;
    HeadWaiter &head_waiter_;
    ThreadPool &threadPool;
    std::atomic<bool> isRunning;
    mutex lock;
};
#endif //MANAGEASSIGNTABLE_H
