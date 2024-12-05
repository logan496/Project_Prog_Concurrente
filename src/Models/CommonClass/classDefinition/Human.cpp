//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Human.h"

double Human::getX() const {
    return abscice;
}

double Human::getY() const {
    return intercept;
}

void Human::move(double newX, double newY, bool isRelative) {
    if(isRelative) {
        abscice += newX;
        intercept += newY;
    } else {
        abscice = newX;
        intercept = newY;
    }
}
