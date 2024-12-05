#include <QApplication>
#include "MainView.h"
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow main_window;
    main_window.setWindowTitle("Main interface");
    main_window.show();

    return app.exec();
}