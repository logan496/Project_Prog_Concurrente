//
// Created by wolverine on 12/9/24.
//
#include "../factories/DinningRoom/classDeclaration/TableFactory.h"

TableFactory::TableFactory() {
}

TableFactory::~TableFactory() = default;


std::shared_ptr<Table> TableFactory::createFixedTable() {
    actual_table_coordinate_ = returnFixedPosition();
    int capacity_table_ = ManageCapacityOfTable();
    cout << "table num : " << i << endl;
    return std::make_shared<Table>(actual_table_coordinate_.first, actual_table_coordinate_.second,
                                   capacity_table_, false, client_list_, bread_cart_needed_);
}

std::pair<int, int> TableFactory::returnFixedPosition() {
    std::pair<int, int> coordinate;

    coordinate.first = x_pos[i];
    coordinate.second = y_pos[i];
    i++;
    return coordinate;
}

int TableFactory::ManageCapacityOfTable() {
    // TODO : une méthode pour gérer efficacement l'attribution des capacités
    return 0;
}
