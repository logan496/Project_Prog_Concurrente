//
// Created by wolverine on 12/6/24.
//

#ifndef MOBILITYMODEL_H
#define MOBILITYMODEL_H
#include "../../../Observer/Observable.h"
#include <QObject>
#include <QTimer>
/**
 * @class MobilityModel
 */
class MobilityModel : public Observable, public QObject{
public:
    explicit MobilityModel(QObject *parent = nullptr);

    bool isAtDestionAbscice(int delatX) const;
    bool isAtDestinationIntercept(int delatY) const;

    void updatePosition();

    void move(int deltaX, int deltaY);
private:
    int abscice;
    int ordered;
    int deltaX, deltaY;
    QTimer *timer;
};
#endif //MOBILITYMODEL_H
