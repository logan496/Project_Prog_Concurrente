#include <QApplication>
#include "MainView.h"
#include "src/Controllers/classDeclaration/MoveController.h"
#include "src/Models/CommonClass/classDeclaration/MobilityModel.h"
#include "src/View/DinningRoom/ClassDeclaration/MobileElementView.h"

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
}
