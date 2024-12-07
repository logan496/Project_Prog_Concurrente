//
// Created by wolverine on 12/4/24.
//

#ifndef SERVERVIEW_H
#define SERVERVIEW_H
#include <QLabel>
#include <QVBoxLayout>
#include "../Observer/Observer.h"


class ServerView : public Observer  {
public:

    void update(const std::unordered_map<std::string, std::any>& data) override;
    
};

#endif //SERVERVIEW_H
