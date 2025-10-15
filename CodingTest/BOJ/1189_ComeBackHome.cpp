#include <iostream>

using namespace std;

typedef pair<int, int> pii;
pii Dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool Map[5][5];
int R, C, K;
int Way = 0;

void Home(int row, int col, int move) {
	if (!Map[row][col] || move > K) return;
	if (row == 0 && col == C - 1) {
		if (move == K) Way++;
		return;
	}

	Map[row][col] = false;
	for (int i = 0; i < 4; ++i) {
		int nRow = row + Dir[i].first;
		int nCol = col + Dir[i].second;

		if (nRow >= R || nCol >= C || nRow < 0 || nCol < 0 || !Map[nRow][nCol]) continue;
		Home(nRow, nCol, move + 1);
	}
	Map[row][col] = true;
}

int main() {
	cin >> R >> C >> K;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			char p; cin >> p;
			Map[r][c] = (p == '.' ? true : false);
		}
	}

	Home(R - 1, 0, 1);
	cout << Way;
}