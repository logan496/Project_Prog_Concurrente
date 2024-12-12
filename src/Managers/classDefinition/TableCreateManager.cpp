//
// Created by wolverine on 12/10/24.
//
#include "../Managers/classDeclaration/TableCreateManager.h"

void TableCreateManager::start(const size_t taskcout) {
    isRunning = true;

    for (size_t i = 0; i <= taskcout; i++) {
        threadPool.enqueue([this]() {
            lock_guard<mutex> guard (lock);
            auto const table = tableFactory.createFixedTable();
            dinningRoom.setTableList(table);
        });
    }
}
