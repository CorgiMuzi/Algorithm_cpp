#include <iostream>
#include <vector>
using namespace std;

enum CellType {
	Blank,
	Snake,
	Apple
};

typedef struct {
	int x, y;
	CellType content;
}BoardCell;

int degree = 90;
int boardSize;
int endSec = 0;
int tempSec = 0;
vector<vector<BoardCell>> board;
vector<BoardCell> SnakeVec;

bool SnakeMove(int x, int y, char dir, int sec) {
	// Moving cell occured once each second.
	for (int i = 0; i < sec; i++) {
		switch (degree) {
		case 0:
			if (y - 1 < 0) { 
				endSec = tempSec + i + 1;
				return false; 
			}
			else {
				y = y - 1;
			}
			break;
			
		case 90:
			if (x + 1 > boardSize - 1) { 
				endSec = tempSec + i + 1;
				return false; 
			}
			else {
				x = x + 1;
			}
			break;
		case 180:
			if (y + 1 > boardSize - 1) { 
				endSec = tempSec + i + 1;
				return false; 
			}
			else {
				y = y + 1;
			}
			break;
		case 270:
			if (x - 1 < 0) { 
				endSec = tempSec + i + 1;
				return false; 
			}
			else {
				x = x - 1;
			}
			break;
		}

		if (board[x][y].content == Apple) {
			board[x][y].content = Snake;
			SnakeVec.push_back(board[x][y]);
		}
		else if (board[x][y].content == Snake) {
			endSec = tempSec + i + 1;
			return false;
		}
		else {
			board[x][y].content = Snake;
			SnakeVec.push_back(board[x][y]); // Add snake's head into the vector
			board[SnakeVec[0].x][SnakeVec[0].y].content = Blank; // Snake's tail cell turns into blank
			SnakeVec.erase(SnakeVec.begin()); // Delete snake's tail from vector
		}

		endSec = tempSec + sec;
	}

	// Changing degree occured once every move.
	if (dir == 'L') degree -= 90;
	else if (dir == 'D') degree += 90;

	if (degree < 0) degree += 360;
	else if (degree >= 360) degree -= 360;

	return true;
}

bool SnakeMove(int x, int y) {
	switch (degree) {
	case 0:
		if (y - 1 < 0) {
			endSec += 1;
			return false;
		}
		else {
			y = y - 1;
		}
		break;

	case 90:
		if (x + 1 > boardSize - 1) {
			endSec += 1;
			return false;
		}
		else {
			x = x + 1;
		}
		break;
	case 180:
		if (y + 1 > boardSize - 1) {
			endSec += 1;
			return false;
		}
		else {
			y = y + 1;
		}
		break;
	case 270:
		if (x - 1 < 0) {
			endSec += 1;
			return false;
		}
		else {
			x = x - 1;
		}
		break;
	}

	if (board[x][y].content == Apple) {
		board[x][y].content = Snake;
		SnakeVec.push_back(board[x][y]);
	}
	else if (board[x][y].content == Snake) {
		endSec += 1;
		return false;
	}
	else {
		board[x][y].content = Snake;
		SnakeVec.push_back(board[x][y]); // Add snake's head into the vector
		board[SnakeVec[0].x][SnakeVec[0].y].content = Blank; // Snake's tail cell turns into blank
		SnakeVec.erase(SnakeVec.begin()); // Delete snake's tail from vector
	}

	endSec += 1;

	return true;
}

int main() {

	cin >> boardSize;

	board.resize(boardSize);
	for (int i = 0; i < boardSize; i++) {
		board[i].resize(boardSize);
	}

	int appleCount;
	cin >> appleCount;

	board[0][0].content = Snake; // Init snake position
	SnakeVec.push_back(board[0][0]);

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].content = Blank;
		}
	}

	for (int i = 0; i < appleCount; i++) {
		int y, x;
		cin >> y >> x;
		board[x-1][y-1].content = Apple; // Inin apple position
	}

	int curveNumber;
	cin >> curveNumber;

	vector<int> secVec;
	vector<char> dirVec;

	for (int i = 0; i < curveNumber; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;

		secVec.push_back(sec);
		dirVec.push_back(dir);
	}

	int index = 0;

	for (int train = 0; train < dirVec.size(); train++) {
		if (train - 1 < 0) tempSec = 0;
		else tempSec = secVec[train-1];

		if (!SnakeMove(SnakeVec[SnakeVec.size() - 1].x, SnakeVec[SnakeVec.size() - 1].y, dirVec[train], secVec[train] - tempSec)) {
			cout << endSec;
			return 0;
		}
	}

	while (true) {
		if (!SnakeMove(SnakeVec[SnakeVec.size() - 1].x, SnakeVec[SnakeVec.size() - 1].y)) {
			cout << endSec;
			return 0;
		}
	}

	return 0;
}