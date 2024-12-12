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
    int y_pos[33] = {
        // Colonne 1 (gauche)
        50, 130, 210, 290, 370, 450, 530, 610, 690, 770, 850,
        // Colonne 2 (gauche)
        50, 130, 210, 290, 370, 450, 530, 610, 690, 770, 850,
        // Ligne (droite supérieure)
        50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50
    };

    int x_pos[33] = {
        // Colonne 1 (gauche)
        50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
        // Colonne 2 (gauche)
        130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130,
        // Ligne (droite supérieure)
        750, 830, 910, 990, 1070, 1150, 1230, 1310, 1390, 1470, 1550
    };


    int i = 0;
    std::pair<int, int> actual_table_coordinate_;

    mutex lock;
};
#endif //TABLEFACTORY_H
