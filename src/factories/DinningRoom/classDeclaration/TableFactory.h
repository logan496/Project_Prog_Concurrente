//
// Created by wolverine on 12/9/24.
//

#ifndef TABLEFACTORY_H
#define TABLEFACTORY_H
#include <memory>

#include "../Models/DinningRoom/classDeclaration/Table.h"
#include "../Models/DinningRoom/classDeclaration/ClientModel.h"
#include <mutex>

/**
 * @class TableFactory
 * @brief this class is in charge of the creation of ours fixed table
 */
class TableFactory {
public:
    TableFactory();

    ~TableFactory();

    std::shared_ptr<Table> createFixedTable();

    /**
     * @brief this method classify table position by their array and square
     * @return the position of each of the 34 tables
     */
    std::pair<int, int> returnFixedPosition();

    int getNumberOfTask() const {return size(x_pos);}

    int ManageCapacityOfTable();

private:
    vector<ClientModel> client_list_{};
    int bread_cart_needed_ = 0; // default value
    int x_pos[33] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 0, 2, 4, 6, 8, 10, 12, 14, 16,
        20, 22, 24, 26, 28, 30, 32, 34, 20, 22, 24, 26, 28, 30, 32
    };

    int y_pos[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
        3, 3, 3, 3, 3, 3, 3
    };

    int i = 0;
    std::pair <int, int> actual_table_coordinate_;
    mutex lock;
};
#endif //TABLEFACTORY_H
