#ifndef PLONGEUR_H
#define PLONGEUR_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Plongeur : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Plongeur(const QString &imagePath, QGraphicsItem *parent = nullptr);

    void setPosition(int x, int y);
    void moveTo(int x, int y); // Permettre au plongeur de se déplacer
    void startCleaning();      // Action de nettoyage

private:
    bool isCleaning;           // Indicateur si le plongeur est en train de nettoyer
};

#endif // PLONGEUR_H
