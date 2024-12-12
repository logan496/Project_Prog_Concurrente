#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "MaitreHotel.h"
#include "Serveur.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Assurez-vous que 'this' correspond bien à QMainWindow
    scene = new QGraphicsScene(nullptr);

    // Ajouter une image d'arrière-plan
    QString backgroundPath = "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/restaurant.png";
    QPixmap background(backgroundPath);
    if (background.isNull()) {
        qDebug() << "Erreur : l'image d'arrière-plan n'a pas été chargée ! Chemin : " << backgroundPath;
    } else {
        scene->addPixmap(background);
    }

    // Configurer la vue pour afficher la scène
    ui->restaurantGraphicsView->setScene(scene);

    // Ajouter des tables en utilisant la méthode addTable
    addTable(scene, 1000, 100, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 1);
    addTable(scene, 1000, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 2);
    addTable(scene, 1000, 250, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 3);
    addTable(scene, 825, 100, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 4);
    addTable(scene, 825, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 5);
    addTable(scene, 825, 250, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 6);
    addTable(scene, 650, 550, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 7);
    addTable(scene, 475, 550, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 8);
    addTable(scene, 300, 550, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 9);
    addTable(scene, 650, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 10);
    addTable(scene, 475, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 11);
    addTable(scene, 300, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/tables.png", 12);


    // Ajouter des frigo en utilisant la méthode addRefrigerator
    addRefrigerator(scene, 663, 225, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/frigo.png");

    //Ajoutez le cuisinier dans la cuisine
    addChef(scene, 500, 210, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/cuisinier.png");

    //Ajoutez le maitre d'hotel a la salle de restauration
    addMaitreHotel(scene, 200, 300, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/maitre_hotel.png");

    //Ajoutez le serveur la la selle de restauration
    addServeur(scene, 750, 150, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/serveur.png", 1);
    addServeur(scene, 200, 400, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/serveur.png", 2);

    addCuisiniere(scene, 350, 50, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/four.png");

    addClient(scene, 250, 500, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/client1.png", 1);
    addClient(scene, 200, 600, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/client2.png", 2);
    addClient(scene, 150, 500, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/client3.png", 3);
    addClient(scene, 230, 550, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/client4.png", 4);
    addClient(scene, 170, 500, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/client5.png", 5);

    // Ajoutez le plongeur à la scène
    addPlongeur(scene, 670, 80, "/Users/macbookpro/Documents/code/programmation concurente /test window/window_projet_sim/concurrence/images/Plongeurs.png");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTable(QGraphicsScene *scene, int x, int y, const QString &imagePath, int tableId)
{
    QPixmap tablePixmap(imagePath); // Charger l'image de la table
    if (tablePixmap.isNull()) {
        qDebug() << "Erreur : l'image de la table n'a pas été chargée ! Chemin : " << imagePath;
        return; // Ne rien faire si l'image est invalide
    }

    // Ajouter l'image de la table comme un élément graphique
    QGraphicsPixmapItem *tableItem = new QGraphicsPixmapItem(tablePixmap);
    tableItem->setPos(x, y); // Positionner la table
    tableItem->setData(0, tableId); // Stocker l'identifiant de la table comme donnée utilisateur
    scene->addItem(tableItem);

    qDebug() << "Table ajoutée avec succès à la position (" << x << "," << y << ") avec l'ID" << tableId;
}

void MainWindow::addRefrigerator(QGraphicsScene *scene, int x, int y, const QString &imagePath)
{
    QPixmap refrigeratorPixmap(imagePath);
    if (refrigeratorPixmap.isNull()) {
        qDebug() << "Erreur : l'image du réfrigérateur n'a pas été chargée ! Chemin : " << imagePath;
        return;
    }

    QGraphicsPixmapItem *refrigeratorItem = new QGraphicsPixmapItem(refrigeratorPixmap);
    refrigeratorItem->setPos(x, y); // Positionner l'image
    refrigeratorItem->setData(0, "Refrigerator"); // Ajouter des données utilisateur
    refrigeratorItem->setScale(0.3); // Réduire la taille à 50% (ajustez selon vos besoins)
    scene->addItem(refrigeratorItem);

    qDebug() << "Réfrigérateur ajouté avec succès à la position (" << x << "," << y << ").";
}

void MainWindow::addChef(QGraphicsScene *scene, int x, int y, const QString &imagePath)
{
    QPixmap chefPixmap(imagePath); // Charger l'image du cuisinier
    if (chefPixmap.isNull()) {
        qDebug() << "Erreur : l'image du cuisinier n'a pas été chargée ! Chemin : " << imagePath;
        return;
    }

    // Ajouter l'image comme un élément graphique
    QGraphicsPixmapItem *chefItem = new QGraphicsPixmapItem(chefPixmap);
    chefItem->setPos(x, y); // Positionner le cuisinier
    chefItem->setScale(0.12); // Réduire la taille à 50% (ajustez le facteur selon vos besoins)
    scene->addItem(chefItem);

    qDebug() << "Cuisinier ajouté avec succès à la position (" << x << "," << y << ").";
}


void MainWindow::addMaitreHotel(QGraphicsScene *scene, int x, int y, const QString &imagePath)
{
    MaitreHotel *maitreHotel = new MaitreHotel(imagePath);
    maitreHotel->setPosition(x, y);
    maitreHotel->setScale(0.15);
    scene->addItem(maitreHotel);
    qDebug() << "Maître d'hôtel ajouté avec succès à la position (" << x << "," << y << ").";
}

void MainWindow::addServeur(QGraphicsScene *scene, int x, int y, const QString &imagePath, int serveurId)
{
    Serveur *serveur = new Serveur(imagePath);
    serveur->setPosition(x, y);
    serveur->setScale(0.2);

    // Associer un identifiant unique au serveur
    serveur->setData(0, serveurId);

    // Ajouter le serveur à la scène et à la liste
    scene->addItem(serveur);
    serveurs.append(serveur);

    qDebug() << "Serveur ID" << serveurId << "ajouté avec succès à la position (" << x << "," << y << ").";
}


void MainWindow::addCuisiniere(QGraphicsScene *scene, int x, int y, const QString &imagePath)
{
    QPixmap cuisinierePixmap(imagePath); // Charger l'image de la cuisinière
    if (cuisinierePixmap.isNull()) {
        qDebug() << "Erreur : l'image de la cuisinière n'a pas été chargée ! Chemin : " << imagePath;
        return; // Ne rien faire si l'image est invalide
    }

    // Ajouter l'image comme un élément graphique
    QGraphicsPixmapItem *cuisiniereItem = new QGraphicsPixmapItem(cuisinierePixmap);
    cuisiniereItem->setPos(x, y); // Positionner la cuisinière
    cuisiniereItem->setData(0, "Cuisiniere"); // Ajouter des données utilisateur
    cuisiniereItem->setScale(0.3); // Réduire la taille si nécessaire
    scene->addItem(cuisiniereItem);

    qDebug() << "Cuisinière ajoutée avec succès à la position (" << x << "," << y << ").";
}

void MainWindow::addClient(QGraphicsScene *scene, int x, int y, const QString &imagePath, int clientId)
{
    Client *client = new Client(imagePath);
    client->setPosition(x, y);

    // Associez un ID unique au client
    client->setData(0, clientId);

    // Ajouter le client à la scène et à la liste
    scene->addItem(client);
    clients.append(client);

    qDebug() << "Client ID" << clientId << "ajouté avec succès à la position (" << x << "," << y << ").";
}

#include "Plongeur.h"

// ...

void MainWindow::addPlongeur(QGraphicsScene *scene, int x, int y, const QString &imagePath)
{
    Plongeur *plongeur = new Plongeur(imagePath);
    plongeur->setPosition(x, y);
    scene->addItem(plongeur);
    plongeurs.append(plongeur);

    qDebug() << "Plongeur ajouté avec succès à la position (" << x << "," << y << ").";
}


