#ifndef CLIENT_H
#define CLIENT_H

#include <QGraphicsPixmapItem>
#include <QObject> // Nécessaire pour utiliser QObject

class Client : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT // Macro requise pour les fonctionnalités de QObject

public:
    explicit Client(const QString &imagePath, QGraphicsItem *parent = nullptr);

    void setPosition(int x, int y);
    void moveTo(int x, int y); // Animation pour déplacer le client
    int getTableId() const;
    void setTableId(int id);

private:
    int tableId; // Identifiant de la table assignée au client
};

#endif // CLIENT_H
