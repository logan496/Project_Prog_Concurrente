//
// Created by wolverine on 12/11/24.
//
#include "../Managers/classDeclaration/ManageAssignTable.h"

void ManageAssignTable::start(size_t taskcout) {
    isRunning = true;

    // for (size_t i = 0; i < taskcout; i++) {
    //     threadPool.enqueue([this]() {
    //         const auto group = butler_.waitForGroupOfClient();
    //         cout << "goupe de client : " << group.size() << endl;
    //         // TODO: call the method lead client of the headwaiter
    //     });
    // }
    // threadPool.enqueue([this]() {
    //     cout << "this" << endl;
    //     const auto clientGroupToLead = butler_.waitForGroupOfClient();
    //     cout << "in function" << endl;
    //     const auto tableAssigned = butler_.assignTable();
    //     cout << "table x : " << tableAssigned->getCapacity() << endl;
    //
    // });
    threadPool.enqueue([this]() {
       const auto group = butler_.waitForGroupOfClient();
        cout << "Groupe de client : " << group.size() << endl;
    });
}

void ManageAssignTable::stop() {
    isRunning = false;
}
