//
// Created by konus on 12.07.2023.
//

#ifndef MINIGAMES_PLAYER_H
#define MINIGAMES_PLAYER_H

#include <string>
#include <iostream>


class Player {
public:
    int balance;
    std::string name;

    Player() {
        balance = 100;
    }
    Player(std::string Name) {
        balance = 100;
        name = Name;
    }

    void getName();
};


#endif //MINIGAMES_PLAYER_H
