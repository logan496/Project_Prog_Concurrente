#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsPixmapItem>
#include <QString>

class Table : public QGraphicsPixmapItem
{
public:
    explicit Table(int id, const QString &imagePath, QGraphicsItem *parent = nullptr);

    // Méthodes pour récupérer et définir des informations sur la table
    int getId() const;
    void setId(int newId);

    // Ajouter d'autres fonctionnalités, comme des états (occupé, libre, etc.)
    bool isOccupied() const;
    void setOccupied(bool occupied);

private:
    int m_id;          // Identifiant unique de la table
    bool m_occupied;   // État de la table
};

#endif // TABLE_H
