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
#include "../manageConfig/readEnv/EnvReader.h"
class MainWindow : public QGraphicsEllipseItem{
public:
    explicit MainWindow(MobileElementView *element_view, DinningRoom *dinning_room);
    // explicit MainWindow(MobileElementView *element_view);
    ~MainWindow();

    void createTable();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    MobileElementView *element_view_;
    DinningRoom *dinning_room_;
    // const auto background = envVars[""]

};

#endif //MAINVIEW_H
