//
// Created by wolverine on 12/6/24.
//

#ifndef MOBILITYMODEL_H
#define MOBILITYMODEL_H
#include "../../../Observer/Observable.h"

/**
 * @class MobilityModel
 */
class MobilityModel : public Observable {
public:
    MobilityModel();

    bool isAtDestionAbscice(int delatX) const;
    bool isAtDestinationIntercept(int delatY) const;

    int getAbscice(){return abscice;};
    int getOrdered(){return ordered;};

    void move(int deltaX, int deltaY);
private:
    int abscice;
    int ordered;
};
#endif //MOBILITYMODEL_H
