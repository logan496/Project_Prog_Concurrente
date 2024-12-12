//
// Created by wolverine on 12/5/24.
//

#ifndef MOBILEELEMENT_H
#define MOBILEELEMENT_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QPropertyAnimation>
#include "../Observer/Observer.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
/**
 * @class MobileElementView
 */
class MobileElementView : public Observer, public QGraphicsEllipseItem, public QObject{
public:
    /**
     * @brief MobileElementView constructor
     * @param parent
     * @param abscice
     * @param ordered
     */
    explicit  MobileElementView(QGraphicsEllipseItem *parent = nullptr, int abscice=0, int ordered=0);

    /**
     * @brief this function receive the different coordinate of the element
     * through a point to another and update it position
     * @param data the tab of the different position of the mobile element
     */
    void update(const std::unordered_map<std::string, std::any>& data) override;
private:
    int x, y;

protected:
    void drawElement();
    void setElementPosition(int newX, int newY);
    MobilityModel mobilityModel;
    QTimer *time;


};
#endif //MOBILEELEMENT_H
