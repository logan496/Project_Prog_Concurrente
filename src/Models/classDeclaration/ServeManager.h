#ifndef SERVEMANAGER_H
#define SERVEMANAGER_H

#include "src/Models/classDeclaration/Order.h"
#include "src/Models/classDeclaration/KitchenCounter.h"
#include "src/Models/classDeclaration/Table.h"
#include "src/Models/classDeclaration/DishwasherModel.h"
#include "src/Models/classDeclaration/UstensilModel.h"
#include <vector>

// Classe pour gérer le service des commandes
class ServeManager {
public:
    // Constructeur
    ServeManager(KitchenCounter& counter, DishwasherModel& dishwasher, UstensilModel& ustensilModel);

    // Méthodes principales
    void retrieveOrderFromCounter();         // Récupérer les commandes prêtes sur le comptoir
    void serveOrderToTable(Table& table);    // Servir une commande à une table
    void collectDirtyUstensils(Table& table); // Récupérer les ustensiles sales d'une table
    void sendDirtyUstensilsToDishwasher();   // Envoyer les ustensiles sales au lave-vaisselle

private:
    KitchenCounter& kitchenCounter;         // Référence au comptoir de la cuisine
    DishwasherModel& dishwasher;            // Référence au modèle du lave-vaisselle
    UstensilModel& ustensilModel;           // Référence au modèle des ustensiles
    std::vector<Order> retrievedOrders;     // Commandes récupérées du comptoir
};

#endif // SERVEMANAGER_H
