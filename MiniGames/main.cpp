
#include <iostream>
#include "Roulette/Roulette.h"
#include "Functions/Player.h"

int main() {
    Player player;

    player.getName();

   int numberOfGame;


   std::cout << "\n\n\nHi,"<< player.name << "!\n";
   std::cout << "You have a 100$ at the start, but if you lose them, then the game is over \n" <<
                "But if you reach 1000$ then you will become a winner! \n \t\t\t Good luck! \n";
   std::cout << "\n#############################################################################################\n\n";

    while(true) {
       std::cout << "Your balance is " << player.balance << "$\n\n";
       std::cout << "List of the games:\n";
       std::cout << "1. Roulette" << '\n';
       std::cout << "\nEnter the number of the desired game(or '0' if you want exit): ";
       std::cin >> numberOfGame;
       switch (numberOfGame) {
           case 1:
               player.balance = Roulette(player.balance);
               break;
           case 0:
               std::cout << '\n' << "Bye!";
               return 0;
           default:
               std::cout << '\n' << "Incorrect number!";
       }
       if (player.balance <= 0) {
           std::cout << "\n\t\t\tYou are lose!";
           return 0;
       } else {
           if (player.balance >= 1000) {
               int continued = 0;
               std::cout << "You are win!\n" << "Do you want to continue? (0 - No, 1 - Yes)";
               std::cin >> continued;
               if (continued == 0) {
                   std::cout << "Bye!\n";
                   return 0;
               }
           }
       }
   }
}
