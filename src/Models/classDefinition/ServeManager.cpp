// Order.cpp
#include "Order.h"

// Constructeurs
Order::Order() : orderId(0), ready(false) {}

Order::Order(int orderId, const std::vector<Recipe>& recipes, const std::string& clientName)
    : orderId(orderId), recipes(recipes), clientName(clientName), ready(false) {}

// Accesseurs
int Order::getOrderId() const {
    return orderId;
}

const std::vector<Recipe>& Order::getRecipes() const {
    return recipes;
}

const std::string& Order::getClientName() const {
    return clientName;
}

bool Order::isReady() const {
    return ready;
}

// Mutateurs
void Order::setReady(bool readyStatus) {
    ready = readyStatus;
}
