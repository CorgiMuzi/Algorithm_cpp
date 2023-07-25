#include <iostream>

#define VERT 0
#define HORIZ 1
#define DIAG 2

using namespace std;

int house[16][16];
int N = 0, method = 0;

bool isValidToCarry(const int& dir, const pair<int, int>& head) {
	int head_r = head.first, head_c = head.second;
	if (head_r >= N || head_c >= N || head_r < 0 || head_c < 0 || house[head_r][head_c] == 1) return false;

	if (dir == DIAG) {
		if (head_r - 1 < 0 || house[head_r - 1][head_c] == 1) return false;
		else if (head_c - 1 < 0 || house[head_r][head_c - 1] == 1) return false;
	}

	return true;
}

void carryingPipe(int dir, pair<int, int> head) {
	if (head == make_pair(N - 1, N - 1)) {
		method++;
		return;
	}

	int head_r = head.first, head_c = head.second;

	if (dir == HORIZ) {
		if (isValidToCarry(HORIZ, { head_r , head_c + 1 })) {
			carryingPipe(HORIZ, { head_r , head_c + 1 });
		}	

		if (isValidToCarry(DIAG, { head_r + 1, head_c + 1 })) {
			carryingPipe(DIAG, { head_r + 1, head_c + 1 });
		}
	}
	else if (dir == VERT) {
		if (isValidToCarry(VERT, { head_r + 1, head_c })) {
			carryingPipe(VERT, { head_r + 1, head_c });
		}

		if (isValidToCarry(DIAG, { head_r + 1, head_c + 1 })) {
			carryingPipe(DIAG, { head_r + 1, head_c + 1 });
		}
	}
	else if (dir == DIAG) {
		if (isValidToCarry(HORIZ, { head_r , head_c + 1 })) {
			carryingPipe(HORIZ, { head_r , head_c + 1 });
		}

		if (isValidToCarry(VERT, { head_r + 1, head_c })) {
			carryingPipe(VERT, { head_r + 1, head_c });
		}

		if (isValidToCarry(DIAG, { head_r + 1, head_c + 1 })) {
			carryingPipe(DIAG, { head_r + 1, head_c + 1 });
		}
	}
}

int main() {
	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> house[r][c];
		}
	}

	carryingPipe(HORIZ, {0, 1});
	cout << method;
}