#include "MaitreHotel.h"

MaitreHotel::MaitreHotel(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        setPixmap(pixmap);
        setScale(0.1); // Réduire la taille à 50% (ajustez selon vos besoins)
    }
}

void MaitreHotel::setPosition(int x, int y)
{
    setPos(x, y);
}
