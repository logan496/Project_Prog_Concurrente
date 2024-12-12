//
// Created by wolverine on 12/9/24.
//

#ifndef MOTIONLESSMODEL_H
#define MOTIONLESSMODEL_H


/**
 * @class MotionlessElementModel
 *
 * @brief this class will be used to create motionless element on the map
 */
class MotionlessElementModel {
public:
    /**
     * @breif MotionlessElementModel constructor
     * @param abscice the actual x of the element
     * @param ordinate the actual y of the element
     */
    MotionlessElementModel(int abscice, int ordinate): abscice(abscice), ordinate(ordinate) {
    };

    int getAbscice() const { return abscice; }
    int getOrdinate() const { return ordinate; }

private:
    int abscice;
    int ordinate;
};
#endif //MOTIONLESSMODEL_H
