#ifndef CHEF_H
#define CHEF_H

#include <QString>
#include <QGraphicsPixmapItem>

class Chef : public QGraphicsPixmapItem
{
public:
    explicit Chef(const QString &imagePath, QGraphicsItem *parent = nullptr);

    // Méthodes supplémentaires pour le cuisinier
    void setPosition(int x, int y); // Positionner le cuisinier
    void performTask(const QString &task); // Effectuer une tâche en cuisine

private:
    QString name; // Optionnel : Nom du cuisinier
    QString currentTask; // Tâche actuelle
};

#endif // CHEF_H
