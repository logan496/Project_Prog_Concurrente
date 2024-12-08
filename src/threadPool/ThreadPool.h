//
// Created by wolverine on 12/7/24.
//

#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <iostream>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>
using namespace std;

/**
 * @class ThreadPool
 *
 * @brief this class represent all the threads that are going to be use
 * in this project
 */
class ThreadPool {
public:
    /**
     * @brief the constructor of the thread pool class
     * @param num_threads the numbers of threads actually active
     */
    explicit ThreadPool(size_t num_threads
            = thread::hardware_concurrency());

    ~ThreadPool();

    /**
     * @brief this function enqueue the different task for the execution with threads
     * @param task the task that the thread had to do.
     */
    void enqueue(std::function<void()> task);

private:
    vector<thread> threads;
    queue<std::function<void()> > tasks_;
    mutex queue_mutex;
    condition_variable cv_;
    bool stop_ = false;
};
#endif //THREADPOOL_H
