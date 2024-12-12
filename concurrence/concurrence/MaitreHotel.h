#ifndef MAITREHOTEL_H
#define MAITREHOTEL_H

#include <QGraphicsPixmapItem>
#include <QString>


class MaitreHotel : public QGraphicsPixmapItem
{
public:
    explicit MaitreHotel(const QString &imagePath);
    void setPosition(int x, int y); // Définir la position du maître d'hôtel
};

#endif // MAITREHOTEL_H
