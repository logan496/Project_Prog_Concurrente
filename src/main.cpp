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

    ThreadPool pool;
    ClientGroupFactory factory;
    ClientGroupCreator client_group_creator;
    TableFactory table_factory;
    DinningRoom dinning_room(0, 0, 0, false, false, 0, 0);
    TableCreateManager table_manage(table_factory, pool, dinning_room);

    ClientGroupManager manager(factory, client_group_creator, pool);

    size_t numberOfTasks = client_group_creator.returnRandomClientNumber();
    size_t taskcout = table_factory.getNumberOfTask();

    manager.start(numberOfTasks);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    manager.stop();
    table_manage.start(taskcout);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    table_manage.stop();

    return 0;
}
