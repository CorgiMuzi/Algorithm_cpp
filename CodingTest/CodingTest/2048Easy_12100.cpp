#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;
vvi board;
int boardSz;
int maxNum = 0;

void flip(vvi& b) {
	vvi bb = vvi(b.size(), vector<int>(b[0].size(), 0));
	for (int r = 0; r < boardSz; ++r) {
		for (int c = 0; c < boardSz; ++c) {
			bb[r][c] = b[c][r];
		}
	}

	b.swap(bb);
}

void leftShift(vvi& b) {
	for (int r = 0; r < boardSz; ++r) {
		int lastCell = 0;
		queue<int> q;
		for (int c = 0; c < boardSz; ++c) {
			if (b[r][c] == 0) continue;

			if (lastCell == 0) lastCell = b[r][c];
			else if (lastCell == b[r][c]) {
				q.push(lastCell * 2);
				lastCell = 0;
			}
			else {
				q.push(lastCell);
				lastCell = b[r][c];
			}
		}

		q.push(lastCell);
		for (int c = 0; c < boardSz; ++c) {
			if (q.empty()) b[r][c] = 0;
			else {
				b[r][c] = q.front();
				q.pop();
			}
		}
	}
}

void rightShift(vvi& b) {
	for (int r = 0; r < boardSz; ++r) {
		int lastCell = 0;
		queue<int> q;
		for (int c = boardSz - 1; c >= 0; --c) {
			if (b[r][c] == 0) continue;
			if (lastCell == 0) lastCell = b[r][c];
			else if (lastCell == b[r][c]) {
				q.push(lastCell * 2);
				lastCell = 0;
			}
			else {
				q.push(lastCell);
				lastCell = b[r][c];
			}
		}

		q.push(lastCell);
		for (int c = boardSz - 1; c << boardSz >= 0; --c) {
			if (q.empty()) b[r][c] = 0;
			else {
				b[r][c] = q.front();
				q.pop();
			}
		}
	}
}

void upShift(vvi& b) {
	flip(b);
	leftShift(b);
	flip(b);
}

void downShift(vvi& b) {
	flip(b);
	rightShift(b);
	flip(b);
}

void playShift(vvi& b, int stack) {
	if (stack == 5) {
		int top = *max_element(b[0].begin(), b[0].end());

		for (vector<int> v : b) {
			top = max(top, *max_element(v.begin(), v.end()));
		}

		maxNum = max(maxNum, top);

		return;
	}

	vvi bb = b;

	leftShift(bb);
	playShift(bb, stack + 1);
	bb = b;

	rightShift(bb);
	playShift(bb, stack + 1);
	bb = b;

	upShift(bb);
	playShift(bb, stack + 1);
	bb = b;

	downShift(bb);
	playShift(bb, stack + 1);

	return;
}

int main() {
	cin >> boardSz;

	for (int r = 0; r < boardSz; ++r) {
		vector<int> row;
		for (int c = 0; c < boardSz; ++c) {
			int cell; cin >> cell;
			row.push_back(cell);
		}
		board.push_back(row);
	}

	playShift(board, 0);

	cout << maxNum << "\n";
}
