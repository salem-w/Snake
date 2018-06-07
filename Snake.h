#include <conio.h>
#include <iostream>

#include "Board.h"
#include "Food.h"

enum DIRECTION {UP, RIGHT, DOWN, LEFT}

class Snake
{
public:
	Snake();
	void run();
	void changeDirection();
	void draw();
	void move(int destinationX, int destinationY);

	bool running;

	int snakeLength;
	int snakeDirection;
	int currentXPos;
	int currentYPos;

	Board snakeBoard;
	
};