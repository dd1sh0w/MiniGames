#pragma once

#include <iostream>

void initializeField(const int SIZE, char (*gameField)[3]);

int modeSelection();

int choiceOfFirstMove();

bool hasWinner(char symb, char(*gameField)[3]);

bool isTie(char(*gameField)[3]);

void printField(char(*gameField)[3]);

int minimax(char(*gameField)[3], char player, char playerSymb, char compSymb);

void compMove(char(*gameField)[3], char compSymb, char playerSymb);


