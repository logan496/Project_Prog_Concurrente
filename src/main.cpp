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

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Création des objets nécessaires
    MobilityModel mobilityModel;
    MobileElementView view;
    // Création et liaison du contrôleur
    MoveController moveController(&view, &mobilityModel);
    moveController.moveElement(200, 200);

    // Création de la fenêtre principale
    MainWindow main_window(&view);


    // Lancement de l'application
    app.exec();

    ThreadPool pool;
    ClientGroupFactory factory;
    ClientGroupCreator client_group_creator;
    TableFactory table_factory;

    TableCreateManager table_manage(table_factory, pool);

    ClientGroupManager manager(factory, client_group_creator, pool);

    size_t numberOfTasks = client_group_creator.returnRandomClientNumber();
    size_t taskcout = table_factory.getNumberOfTask();
    table_manage.start(taskcout);
    manager.start(numberOfTasks);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    manager.stop();

    return 0;

    // try {
    //     auto envVars = EnvReader::readEnv("src/.env");
    //     std::cout << "MY_ENV_VAR:" << envVars["TIME_WAIT_COOL_CLIENT"] << std::endl;
    // } catch (const std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }
}
