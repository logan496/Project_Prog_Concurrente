// Created by wolverine on 12/6/24.
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"

#include <iostream>
#include <QTimer>

MobilityModel::MobilityModel(QObject *parent)
    : QObject(parent), abscice(10), ordered(10), deltaX(0), deltaY(0),
      timer(new QTimer(this)) {}

bool MobilityModel::isAtDestionAbscice(int targetX) const {
    return abscice == targetX;
}

bool MobilityModel::isAtDestinationIntercept(int targetY) const {
    return ordered == targetY;
}

void MobilityModel::updatePosition() {
    connect(timer, &QTimer::timeout, [this]() {
        if (abscice != deltaX) {
            abscice += (deltaX > abscice ? 1 : -1);
            notify({{"x", abscice}});
        }else if(ordered != deltaY) {
            ordered += (deltaY > ordered ? 1 : -1);
            notify({{"y", ordered}});
        }
        if (isAtDestionAbscice(deltaX) && isAtDestinationIntercept(deltaY)) {
            timer->stop();
        }
    });
    timer->start(16); // 60 FPS
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
