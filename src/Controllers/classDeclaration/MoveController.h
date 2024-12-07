//
// Created by wolverine on 12/2/24.
//

#ifndef MOVECONTROLLER_H
#define MOVECONTROLLER_H

#include <iostream>
// #include "../../Models/DinningRoom/classDeclaration/headWaiter.h"
// #include "../../Models/KitchenClass//classDeclaration/RestaurantDiver.h"
// #include "../../Models/DinningRoom/classDeclaration/Server.h"
// #include "../../Models/DinningRoom/classDeclaration/ClientModel.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include "../View/DinningRoom/ClassDeclaration/MobileElementView.h"
using namespace std;
class MoveController {
public:
    MoveController(MobileElementView* view, MobilityModel* mobilityModel);
    // void moveServe(Server server);
    // void moveHeadWaiter(HeadWaiter headWaiter);
    // void moveRestaurantDiver(RestaurantDiver restaurantDiver);
    // void moveClient(ClientModel client_model);
    // TODO: add the rest of the move method

    void moveElement(int deltaX, int deltaY);
private:
    MobileElementView *view;
    MobilityModel *mobilityModel;
};
#endif //MOVECONTROLLER_H
