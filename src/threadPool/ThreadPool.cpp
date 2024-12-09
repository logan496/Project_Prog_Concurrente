//
// Created by wolverine on 12/7/24.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(const size_t num_threads) {
    for (size_t i = 0; i < num_threads; i++) {
        threads.emplace_back([this]() {
            while (true) {
                function<void()> task; {
                    unique_lock<mutex> lock(queue_mutex);

                    cv_.wait(lock, [this] {
                        return !tasks_.empty() || stop_;
                    });

                    if (stop_ && tasks_.empty()) {
                        return;
                    }

                    task = std::move(tasks_.front());
                    tasks_.pop();
                }
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() { {
        unique_lock<mutex> lock(queue_mutex);
        stop_ = true;
    }

    cv_.notify_all();

    for (auto &thread: threads) {
        thread.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task) { {
        unique_lock<mutex> lock(queue_mutex);
        tasks_.emplace(std::move(task));
    }
    cv_.notify_all();
}
