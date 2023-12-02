#include <iostream>

using namespace std;

bool board[10][10];
bool rightTop[20], leftTop[20];
pair<int, int> origin;
int boardSize = 0;
int diagSize = 0;
int answer = 0;

bool isSafeToPlay(int ld, int rd) {
	if (leftTop[ld] || rightTop[rd]) return false;
	return true;
}

void playBishop(int diag, int numOfBishop) {
	if (diag >= diagSize) {
		answer = max(answer, numOfBishop);
		return;
	}

	bool isBishopPlayed = false;
	int cellPerDiag = diag < boardSize ? diag + 1 : diagSize - diag;
	for (int cell = 0; cell < cellPerDiag; ++cell) {
		int r = (boardSize - 1 <= diag) ? boardSize - 1 - cell : diag - cell;
		int c = (boardSize - 1 <= diag) ? diag - (boardSize - 1) + cell : cell;;

		if (!board[r][c]) continue;
		int diag2 = boardSize - 1 + (r - c);
		if (isSafeToPlay(diag, diag2)) {
			isBishopPlayed = true;
			leftTop[diag] = true;
			rightTop[diag2] = true;
			playBishop(diag, numOfBishop + 1);
			leftTop[diag] = false;
			rightTop[diag2] = false;
		}
	}

	if (!isBishopPlayed) playBishop(diag + 1, numOfBishop);
}

int main() {
	cin >> boardSize;
	diagSize = 2 * boardSize - 1;
	origin = make_pair(0, boardSize - 1);

	for (int row = 0; row < boardSize; ++row) {
		for (int col = 0; col < boardSize; ++col) {
			cin >> board[row][col];
		}
	}

	playBishop(0, 0);
	cout << answer << "\n";
}