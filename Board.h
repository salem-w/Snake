struct Node {
	int x;
	int y;
	Node* next;
}

class Board
{
public:
	Board(int w);
	void printBoard();
	void generateBoard();
	void updateBoard();
	void changePosition(int x, int y);
	void createFood();

private:
	int boardWidth;
	int area;
	char board[][];
	int snakeHeadX;
	int snakeHeadY;
	
};

