//
// Created by wolverine on 12/4/24.
//
#include "MainView.h"

MainWindow::MainWindow(MobileElementView *element_view) : element_view_(element_view) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setSceneRect(0, 0, 800, 600);

    scene->addItem(element_view);

    view->show();
}


MainWindow::~MainWindow() {
    delete view;
    delete scene;
}



