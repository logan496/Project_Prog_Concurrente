//
// Created by wolverine on 12/4/24.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QMainWindow>
#include <QWidget>
#include <QLabel>

#include "../View/DinningRoom/ClassDeclaration/ServerView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow() override;

    ServerView* getServerView();

    void setupUi();
protected:
    ServerView *serverView;
    std::queue<int> foko_queue;
    // importer ici les éléments de la vue

};

#endif //MAINVIEW_H
