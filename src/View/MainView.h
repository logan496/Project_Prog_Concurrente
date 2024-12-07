//
// Created by wolverine on 12/4/24.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QGraphicsView>


#include <QGraphicsScene>

#include "../View/DinningRoom/ClassDeclaration/MobileElementView.h"

class MainWindow{
public:
    explicit MainWindow(MobileElementView *element_view);
    ~MainWindow();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    MobileElementView *element_view_;
};

#endif //MAINVIEW_H
