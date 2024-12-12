//
// Created by wolverine on 12/2/24.
//

#ifndef DINNINGROOM_H
#define DINNINGROOM_H

#include <vector>
#include <queue>

#include "Table.h"
using namespace std;

/**
 * @class DinningRoom
 *
 * @brief this class manage all the elements in the dinning room
 */
class DinningRoom {
public:
    /**
     * @brief constructor of the dinning room
     *
     * @param bread_cart_available
     * @param card_distribueted
     * @param current_client_number
     * @param is_first_square_busy
     * @param is_second_square_busy
     * @param firt_square_busy_server_number
     * @param second_square_busy_server_number
     */
    DinningRoom(int bread_cart_available, int card_distribueted,
                int current_client_number, bool is_first_square_busy,
                bool is_second_square_busy,
                int firt_square_busy_server_number, int second_square_busy_server_number
    )
        : breadCartAvailable(bread_cart_available),
          cardDistribueted(card_distribueted),
          currentClientNumber(current_client_number),
          isFirstSquareBusy(is_first_square_busy),
          isSecondSquareBusy(is_second_square_busy),
          firtSquareBusyServerNumber(firt_square_busy_server_number),
          secondSquareBusyServerNumber(second_square_busy_server_number) {
    }

    DinningRoom(){}

    /**
     * @brief this function take the list of table which don't have any client
     * on and send it to the Butler
     *
     * @return EmptyTable[]
     */
    vector<Table> getEmptyTableList();

    /**
     * @brief getter for the tableList attribute
     * @return tableList
     */
    vector<Table> getTableList();

    void setTableList(shared_ptr<Table> const &tableElement);

private:
    vector<Table> tableList;
    vector<Table> emptyTableList;
    int breadCartAvailable = 0;
    int cardDistribueted = 0;
    int currentClientNumber = 0;
    int totalClientOfTheDay =0;
    bool isFirstSquareBusy = false;
    bool isSecondSquareBusy = false;
    int firtSquareBusyServerNumber = 0;
    int secondSquareBusyServerNumber = 0;
    queue<Table> firstSquareRequest;
    queue<Table> secondSquareRequest;
};

#endif //DINNINGROOM_H
