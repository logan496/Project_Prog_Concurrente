#include "../classDeclaration/MoveController.h"
//
// Created by wolverine on 12/2/24.
//

MoveController::MoveController(MobileElementView* view, MobilityModel* mobilityModel)
    : mobilityModel(mobilityModel), view(view) {
    if (!mobilityModel || !view) {
        std::cout << "Error: Null pointer passed to MoveController!" << std::endl;
        return;
    }
    mobilityModel->subscribe(view);
}

void MoveController::moveElement(int deltaX, int deltaY) {
    mobilityModel->move(deltaX, deltaY);
}


// void MoveController::moveServe(Server server) {
//     // TODO: add few instructions to manage it
// }
// void MoveController::moveHeadWaiter(HeadWaiter headWaiter) {
//     // TODO: add few instructions to manage it
// }
// void MoveController::moveRestaurantDiver(RestaurantDiver restaurantDiver) {
//     // TODO: add few instructions to manage it
// }


