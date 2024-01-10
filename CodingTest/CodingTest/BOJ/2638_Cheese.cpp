#include <iostream>
#include <queue>

#define CHEESE 1

using namespace std;

int room[100][100];
pair<int, int> corners[4];
int N = 0, M = 0, elapsedTime = 0;
int rDir[4] = { -1, 1, 0, 0 };
int cDir[4] = { 0, 0, -1, 1 };
bool isCheeseRemaining = true;

void meltingCheese() {
	queue<pair<int, int>> air;
	for (int i = 0; i < 4; ++i) {
		air.push(corners[i]);
	}

	bool isVisit[100][100] = { false };
	isVisit[0][0] = true;
	isVisit[N - 1][0] = true;
	isVisit[0][M - 1] = true;
	isVisit[N - 1][M - 1] = true;

	while (!air.empty()) {
		int cur_r = air.front().first, cur_c = air.front().second;
		air.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nxt_r = cur_r + rDir[dir];
			int nxt_c = cur_c + cDir[dir];

			if (nxt_r < 0 || nxt_c < 0 || nxt_r >= N || nxt_c >= M || isVisit[nxt_r][nxt_c]) continue;
			
			if (room[nxt_r][nxt_c] >= CHEESE) {
				room[nxt_r][nxt_c]++;
				continue;
			}
			
			isVisit[nxt_r][nxt_c] = true;
			air.push(make_pair(nxt_r, nxt_c));
		}

	}

	isCheeseRemaining = false;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (room[r][c] >= CHEESE + 2) {
				room[r][c] = 0;
			}
			else if (room[r][c] > 0) {
				room[r][c] = CHEESE;
				isCheeseRemaining = true;
			}
		}
	}

	elapsedTime++;
}

int main() {
	cin >> N >> M;

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> room[r][c];
		}
	}

	corners[0] = make_pair(0, 0);
	corners[1] = make_pair(N - 1, 0);
	corners[2] = make_pair(0, M - 1);
	corners[3] = make_pair(N - 1, M - 1);

	while (isCheeseRemaining) {
		meltingCheese();
	}

	cout << elapsedTime;
}