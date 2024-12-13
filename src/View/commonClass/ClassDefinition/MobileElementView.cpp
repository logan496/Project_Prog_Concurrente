//
// Created by wolverine on 12/5/24.
//
#include "../View/commonClass/ClassDeclaration/MobileElementView.h"

#include <iostream>
#include <ostream>
#include <qbrush.h>
#include <QGraphicsEllipseItem>
#include <QTimer>

#include "MainView.h"

MobileElementView::MobileElementView(QGraphicsEllipseItem *parent,
                                     MobilityModel *mobility_model) : QGraphicsEllipseItem(parent),
                                                                      mobilityModel(mobility_model) {
    x = mobilityModel->getAbscice();
    y = mobilityModel->getOrdered();
    mobilityModel->subscribe(this);
    drawElement();
}

MobileElementView::MobileElementView(QGraphicsEllipseItem *parent, HeadWaiter *head_waiter):
    QGraphicsEllipseItem(parent),
    head_waiter_(head_waiter)
     {
    x = head_waiter_->getAbscice();
    y = head_waiter_->getOrdered();
    head_waiter_->subscribe(this);
    drawElement();
}

void MobileElementView::update(const std::unordered_map<std::string, std::any> &data) {
    int newX = x;
    int newY = y;
    try {
        if (data.count("x") > 0)
            newX = std::any_cast<int>(data.at("x"));
        if (data.count("y") > 0)
            newY = std::any_cast<int>(data.at("y"));
        setElementPosition(newX, newY);
    } catch (const std::exception &e) {
        std::cerr << "Error while updating mobileElementView: " << e.what() << std::endl;
    }
}

void MobileElementView::drawElement() {
    setRect(x, y, 10, 10);
    setBrush(QBrush(Qt::blue));
    setPen(QPen(Qt::NoPen));
}


void MobileElementView::setElementPosition(int newX, int newY) {
    x = newX;
    y = newY;
    QRectF rect(x - 10, y - 10, 20, 20);
    scene()->update(rect);
    this->setPos(x, y);

    std::cout << "MobileElementView::setElementPosition: x: " << x << ", y: " << y << std::endl;
}
