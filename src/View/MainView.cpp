//
// Created by wolverine on 12/4/24.
//
#include "MainView.h"


#include <QTimer>  // Include this header for QTimer

MainWindow::MainWindow(MobileElementView *element_view, DinningRoom *dinning_room)
    : element_view_(element_view), dinning_room_(dinning_room) {

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    const QPixmap background("/home/wolverine/CLionProjects/Projet_Programmation_Syteme/Project_Prog_Concurrente/src/assets/restaurant.png");
    const QPixmap fullSizeBackground = background.scaled(1920, 1080, Qt::IgnoreAspectRatio);
    view->setSceneRect(0, 0, 1920, 1080);

    scene->addPixmap(fullSizeBackground);
    createTable();
    scene->addItem(element_view);

    // Delay table creation to avoid blocking the UI thread
   // QTimer::singleShot(std::chrono::milliseconds(10), [this]() { createTable(); }); // Asynchronous call

    view->show();
}



MainWindow::~MainWindow() {
    delete view;
    delete scene;
}

void MainWindow::createTable() {
    QPixmap tablePixmap("/home/wolverine/CLionProjects/Projet_Programmation_Syteme/Project_Prog_Concurrente/src/assets/tables.png");
    QPixmap scaledPixmap = tablePixmap.scaled(50, 50, Qt::IgnoreAspectRatio);
    for (const Table &table : dinning_room_->getTableList()) {
        QGraphicsPixmapItem *tableItem = new QGraphicsPixmapItem(scaledPixmap);
        cout << table.getAbscice() << endl;
        cout << table.getOrdinate() << endl;
        tableItem->setPos(table.getAbscice(), table.getOrdinate());
        scene->addItem(tableItem);
    }
    scene->update();
}



