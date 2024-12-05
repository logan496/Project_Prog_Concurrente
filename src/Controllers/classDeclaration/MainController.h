//
// Created by wolverine on 12/2/24.
//

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <utility>

#include "DBController.h"
#include "MotionlessElementController.h"
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
          motionlessElementController(motionless_element_controller) {
    }

private:
    DBController dbController;
    MotionlessElementController motionlessElementController;
    // TODO: add the rest and modify where necessary
};
#endif //MAINCONTROLLER_H
