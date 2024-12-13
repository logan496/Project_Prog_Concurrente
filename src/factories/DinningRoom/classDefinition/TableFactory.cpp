//
// Created by wolverine on 12/9/24.
//
#include "../factories/DinningRoom/classDeclaration/TableFactory.h"

TableFactory::TableFactory() {
}

TableFactory::~TableFactory() = default;


std::shared_ptr<Table> TableFactory::createFixedTable() {
    try {
        std::pair<int, int> coordinates = returnFixedPosition();
        int capacity_table_ = ManageCapacityOfTable();

        return std::make_shared<Table>(coordinates.first, coordinates.second,
                                       capacity_table_, false, client_list_, bread_cart_needed_);
    } catch (const std::out_of_range &e) {
        std::cerr << "Erreur lors de la création de la table : " << e.what() << std::endl;
        return nullptr; // Retourner un pointeur nul si aucune table ne peut être créée
    }
}


std::pair<int, int> TableFactory::returnFixedPosition() {
    std::pair<int, int> coordinate;
    coordinate.first = x_pos[i];
    coordinate.second = y_pos[i];
    i++;
    return coordinate;
}

int TableFactory::ManageCapacityOfTable() const {
    srand(time(nullptr));
    const int indexToSend = rand() % 9;
    return table_capacity[indexToSend];
}
