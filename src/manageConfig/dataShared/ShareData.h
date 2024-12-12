//
// Created by wolverine on 12/12/24.
//

#ifndef SHAREDATA_H
#define SHAREDATA_H

#include <vector>
#include <mutex>
#include <condition_variable>
#include "../Models/DinningRoom/classDeclaration/ClientModel.h"


class ShareData {
public:
    std::vector<std::vector<ClientModel>>  shared_list;
    std::mutex list_mutex;
    std::condition_variable list_condition;

};



#endif //SHAREDATA_H
