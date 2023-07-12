//
// Created by konus on 12.07.2023.
//

#ifndef MINIGAMES_PLAYER_H
#define MINIGAMES_PLAYER_H

#include <string>
#include <iostream>


class Player {
public:
    int balance = 100;
    std::string name;

    void getName();
};


#endif //MINIGAMES_PLAYER_H
