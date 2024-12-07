//
// Created by wolverine on 12/4/24.
//
#include "MainView.h"

MainWindow::MainWindow(MobileElementView *element_view_) : element_view_(element_view_) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setSceneRect(0, 0, 800, 600);

    // Use the passed-in element_view_ (not creating a new one)
    scene->addItem(element_view_); // Add the passed-in element view to the scene

    view->show();

}



MainWindow::~MainWindow() {
    delete view;
    delete scene;
}



