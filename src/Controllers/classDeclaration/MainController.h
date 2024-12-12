//
// Created by wolverine on 12/2/24.
//

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <utility>

#include "DBController.h"
#include "MotionlessElementController.h"
#include "../Managers/classDeclaration/clientGroupManager.h"
#include "../threadPool/ThreadPool.h"
#include "../factories/DinningRoom/classDeclaration/ClientGroupFactory.h"
#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"

using namespace std;

/**
 * @class MainController
 */
class MainController {
public:
    /**
     * @brief
     *
     * @param db_controller
     * @param motionless_element_controller
     */
    MainController(DBController db_controller, const MotionlessElementController &motionless_element_controller)
        : dbController(std::move(db_controller)),
          motionlessElementController(motionless_element_controller),
          manager_(factory_, client_group_creator_, pool),
          numberOfTasks(client_group_creator_.returnRandomClientNumber()) {
    }

private:
    DBController dbController;
    MotionlessElementController motionlessElementController;
    ThreadPool pool;
    ClientGroupCreator client_group_creator_;
    ClientGroupFactory factory_;

    ClientGroupManager manager_;

    size_t numberOfTasks;
    // TODO: add the rest and modify where necessary
};
#endif //MAINCONTROLLER_H
