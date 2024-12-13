// Created by wolverine on 12/6/24.
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include <iostream>
#include <QObject>

MobilityModel::MobilityModel(QObject *parent, int abscice, int ordered)
    : QObject(parent), abscice(abscice), ordered(ordered), deltaX(0), deltaY(0),
      timer(new QTimer(this)) {
}


bool MobilityModel::isAtDestionAbscice(int targetX) const {
    return abscice == targetX;
}

bool MobilityModel::isAtDestinationIntercept(int targetY) const {
    return ordered == targetY;
}

int MobilityModel::getAbscice() const {
    return abscice;
}

int MobilityModel::getOrdered() const {
    return ordered;
}

void MobilityModel::updatePosition() {
    QMetaObject::invokeMethod(this,[this]() {
        connect(timer, &QTimer::timeout, [this]() {
        if (abscice != deltaX) {
            abscice += (deltaX > abscice ? 1 : -1);
            notify({{"x", abscice}});
        } else if (ordered != deltaY) {
            ordered += (deltaY > ordered ? 1 : -1);
            notify({{"y", ordered}});
        }
        if (isAtDestionAbscice(deltaX) && isAtDestinationIntercept(deltaY)) {
            timer->stop();
        }
    });
    timer->start(16); // 60 FPS
    }, Qt::QueuedConnection);

}

void MobilityModel::move(int delX, int delY) {
    deltaX = delX;
    deltaY = delY;
    notify({{"x", abscice}, {"y", ordered}});
    std::cout << "Moving to: " << deltaX << ", " << deltaY << std::endl;
    if (!timer->isActive()) {
        updatePosition();
    }
}
