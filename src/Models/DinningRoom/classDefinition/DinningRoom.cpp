//
// Created by wolverine on 12/2/24.
//
#include "../classDeclaration/DinningRoom.h"

vector<Table> DinningRoom::getEmptyTableList() {
    for (Table &table_ : tableList) {
        if(!table_.returnOccupedState()) {
            emptyTableList.push_back(table_);
        }
    }
    return emptyTableList;
}

vector<Table> DinningRoom::getTableList() {
    return this->tableList;
}

void DinningRoom::setTableList(std::shared_ptr<Table> const &tableElement) {
    this->tableList.push_back(*tableElement);
    cout << "table ajoutée à la liste" << endl;
}
