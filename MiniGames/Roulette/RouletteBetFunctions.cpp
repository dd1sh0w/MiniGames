//
// Created by konus on 11.07.2023.
//
#include "RouletteBetFunctions.h"

Bet BetCheck (int number, Bet bet) {
    int originBet;

    std::vector <int> lineOne   {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};
    std::vector <int> lineTwo   {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};
    std::vector <int> lineThree {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
    std::vector <int> sectorOne {1,2,3,4,5,6,7,8,9,10,11,12};
    std::vector <int> sectorTwo {13,14,15,16,17,18,19,20,21,22,23,24};
    std::vector <int> sectorThree {25,26,27,28,29,30,31,32,33,34,35,36};
    std::vector <int> red {1,3,5,7,9,12,14,16,18,21,23,25,27,28,30,32,34,36};
    std::vector <int> black {2,4,6,8,10,11,13,15,17,19,20,22,24,26,29,31,33,35};

    switch (bet.typeOfBet) {
        case 1:
            if (number == bet.number) {
                originBet = bet.changingTheBalance;
                bet.changingTheBalance *= -36;
                bet.theWonBet = true;
                return bet;
            }
            bet.changingTheBalance = 0;
            return bet;
        case 2:
            switch (bet.number) {
                case 1:
                    for (int i = 0; i <  lineOne.size(); i++) {
                        if (lineOne[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 2:
                    for (int i = 0; i < lineTwo.size(); i++) {
                        if (lineTwo[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 3:
                    for (int i = 0; i < lineThree.size(); i++) {
                        if (lineThree[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
            }
            bet.changingTheBalance = 0;
            return bet;
        case 3:
            switch (bet.number) {
                case 1:
                    for (int i : sectorOne) {
                        if (sectorOne[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 2:
                    for (int i : sectorTwo) {
                        if (sectorTwo[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 3:
                    for (int i : sectorThree) {
                        if (sectorThree[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -3) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
            }
            bet.changingTheBalance = 0;
            return bet;
        case 4:
            switch (bet.number) {
                case 1:
                    for (int i = 0; i < red.size(); i++) {
                        if (red[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -2) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 2:
                    for (int i = 0; i <  black.size(); i++) {
                        if (black[i] == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -2) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                    }
                    bet.changingTheBalance = 0;
                    return bet;
            }
            bet.changingTheBalance = 0;
            return bet;
        case 5:
            switch (bet.number) {
                case 1:
                    for (int i = 1; i < 36; i++) {
                        if (i == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -2) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                        i++;
                    }
                    bet.changingTheBalance = 0;
                    return bet;
                case 2:
                    for (int i = 2; i < 37; i++) {
                        if (i == number) {
                            originBet = bet.changingTheBalance;
                            bet.changingTheBalance = (bet.changingTheBalance * -2) ;
                            bet.theWonBet = true;
                            return bet;
                        }
                        i++;
                    }
                    bet.changingTheBalance = 0;
                    return bet;
            }
    }
    bet.changingTheBalance = 0;
    return bet;
}

int BetCash (int balance) {
    int cash = 99999999;
    while (cash > balance) {
        std::cout << "How much do we put?\n";
        std::cin >> cash;
        if (cash > balance) {
            std::cout << "You have no money!\n";
        }
    }
    return cash * -1;
}

Bet BetSelection (Bet bet, int balance) {
    std::cout << "What type of bet do you want place?" << std::endl;
    std::cout << "1 - bet on number (1:36)" << '\n' << "2 - bet on line (1:3)" << '\n' <<
              "3 - bet on sector (1:3)" << '\n' << "4 - bet on color (1:2)" << '\n' <<
              "5 - bet on odd or even (1:2)" << '\n';
    std::cin >> bet.typeOfBet;
    switch (bet.typeOfBet) {
        case 1:
            std::cout <<"What number? (from 0 to 36)" << '\n';
            std::cin >> bet.number;
            bet.changingTheBalance = BetCash(balance);
            break;
        case 2:
            std::cout <<"What line?" << '\n';
            std::cin >> bet.number;
            bet.changingTheBalance = BetCash(balance);
            break;
        case 3:
            std::cout <<"What sector? (1 - from 1 to 12,"
                        " 2 - from 13 to 24, 3 - from 25 to 36)" << '\n';
            std::cin >> bet.number;
            bet.changingTheBalance = BetCash(balance);
            break;
        case 4:
            std::cout <<"What color? (1 - red, 2 - black)" << '\n';
            std::cin >> bet.number;
            bet.changingTheBalance = BetCash(balance);
            break;
        case 5:
            std::cout <<"Odd or even? (1 - odd, 2 - even)" << '\n';
            std::cin >> bet.number;
            bet.changingTheBalance = BetCash(balance);
            break;

    }
    return bet;
}