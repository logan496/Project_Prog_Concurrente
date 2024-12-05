//
// Created by wolverine on 12/4/24.
//
#include "MainView.h"

#include <qlayout.h>

MainWindow::MainWindow()
 {
    setupUi();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi() {
    QWidget widget;
    widget.setFixedSize(800, 600);

    serverView = new ServerView(this, foko_queue);

    serverView->setGeometry(0, 500, 800, 100);
}


