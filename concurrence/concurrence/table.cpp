#include "table.h"

Table::Table(int id, const QString &imagePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), m_id(id), m_occupied(false)
{
    QPixmap tablePixmap(imagePath);
    if (!tablePixmap.isNull()) {
        setPixmap(tablePixmap); // Définir l'image de la table
    } else {
        qWarning() << "Erreur : Impossible de charger l'image pour la table ID :" << id;
    }
}

int Table::getId() const
{
    return m_id;
}

void Table::setId(int newId)
{
    m_id = newId;
}

bool Table::isOccupied() const
{
    return m_occupied;
}

void Table::setOccupied(bool occupied)
{
    m_occupied = occupied;
}
