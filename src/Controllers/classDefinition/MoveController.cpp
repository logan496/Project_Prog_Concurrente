#include "../classDeclaration/MoveController.h"
//
// Created by wolverine on 12/2/24.
//

MoveController::MoveController(MobileElementView* view, MobilityModel* mobilityModel)
    : view(view), mobilityModel(mobilityModel) {
    if (!mobilityModel || !view) {
        std::cout << "Error: Null pointer passed to MoveController!" << std::endl;
        return;
    }
    setViewElement();
    mobilityModel->subscribe(view);

}
void MoveController::setViewElement() {
    view = new MobileElementView(nullptr,mobilityModel->getAbscice(), mobilityModel->getOrdered());
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


