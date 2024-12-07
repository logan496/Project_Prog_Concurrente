//
// Created by wolverine on 12/5/24.
//
#include "../View/DinningRoom/ClassDeclaration/MobileElementView.h"

#include <iostream>
#include <ostream>
#include <qbrush.h>
#include <QGraphicsEllipseItem>

#include "MainView.h"



MobileElementView::MobileElementView(QGraphicsEllipseItem *parent) : QGraphicsEllipseItem(parent), x(10), y(10){
    drawElement();
}

// void MobileElementView::update(const std::unordered_map<std::string, std::any> &data) {
//     try {
//         int newX = std::any_cast<int>(data.at("x"));
//
//         int newY = std::any_cast<int>(data.at("y"));
//         std::cout << newY << std::endl;
//
//         setElementPosition(newX, newY);
//     } catch (const std::exception &e) {
//         std::cerr << "Error while updating mobileElementView: " << e.what() << std::endl;
//     }
// }
void MobileElementView::update(const std::unordered_map<std::string, std::any>& data) {
    try {


        time = new QTimer(this);
        connect(time, &QTimer::timeout, [this,  data]() {
            int newX = x;
            int newY = y;
            if (data.count("x") > 0) {
                newX = std::any_cast<int>(data.at("x"));
            }
            if (data.count("y") > 0) {
                newY = std::any_cast<int>(data.at("y"));
            }
            setElementPosition(newX, newY);
        });
        time->start(16);

    } catch (const std::bad_any_cast& e) {
        std::cerr << "Error: Type mismatch for key 'x' or 'y': " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error while updating MobileElementView: " << e.what() << std::endl;
    }
}

// void MobileElementView::timerMovement() {
//     time = new QTimer(this);
//     time->setInterval(500);
//     connect(time, &QTimer::timeout, this, &MobileElementView::update);
//     time->start();
// }


void MobileElementView::drawElement() {
    setRect(x, y, 10, 10);
    setBrush(QBrush(Qt::blue));
    setPen(QPen(Qt::NoPen));
}



void MobileElementView::setElementPosition(int newX, int newY) {
    x = newX;
    y = newY;

    // QPointF startPos = this->pos();
    // QPointF endPos(newX, newY);
    //
    // QPropertyAnimation*  animation = new QPropertyAnimation(this, "pos");
    // animation->setDuration(500);
    // animation->setStartValue(startPos);
    // animation->setEndValue(endPos);
    //
    // animation->start(QPropertyAnimation::DeleteWhenStopped);

    this->setPos(x, y);
    std::cout << "MobileElementView::setElementPosition: x: " << x << ", y: " << y << std::endl;
}

