//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Server.h"

Server::Server() {

}


void Server::help() {
    // TODO: add a method to manage this
}

void Server::move(int deltaX, int deltaY) {
    MobileElementView::move(deltaX, deltaY);
    notify({{"x", abscice}, {"y", intercept}});
}

// void Server::move(double newX, double newY, bool isRelative) {
//     Human::move(newX, newY, isRelative);
// }

// void Server::dropDirtyDishes() {
//     // TODO: add a method to drop it
// }

// void Server::serveClient(vector<UstensilModel> ustensilList, Table &table, Order &order) {
//     // TODO: add few instructions to manage it
// }
//
// void Server::clearTable(const UstensilModel &dish) {
//     dirtyDishesCollected.push_back(dish);
//
//     // TODO: add few instructions to manage it
// }

void Server::getReadyOrder() {
    // TODO: add few instructions to manage it
}




