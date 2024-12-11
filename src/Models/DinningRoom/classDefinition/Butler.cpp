//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Butler.h"

Table* Butler::assignTable(const int clientNumber) const {
    Table* bestFitTable = nullptr;
    bool tableFound = false;

    for(Table &emptyTable : dinningRoom.getEmptyTableList()) {
        if(emptyTable.getCapacity() == clientNumber) {
            return &emptyTable;
        }
        else if (emptyTable.getCapacity() >= clientNumber) {
            if (!tableFound || emptyTable.getCapacity() < bestFitTable->getCapacity()) {
                bestFitTable = &emptyTable;
            }
        }
    }

    if(tableFound) {
        return bestFitTable;
    }
    throw std::runtime_error("No suitable table available.");
    // add a return statement here
}

void Butler::notifyHeadWaiter(Table table, ClientModel client) {
    /* TODO: add a condition variable for notify the headwaiter
     * add few instructions to also pass the client list/group
     */
}
