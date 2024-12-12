#include "Serveur.h"

Serveur::Serveur(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        setPixmap(pixmap);
        setScale(0.5); // Réduire la taille à 50% (ajustez selon vos besoins)
    }
}

void Serveur::setPosition(int x, int y)
{
    setPos(x, y);
}
