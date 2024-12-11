//
// Created by wolverine on 12/2/24.
//

#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Recipe.h"  // Inclure la classe Recipe
#include "Table.h"   // Inclure la classe Table
#include "ClientModel.h" // Inclure la classe ClientModel
#include "KitchenCounter.h" // Pour interaction avec la cuisine
#include "UstensilModel.h" // Pour gestion des ustensiles

class Order {
public:
    // Enumération pour représenter l'état de la commande
    enum class Status {
        PENDING,      // Commande en attente
        IN_PROGRESS,  // Commande en cours de préparation
        COMPLETED     // Commande terminée
    };

    // Constructeur par défaut
    Order();

    // Constructeur avec paramètres
    Order(int orderId, ClientModel* client, Table* table);

    // Ajouter une recette à la commande
    void addRecipe(const Recipe& recipe);

    // Supprimer une recette de la commande
    bool removeRecipe(const std::string& recipeName);

    // Mettre à jour l'état de la commande
    void updateStatus(Status newStatus);

    // Obtenir l'état actuel de la commande
    Status getStatus() const;

    // Gérer les ustensiles requis
    void manageUstensils(const UstensilModel& utensil);

    // Interaction avec la cuisine pour préparer les plats
    void sendToKitchen(KitchenCounter& kitchen);

    // Afficher les détails de la commande
    void printOrderDetails() const;

private:
    int orderId;                       // Identifiant unique de la commande
    ClientModel* client;               // Client ayant passé la commande
    Table* table;                      // Table associée à la commande
    std::vector<Recipe> recipes;       // Liste des recettes commandées
    Status status;                     // État de la commande
};

#endif // ORDER_H
