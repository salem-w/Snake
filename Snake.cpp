#include <time.h>
#include <unistd.h>
#include <windows.h>

#include "Snake.h"

Snake::Snake() {
	Board b(20, 20);
	snakeBoard = b;
}

void Snake::run() {
	snakeBoard.generateBoard();
	running = true;
	double seconds;

	while(running) {
		std::time_t t = std::time(0);
		if(kbhit()) {
			changeDirection(_getch());
		}
		draw();//print update and clear

		seconds = std::difftime(std::time(0), t);
		Sleep(500 - seconds);

	}

	std::cout << "Game Over!\n";
	std::cin.ignore();
}

void Snake::changeDirection(char c) {
	if(c == 0 or c == 224)//first code for arrow keys
		switch(_getch()) {//get second code from _getch()
			case 72://up getch value
				snakeDirection = 0;
				break;
			case 77://left
				snakeDirection = 1;
				break;
			case 80://down
				snakeDirection = 2;
				break;
			case 75://right
				snakeDirection = 3;
				break;

		}
		move();
}

void Snake::draw() {
	switch(snakeDirection) {
		case UP:
			move(0, 1);
			break;
		case RIGHT:
			move(1,0);
			break;
		case DOWN:
			move(0, -1);
			break;
		case LEFT:
			move(-1,0);
			break;

	}

	System("cls");//clearing the screen

	snakeBoard.printBoard();

}

void move(int destinationX, int destinationY) {
	int newx = currentXPos + destinationX;
	int newy = currentYPos + destinationY;
	if(snakeBoard.hasFoodAt(newx, newy)) {
		snakeLength++;
		snakeBoard.createFood();
	}
	//if game over ...
	else if(snakeBoard.wallHit(newx, newy)) {
		running = false;
	}

	currentXPos = newx;
	currentYPos = newy;
	snakeBoard.changePosition(currentXPos, currentYPos);
}

