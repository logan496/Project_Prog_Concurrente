// OrderManager.cpp
#include "OrderManager.h"
#include <iostream>

OrderManager::OrderManager() {
    // Initialisation du gestionnaire de commandes
}

void OrderManager::passerCommande(ClientModel* client, Table* table, const std::vector<Recipe>& recipes) {
    // Créer une nouvelle commande
    Order newOrder(client, table, recipes);

    // Ajouter la commande à la liste des commandes
    commandes.push_back(newOrder);

    std::cout << "Commande passée pour le client : " << client->getName() << std::endl;
}

void OrderManager::prendreCommande(Order& order) {
    // Ajouter la commande à la liste des commandes en cours
    commandes.push_back(order);

    std::cout << "Commande enregistrée pour la table : " << order.getTable()->getTableNumber() << std::endl;
}

void OrderManager::envoyerCommandeEnCuisine(Order& order, KitchenCounter& kitchen) {
    // Envoyer les recettes de la commande au comptoir de cuisine
    for (const auto& recipe : order.getRecipes()) {
        kitchen.addRecipe(recipe);
        std::cout << "Recette envoyée en cuisine : " << recipe.getName() << std::endl;
    }

    // Supprimer la commande des commandes en cours
    commandes.erase(std::remove(commandes.begin(), commandes.end(), order), commandes.end());
}
