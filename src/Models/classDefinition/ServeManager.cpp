// ServeManager.cpp
#include "src/Controllers/classDefinition/ServeManager.h"
#include <iostream>

// Constructeur
ServeManager::ServeManager(KitchenCounter& counter, DishwasherModel& dishwasher, UstensilModel& ustensilModel)
    : kitchenCounter(counter), dishwasher(dishwasher), ustensilModel(ustensilModel) {}

// Récupérer les commandes prêtes sur le comptoir
void ServeManager::retrieveOrderFromCounter() {
    auto orders = kitchenCounter.getReadyOrders();
    for (const auto& order : orders) {
        if (order.getId() == 0) {
            std::cerr << "Erreur : Commande avec un ID invalide récupérée." << std::endl;
        } else {
            retrievedOrders.push_back(order);
            std::cout << "Commande " << order.getId() << " récupérée." << std::endl;
        }
    }
    if (!orders.empty() && retrievedOrders.size() != orders.size()) {
        std::cerr << "Erreur : Certaines commandes n'ont pas pu être récupérées correctement." << std::endl;
    }
    kitchenCounter.clearReadyOrders();
}

// Servir une commande à une table
void ServeManager::serveOrderToTable(Table& table) {
    if (retrievedOrders.empty()) {
        std::cout << "Aucune commande disponible pour servir." << std::endl;
        return;
    }
    Order order = retrievedOrders.front();
    retrievedOrders.erase(retrievedOrders.begin());
    table.receiveOrder(order);
    std::cout << "Commande " << order.getId() << " servie à la table." << std::endl;
}

// Récupérer les ustensiles sales d'une table
void ServeManager::collectDirtyUstensils(Table& table) {
    auto dirtyUstensils = table.getDirtyUstensils();
    ustensilModel.addDirtyUstensils(dirtyUstensils);
    std::cout << dirtyUstensils.size() << " ustensiles sales récupérés de la table." << std::endl;
}

// Envoyer les ustensiles sales au lave-vaisselle
void ServeManager::sendDirtyUstensilsToDishwasher() {
    auto dirtyUstensils = ustensilModel.getDirtyUstensils();
    dishwasher.loadUstensils(dirtyUstensils);
    ustensilModel.clearDirtyUstensils();
    std::cout << "Ustensiles sales envoyés au lave-vaisselle." << std::endl;
}