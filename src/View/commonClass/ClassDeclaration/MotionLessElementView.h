//
// Created by wolverine on 12/9/24.
//

#ifndef MOTIONLESSELEMENTVIEW_H
#define MOTIONLESSELEMENTVIEW_H

#include <QGraphicsEllipseItem>
#include <QPen>

/**
 * @class MotionLessElementView
 */
class MotionLessElementView : public QGraphicsEllipseItem {
public:
    MotionLessElementView(QGraphicsEllipseItem *parent, const int elementX, const int elementY, const int elementWidth,
                          const int elementHeight) : QGraphicsEllipseItem(parent), x(elementX), y(elementY),
                                                     width(elementWidth), height(elementHeight) {
        drawElement();
    }

private:
    int x, y, width, height;

protected:
    void drawElement() {
        setRect(x, y, width, height);
        setBrush(QBrush(Qt::white));
        setPen(QPen(Qt::NoPen));
    };
};
#endif //MOTIONLESSELEMENTVIEW_H
