
#include <iostream>
#include <string>
#include <fstream>
#include "Functions/Greeting.h"
#include "Roulette/Roulette.h"
#include "Functions/Player.h"
#include "Tic-Tac-Toe/Tic-tac-toe.h"

int main() {
    Player player;


   int numberOfGame;
   bool resetSave = true;

   std::string pathOfSaveFile = "save.txt";

   std::ofstream fout;
   std::ifstream fin;
  

   fin.open(pathOfSaveFile);
   fin >> resetSave;
   if (resetSave) {
       player = Greeting();
       resetSave = false;
   }
   else {
       while (fin.read((char*)&player, sizeof(Player)));
   }
   if (player.balance <= 0) {
       player = Greeting();
   }
   fin.close();


    while(true) {
       std::cout << "\n\nYour balance is " << player.balance << "$\n\n";
       std::cout << "List of the games:\n";
       std::cout << "1. Roulette\n";
       std::cout << "2. Tic-Tac-Toe\n";
       std::cout << "\nEnter the number of the desired game(or '0' if you want exit): ";
       std::cin >> numberOfGame;
       switch (numberOfGame) {
           case 2:
               TicTacToe();
               break;
           case 1:
               player.balance = Roulette(player.balance);
               break;
           case 0:
               std::cout << '\n' << "Bye!";
               fout.open(pathOfSaveFile);
               fout << resetSave;
               fout.write((char*)&player, sizeof(Player));
               fout.close();
               return 0;
           default:
               std::cout << '\n' << "Incorrect number!";
       }
       fout.open(pathOfSaveFile);
       fout << resetSave;
       fout.write((char*)&player, sizeof(Player));
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
       fout.close();
   }
}
