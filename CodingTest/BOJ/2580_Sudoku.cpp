#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int board[9][9];
vector<pii> blanks;

bool CheckValid(const pii& point) {
	int Checker = 0;
	int OriginRow = point.first / 3;
	int OriginCol = point.second / 3;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			int num = board[OriginRow * 3 + r][OriginCol * 3 + c];
			if (num == 0) continue;
			if ((Checker & (1 << num)) == (1 << num)) return false;
			Checker = (Checker | (1 << num));
		}
	}

	Checker = 0;
	for (int c = 0; c < 9; ++c) {
		int num = board[point.first][c];
		if (num == 0) continue;
		if ((Checker & (1 << num)) == (1 << num)) return false;
		Checker = (Checker | (1 << num));
	}

	Checker = 0;
	for (int r = 0; r < 9; ++r) {
		int num = board[r][point.second];
		if (num == 0) continue;
		if ((Checker & (1 << num)) == (1 << num)) return false;
		Checker = (Checker | (1 << num));
	}

	return true;
}

void FillSudoku(int stack) {
	if (stack >= blanks.size()) {
		for (int r = 0; r < 9; ++r) {
			for (int c = 0; c < 9; ++c) {
				cout << board[r][c] << " ";
			}cout << "\n";
		}
		return;
	}

	for (int i = 1; i <= 9; ++i) {
		board[blanks[stack].first][blanks[stack].second] = i;
		if (CheckValid(make_pair(blanks[stack].first, blanks[stack].second))) {
			FillSudoku(stack + 1);
		}
	}
}

int main() {
	for (int r = 0; r < 9; ++r) {
		for (int c = 0; c < 9; ++c) {
			cin >> board[r][c];
			if (board[r][c] == 0) blanks.push_back(make_pair(r, c));
		}
	}

	FillSudoku(0);
}