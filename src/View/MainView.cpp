//
// Created by wolverine on 12/4/24.
//
#include "MainView.h"

MainWindow::MainWindow(MobileElementView *element_view, DinningRoom *dinning_room) : element_view_(element_view), dinning_room_(dinning_room) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setSceneRect(0, 0, 1920, 1080);

    scene->setBackgroundBrush(Qt::white);
    createTable();

    scene->addItem(element_view);

    view->show();
}


MainWindow::~MainWindow() {
    delete view;
    delete scene;
}

void MainWindow::createTable() {
    QPixmap tablePixmap("/home/wolverine/CLionProjects/Projet_Programmation_Syteme/Project_Prog_Concurrente/src/assets/table.jpg");
    QPixmap scaledPixmap = tablePixmap.scaled(100, 100, Qt::IgnoreAspectRatio);
    cout << dinning_room_->getTableList().size() << endl;
    for (Table table : dinning_room_->getTableList()) {
        QGraphicsPixmapItem *tableItem = new QGraphicsPixmapItem(scaledPixmap);
        cout << table.getAbscice() << endl;
        cout << table.getOrdinate() << endl;
        tableItem->setPos(table.getAbscice(), table.getOrdinate());
        scene->addItem(tableItem);
    }
}



