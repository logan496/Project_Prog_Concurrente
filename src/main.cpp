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
#include "../manageConfig/dataShared/ShareData.h"


int main(int argc, char **argv) {
    //QApplication app(argc, argv);
    ShareData sharedData;
    ThreadPool pool;
    DinningRoom dinning_room;
    TableFactory table_factory;
    ClientGroupFactory client_group_factory;
    // Création des objets nécessaires
    // MobilityModel mobilityModel;
    // MobileElementView view;
    TableCreateManager table_manage(table_factory, pool, dinning_room);
    size_t taskcout = table_factory.getNumberOfTask();
    table_manage.start(taskcout);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    table_manage.stop();
    // Création et liaison du contrôleur
    // MoveController moveController(&view, &mobilityModel);
    // moveController.moveElement(800, 800);

    // Création de la fenêtre principale
    // MainWindow main_window(&view, &dinning_room);


    // Lancement de l'application
    //app.exec();
    ClientGroupCreator client_group_creator(sharedData);
    ClientGroupManager manager_client(client_group_factory, client_group_creator, pool);
    size_t count = client_group_creator.returnRandomClientNumber();

    Butler butler(20, 20, client_group_creator.returnRandomClientNumber(), dinning_room, sharedData);

    ManageAssignTable manage_assign_table(butler, pool);

    manager_client.start(count);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    manage_assign_table.start(count);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    manage_assign_table.stop();
    manager_client.stop();


    return 0;
}
