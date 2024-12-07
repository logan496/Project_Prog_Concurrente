//
// Created by wolverine on 12/4/24.
//

#include "DinningRoom/ClassDeclaration/ServerView.h"

#include <iostream>

void ServerView::update(const std::unordered_map<std::string, std::any> &data) {
    int x = std::any_cast<int>(data.at("x"));
    int y = std::any_cast<int>(data.at("y"));
    std::cout << "x: " << x << " y: " << y << std::endl;
}


