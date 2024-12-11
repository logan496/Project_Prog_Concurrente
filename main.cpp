#include <QApplication>
#include "src/Views/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
//je doit integerer le chemain d'access vers le l'executable de mon fichier views pour gerer linterface
// exemple 