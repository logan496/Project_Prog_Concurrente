//
// Created by wolverine on 12/4/24.
//

#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H
#include "../Models/DinningRoom/classDeclaration/Server.h"
#include "../View/DinningRoom/ClassDeclaration/ServerView.h"
#include  <QObject>
class ServerController : QObject {
public:
    ServerController(ServerView &server_view, Server &server,QObject *parent = nullptr)
        : QObject(parent), server_view(server_view), server(server) {
    };

    ServerController();
    ~ServerController();

    void onChangeModel(int y, int x);

    void initializeView();
private:
    ServerView &server_view;
    Server &server;
    // à noter que ça c'est juste pour le test

};
#endif //SERVERCONTROLLER_H
