//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Table.h"

void Table::releaseClients() {
    // TODO: add a method to move the clients after the have finished eating
}

void Table::toogleOccuped() {
    this->occuped = !this->occuped;
}

void Table::addClientsToTable(vector<ClientModel> clients) {
    // TODO: add a method for adding client on the table
    this->clientList = clients;
}





