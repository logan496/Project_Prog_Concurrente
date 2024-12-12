#include "Plongeur.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QTimer>


Plongeur::Plongeur(const QString &imagePath, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), isCleaning(false)
{
    QPixmap plongeurPixmap(imagePath);
    if (plongeurPixmap.isNull()) {
        qDebug() << "Erreur : l'image du plongeur n'a pas été chargée ! Chemin : " << imagePath;
        return;
    }
    setPixmap(plongeurPixmap);
    setScale(0.2); // Ajustez la taille du plongeur
}

void Plongeur::setPosition(int x, int y)
{
    setPos(x, y);
}

void Plongeur::moveTo(int x, int y)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000); // Durée en millisecondes
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(x, y));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Plongeur::startCleaning()
{
    if (isCleaning) {
        qDebug() << "Le plongeur est déjà en train de nettoyer.";
        return;
    }
    isCleaning = true;
    qDebug() << "Le plongeur commence à nettoyer.";
    // Simuler une action de nettoyage avec un délai
    QTimer::singleShot(3000, [this]() {
        isCleaning = false;
        qDebug() << "Le plongeur a terminé le nettoyage.";
    });
}
