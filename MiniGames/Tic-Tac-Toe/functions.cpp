#include "functions.h"


void initializeField(const int SIZE, char(*gameField)[3]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			gameField[i][j] = '-';
		}
	}
}

int modeSelection() {
	int mode;
	std::cout << "What mode you will play?\nPlayer VS Player -- 1\nPlayer VS Computer -- 2\n";
	std::cin >> mode;
	return mode;
}

int choiceOfFirstMove() {
	int firstMove;
	std::cout << "Whom put first?\nYou -- 1\nComputer -- 2\n";
	std::cin >> firstMove;
	return firstMove;
}

bool hasWinner(char symb, char(*gameField)[3]) {
	for (int i = 0; i < 3; i++) {
		if ((gameField[i][0] == symb && gameField[i][1] == symb && gameField[i][2] == symb) ||
			(gameField[0][i] == symb && gameField[1][i] == symb && gameField[2][i] == symb)) {
			return true;
		}
	}

	if ((gameField[0][0] == symb && gameField[1][1] == symb && gameField[2][2] == symb) ||
		(gameField[0][2] == symb && gameField[1][1] == symb && gameField[2][0] == symb)) {
		return true;
	}

	return false;
}

bool isTie(char(*gameField)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameField[i][j] == '-') {
				return false;
			}
		}
	}

	return true;
}

void printField(char(*gameField)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << gameField[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int minimax(char (*gameField)[3], char player, char playerSymb, char compSymb) {
	if (hasWinner(playerSymb, gameField)) return -1;
	if (hasWinner(compSymb, gameField)) return 1;
	if (isTie(gameField)) return 0;

	int bestScore = (player == compSymb) ? INT_MIN : INT_MAX;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (gameField[i][j] == '-') {
				gameField[i][j] = player;

				if (player == compSymb) {
					int score = minimax(gameField, playerSymb, playerSymb, compSymb);
					bestScore = std::max(bestScore, score);
				}
				else {
					int score = minimax(gameField, compSymb, playerSymb, compSymb);
					bestScore = std::min(bestScore, score);
				}

				gameField[i][j] = '-';
			}
		}
	}

	return bestScore;
}

void compMove(char(*gameField)[3], char compSymb, char playerSymb) {
	int bestMoveScore = INT_MIN;
	int bestMoveRow = -1;
	int bestMoveCol = -1;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (gameField[i][j] == '-') {
				gameField[i][j] = compSymb;
				int moveScore = minimax(gameField, playerSymb, playerSymb, compSymb);
				gameField[i][j] = '-';

				if (moveScore > bestMoveScore) {
					bestMoveScore = moveScore;
					bestMoveRow = i;
					bestMoveCol = j;
				}
			}
		}
	}

	gameField[bestMoveRow][bestMoveCol] = compSymb;
}