//
// Created by konus on 11.07.2023.
//

#include "RouletteBet.h"
#include <vector>
#include <iostream>

#ifndef MINIGAMES_ROULETTEBETFUNCTIONS_H
#define MINIGAMES_ROULETTEBETFUNCTIONS_H

Bet BetSelection(Bet bet, int balance);

Bet BetCheck(int number, Bet bet);

int BetCash(int balance);

#endif //MINIGAMES_ROULETTEBETFUNCTIONS_H
