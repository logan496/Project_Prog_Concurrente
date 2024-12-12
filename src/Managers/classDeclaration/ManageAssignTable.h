//
// Created by wolverine on 12/11/24.
//

#ifndef MANAGEASSIGNTABLE_H
#define MANAGEASSIGNTABLE_H

#include "../threadPool/ThreadPool.h"
#include "../Models/DinningRoom/classDeclaration/Butler.h"

#include <mutex>

/**
 * @class ManageAssignTable
 *
 * @brief to link the butler and the headwaiter so that the butler will pass the
 * client group to lead and the table of that group to the headwaiter.
 */
class ManageAssignTable {
public:
    ManageAssignTable(Butler &butler, ThreadPool &thread_pool)
        : butler_(butler),
          threadPool(thread_pool),
          isRunning(false)
    {
    }

    /**
     * @brief this class is used to launch a thread to run the assign table method on it
     * @param taskcout
     */
    void start(size_t taskcout);



    void stop();

private:
    Butler &butler_;
    ThreadPool &threadPool;
    std::atomic<bool> isRunning;
    mutex lock;
};
#endif //MANAGEASSIGNTABLE_H
