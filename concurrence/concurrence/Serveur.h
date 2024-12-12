#ifndef SERVEUR_H
#define SERVEUR_H

#include <QGraphicsPixmapItem>
#include <QString>

class Serveur : public QGraphicsPixmapItem
{
public:
    explicit Serveur(const QString &imagePath);
    void setPosition(int x, int y); // Définir la position du serveur
};

#endif // SERVEUR_H
