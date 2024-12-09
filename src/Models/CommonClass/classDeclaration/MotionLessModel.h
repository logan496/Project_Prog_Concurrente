//
// Created by wolverine on 12/9/24.
//

#ifndef MOTIONLESSMODEL_H
#define MOTIONLESSMODEL_H
#include <QObject>

/**
 * @class MotionlessElementModel
 *
 * @brief this class will be used to create motionless element on the map
 */
class MotionlessElementModel : public QObject {
public:
    /**
     * @breif MotionlessElementModel constructor
     * @param parent
     * @param abscice the actual x of the element
     * @param ordinate the actual y of the element
     */
    explicit MotionlessElementModel(QObject *parent = nullptr, int abscice = 0, int ordinate = 0);

    int getAbscice() const { return abscice; }
    int getOrdinate() const { return ordinate; }

private:
    int abscice;
    int ordinate;
};
#endif //MOTIONLESSMODEL_H
