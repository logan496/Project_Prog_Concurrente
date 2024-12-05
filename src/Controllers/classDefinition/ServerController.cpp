#include "classDeclaration/ServerController.h"
//
// Created by wolverine on 12/4/24.
//

ServerController::ServerController(ServerView &server_view, Server &server, QObject *parent = nullptr)
    : QObject(parent), server_view(server_view), server(server) {
    QObject::connect()
}


void ServerController::onChangeModel(int y, int x) {

}
