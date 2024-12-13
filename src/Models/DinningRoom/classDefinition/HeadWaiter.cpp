//
// Created by wolverine on 12/2/24.
//

#include "../classDeclaration/headWaiter.h"
void HeadWaiter::passOrdersTochief() {
    // TODO: add few instructions to manage it
}

void HeadWaiter::leadClients() {
    isBusy = true;
    int final_x = actualTable->getAbscice();
    int final_y = actualTable->getOrdinate();
    // final_coord.first = actualTable.getAbscice();
    // final_coord.second = actualTable.getOrdinate();
    move(final_x, final_y);


    // TODO: add few instructions to manage it
}

void HeadWaiter::setActualTable(const Table *table) {
    actualTable = table;
    if (isBusy) {
        return;
    }
    leadClients();
}

