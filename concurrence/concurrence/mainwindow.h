#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include "Serveur.h"
#include "Client.h"
#include "Plongeur.h" // Inclusion correcte

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Méthodes pour ajouter des éléments à la scène
    void addTable(QGraphicsScene *scene, int x, int y, const QString &imagePath, int tableId);
    void addRefrigerator(QGraphicsScene *scene, int x, int y, const QString &imagePath);
    void addChef(QGraphicsScene *scene, int x, int y, const QString &imagePath);
    void addMaitreHotel(QGraphicsScene *scene, int x, int y, const QString &imagePath);
    void addServeur(QGraphicsScene *scene, int x, int y, const QString &imagePath, int serveurId);
    void addCuisiniere(QGraphicsScene *scene, int x, int y, const QString &imagePath);
    void addClient(QGraphicsScene *scene, int x, int y, const QString &imagePath, int clientId);
    void addPlongeur(QGraphicsScene *scene, int x, int y, const QString &imagePath);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<Serveur*> serveurs;
    QList<Client*> clients;
    QList<Plongeur*> plongeurs;
};

#endif // MAINWINDOW_H
