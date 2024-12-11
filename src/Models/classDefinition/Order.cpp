//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/Order.h"
#include <iostream>
#include <algorithm>

// Constructeur par défaut
Order::Order() : orderId(0), client(nullptr), table(nullptr), status(Status::PENDING) {}

// Constructeur avec paramètres
Order::Order(int orderId, ClientModel* client, Table* table)
    : orderId(orderId), client(client), table(table), status(Status::PENDING) {}

// Ajouter une recette à la commande
void Order::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

// Supprimer une recette de la commande
bool Order::removeRecipe(const std::string& recipeName) {
    auto it = std::remove_if(recipes.begin(), recipes.end(), [&recipeName](const Recipe& recipe) {
        return recipe.getName() == recipeName;
    });
    if (it != recipes.end()) {
        recipes.erase(it, recipes.end());
        return true;
    }
    return false;
}

// Mettre à jour l'état de la commande
void Order::updateStatus(Status newStatus) {
    status = newStatus;
}

// Obtenir l'état actuel de la commande
Order::Status Order::getStatus() const {
    return status;
}

// Gérer les ustensiles requis
void Order::manageUstensils(const UstensilModel& utensil) {
    // Exemple : Afficher les informations sur les ustensiles requis
    std::cout << "Gestion des ustensiles requis: " << utensil.getName() << std::endl;
}

// Interaction avec la cuisine pour préparer les plats
void Order::sendToKitchen(KitchenCounter& kitchen) {
    for (const auto& recipe : recipes) {
        kitchen.prepareRecipe(recipe);
    }
    updateStatus(Status::IN_PROGRESS);
}

// Afficher les détails de la commande
void Order::printOrderDetails() const {
    std::cout << "Commande ID: " << orderId << std::endl;
    if (client) {
        std::cout << "Client: " << client->getName() << std::endl;
    }
    if (table) {
        std::cout << "Table: " << table->getTableNumber() << std::endl;
    }
    std::cout << "Etat de la commande: ";
    switch (status) {
        case Status::PENDING:
            std::cout << "En attente";
            break;
        case Status::IN_PROGRESS:
            std::cout << "En cours de préparation";
            break;
        case Status::COMPLETED:
            std::cout << "Terminée";
            break;
    }
    std::cout << std::endl;

    std::cout << "Recettes: " << std::endl;
    for (const auto& recipe : recipes) {
        std::cout << "- " << recipe.getName() << std::endl;
    }
}
