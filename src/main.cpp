#include <QApplication>
#include "MainView.h"
#include "../Controllers/classDeclaration/MoveController.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include "../View/commonClass/ClassDeclaration/MobileElementView.h"
#include "../Managers/classDeclaration/clientGroupManager.h"
#include "../threadPool/ThreadPool.h"
#include "../factories/DinningRoom/classDeclaration/ClientGroupFactory.h"
#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"
#include "../Managers/classDeclaration/TableCreateManager.h"
#include "../factories/DinningRoom/classDeclaration/TableFactory.h"
#include "../Models/DinningRoom/classDeclaration/Table.h"
#include "../Models/DinningRoom/classDeclaration/DinningRoom.h"
#include "../Managers/classDeclaration/ManageAssignTable.h"
#include <mutex>
#include <condition_variable>

int main(int argc, char **argv) {
    // QApplication app(argc, argv);
    //
    // // Création des objets nécessaires
    // MobilityModel mobilityModel;
    // MobileElementView view;
    // // Création et liaison du contrôleur
    // MoveController moveController(&view, &mobilityModel);
    // moveController.moveElement(200, 200);
    //
    // // Création de la fenêtre principale
    // MainWindow main_window(&view);
    //
    //
    // // Lancement de l'application
    // app.exec();

    // mutex mutex_lock;
    // condition_variable cv;
    vector<vector<ClientModel> > sharedClientGroups;
    ThreadPool pool;
    ClientGroupFactory factory;
    ClientGroupCreator client_group_creator(sharedClientGroups);
    TableFactory table_factory;
    DinningRoom dinning_room;
    Butler *butler;
    client_group_creator.subscribe(butler);

    // Butler butler_(20, 20, client_group_creator.returnRandomClientNumber(), dinning_room, mutex_lock, cv,
    //                sharedClientGroups);
    TableCreateManager table_manage(table_factory, pool, dinning_room);

    ClientGroupManager manager(factory, client_group_creator, pool);

    // ManageAssignTable manage_assign_table(butler_, pool);

    size_t numberOfTasks = client_group_creator.returnRandomClientNumber();
    size_t taskcout = table_factory.getNumberOfTask();

    // manage_assign_table.start(taskcout);
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));

    manager.start(numberOfTasks);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    table_manage.start(taskcout);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));



    table_manage.stop();
    // manage_assign_table.stop();
    manager.stop();


    return 0;
}
