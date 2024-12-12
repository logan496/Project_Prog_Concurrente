#include "Client.h"
#include <QPropertyAnimation>
#include <QDebug>

Client::Client(const QString &imagePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), tableId(-1)
{
    QPixmap clientPixmap(imagePath);
    if (clientPixmap.isNull()) {
        qDebug() << "Erreur : l'image du client n'a pas été chargée ! Chemin : " << imagePath;
        return;
    }
    setPixmap(clientPixmap);
    setScale(0.2); // Ajustez la taille du client si nécessaire
}

void Client::setPosition(int x, int y)
{
    setPos(x, y);
}

void Client::moveTo(int x, int y)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000); // Durée en millisecondes
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(x, y));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

int Client::getTableId() const
{
    return tableId;
}

void Client::setTableId(int id)
{
    tableId = id;
}
