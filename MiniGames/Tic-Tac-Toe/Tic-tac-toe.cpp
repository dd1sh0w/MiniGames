#include <iostream>
#include "functions.h"

const int SIZE = 3;
char gameField[SIZE][SIZE];

int main() {
	int mode;
	int firstMove;
	char playerSymb = 'X';
	char compSymb = 'O';

	initializeField(SIZE, gameField);
	mode = modeSelection();

	if (mode == 2) {
		firstMove = choiceOfFirstMove();

		if (firstMove == 2) {
			playerSymb = 'O';
			compSymb = 'X';
			compMove(gameField, compSymb, playerSymb);
		}

		while (!hasWinner('X', gameField) && !hasWinner('O', gameField) && !isTie(gameField)) {
			printField(gameField);

			int userRow, userCol;
			std::cout << "Enter your move (row and column, separated by space): ";
			std::cin >> userRow >> userCol;
			userRow--;
			userCol--;

			if (gameField[userRow][userCol] == '-') {
				gameField[userRow][userCol] = playerSymb;
			}
			else {
				std::cout << "Cell is already taken. Try again." << std::endl;
				continue;
			}

			if (hasWinner(playerSymb, gameField)) {
				printField(gameField);
				std::cout << "Congatulations! You are winner!";
			}

			if (isTie(gameField)) {
				printField(gameField);
				std::cout << "Is tie!";
			}

			compMove(gameField, compSymb, playerSymb);

			std::cout << "Computer is moving!\n" << std::endl;

			if (hasWinner(compSymb, gameField)) {
				printField(gameField);
				std::cout << "Sorry, you lose. Try again!";
			}

			if (isTie(gameField)) {
				printField(gameField);
				std::cout << "Is tie!";
			}
		}
	}
	else {
		while (!hasWinner('X', gameField) && !hasWinner('O', gameField) && !isTie(gameField)) {
			printField(gameField);

			int userRow, userCol;
			std::cout << "Enter your move (row and column, separated by space): ";
			std::cin >> userRow >> userCol;
			userRow--;
			userCol--;

			if (gameField[userRow][userCol] == '-') {
				gameField[userRow][userCol] = playerSymb;
			}
			else {
				std::cout << "Cell is already taken. Try again." << std::endl;
				continue;
			}

			if (hasWinner(playerSymb, gameField)) {
				printField(gameField);
				std::cout << "Winner is " << playerSymb;
			}

			if (isTie(gameField)) {
				printField(gameField);
				std::cout << "Is tie!";
			}
			playerSymb = (playerSymb == 'X') ? 'O' : 'X';
		}
	}

	std::cout << '\n';
	system("pause");
	return 0;
}

