//
// Created by wolverine on 12/2/24.
//

#ifndef MOVECONTROLLER_H
#define MOVECONTROLLER_H
#include "../../Models/DinningRoom/classDeclaration/headWaiter.h"
#include "../../Models/KitchenClass//classDeclaration/RestaurantDiver.h"
#include "../../Models/DinningRoom/classDeclaration/Server.h"
#include "../../Models/DinningRoom/classDeclaration/ClientModel.h"
using namespace std;
class MoveController {
public:
    void moveServe(Server server);
    void moveHeadWaiter(HeadWaiter headWaiter);
    void moveRestaurantDiver(RestaurantDiver restaurantDiver);
    void moveClient(ClientModel client_model);
    // TODO: add the rest of the move method
};
#endif //MOVECONTROLLER_H
