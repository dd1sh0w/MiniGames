
#include "Roulette.h"
#include "RouletteBet.h"
#include "RouletteBetFunctions.h"


int Roulette(int balance) {
    Bet betOne;
    Bet betTwo;
    Bet betThree;

    bool exit = false;

    std::cout << "You have " << balance << "$" << std::endl;
    std::cout << "You can only place 3 bets at a time!" << std::endl << std::endl;

    while (true){
        betOne.Default(); // Bets to default option
        betTwo.Default();
        betThree.Default();

        int originBetOne = 0;
        int originBetTwo = 0;
        int originBetThree = 0;

        int number;
        bool otherBet = false;


        betOne = BetSelection(betOne, balance); // Bet one choose
        balance += betOne.changingTheBalance;
        originBetOne = betOne.changingTheBalance;

        std::cout << "Do you want place a second bet? (0 - No, 1 - Yes)" << '\n'; // Bet two choose
        std::cin >> otherBet;
        if (otherBet) {
            betTwo = BetSelection(betTwo, balance);
            balance += betTwo.changingTheBalance;
            originBetTwo = betTwo.changingTheBalance;
            otherBet = false;

            std::cout << "Do you want place a third bet? (0 - No, 1 - Yes)" << '\n'; // Bet three choose
            std::cin >> otherBet;
            if (otherBet) {
                betThree = BetSelection(betThree, balance);
                balance += betThree.changingTheBalance;
                originBetThree = betThree.changingTheBalance;
            }
        }
        std::cout << "We launch the ball" << '\n'; // Launch the ball
        number = RandomNumber(37);

        std::cout << "The ball stopped at the number " << number << '!' << '\n';

        betOne = BetCheck(number, betOne); //Bet one check
        balance += betOne.changingTheBalance;
        std::cout << "Your first bet ";
        if (betOne.theWonBet) {
            std::cout << "won!" << "You get a " << betOne.changingTheBalance << "$" << '\n';
        } else {std::cout << "lose.." << "You get a " << originBetOne << "$" << '\n';}

        if (betTwo.changingTheBalance != 0) { // Bet two check
            betTwo = BetCheck(number, betTwo);
            balance += betTwo.changingTheBalance;
            std::cout << "Your second bet ";
            if (betTwo.theWonBet) {
                std::cout << "won!" << "You get a " << betTwo.changingTheBalance << "$" << '\n';
            } else {std::cout << "lose.." << "You get a " << originBetTwo << "$" << '\n';}

            if (betThree.changingTheBalance != 0) { // Bet three check
                betThree = BetCheck(number, betThree);
                balance += betThree.changingTheBalance;
                std::cout << "Your third bet ";
                if (betThree.theWonBet) {
                    std::cout << "won!" << "You get a " << betThree.changingTheBalance << "$" << '\n';
                } else {std::cout << "lose.." << "You get a " << originBetThree << "$" << '\n';}
            }
        }

        std::cout << '\n' << "Now your balance is " << balance << '$' << '\n';

        std::cout << "If you want exit enter '1', else enter '0'" << '\n'; // Exit check
        std::cin >> exit;
        if (exit) return balance;
    }
}