#include "chef.h"
#include <QDebug>

Chef::Chef(const QString &imagePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), name("Unnamed"), currentTask("Idle")
{
    QPixmap chefPixmap(imagePath);
    if (chefPixmap.isNull()) {
        qDebug() << "Erreur : l'image du cuisinier n'a pas été chargée ! Chemin : " << imagePath;
    } else {
        setPixmap(chefPixmap);
    }
}

void Chef::setPosition(int x, int y)
{
    setPos(x, y);
    qDebug() << "Cuisinier positionné à (" << x << "," << y << ").";
}

void Chef::performTask(const QString &task)
{
    currentTask = task;
    qDebug() << "Le cuisinier effectue la tâche :" << task;
}
