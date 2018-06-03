#include "Board.h"
#include <iostream>

Board::Board(int w) {
	this->boardWidth = w;
	this->area = w * w;
	char b[w][w];
	this->board = b;
}

Board::printBoard() {
	for(int i = 0; i < this->boardWidth; i++) {
		for(int j = 0; j < this->boardWidth; j++)
			 std::cout << board[i][j]

		std::cout << std::endl;
	}
}

Board::generateBoard() {
	//creating walls
	for(int i = 0; i < this->boardWidth) {
		this->board[0][i] = char(219);
		this->board[boardWidth][i] = char(219);
		this->board[i][0] = char(219);
		this->board[i][boardWidth] = char(219);
	}
}