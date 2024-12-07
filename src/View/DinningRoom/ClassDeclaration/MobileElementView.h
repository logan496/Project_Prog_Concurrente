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
    explicit MobileElementView(QGraphicsEllipseItem *parent = nullptr);

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
