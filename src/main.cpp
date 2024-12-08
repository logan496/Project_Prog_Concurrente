#include <QApplication>
#include "MainView.h"
#include "../Controllers/classDeclaration/MoveController.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include "../View/DinningRoom/ClassDeclaration/MobileElementView.h"

int main(int argc, char **argv)
{
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

    return 0;

    // try {
    //     auto envVars = EnvReader::readEnv("src/.env");
    //     std::cout << "MY_ENV_VAR:" << envVars["TIME_WAIT_COOL_CLIENT"] << std::endl;
    // } catch (const std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }
}
