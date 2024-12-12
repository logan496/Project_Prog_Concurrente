//
// Created by wolverine on 12/4/24.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "../View/commonClass//ClassDeclaration/MobileElementView.h"
#include "../Models/DinningRoom/classDeclaration/DinningRoom.h"

class MainWindow{
public:
    explicit MainWindow(MobileElementView *element_view, DinningRoom *dinning_room);
    ~MainWindow();

    void createTable();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    MobileElementView *element_view_;
    DinningRoom *dinning_room_;
};

#endif //MAINVIEW_H
