#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int room[50][50];
int rDir[4] = { -1, 1, 0, 0 };
int cDir[4] = { 0, 0, -1, 1 };
int R = 0, C = 0, T = 0;
vector<int> airConditional;
vector<pair<int, pair<int, int>>> dustVec;


void findingDust() {
	dustVec.clear();
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (room[r][c] > 0) {
				dustVec.push_back(make_pair(room[r][c], make_pair(r, c)));
			}
		}
	}
}

void spreadingDust() {
	findingDust();

	vector<pair<int, pair<int, int>>>::iterator dustIter = dustVec.begin();
	while (dustIter != dustVec.end()) {
		int spreadDustAmount = dustIter->first / 5;

		int spreadDir = 0;
		for (int i = 0; i < 4; ++i) {
			int mr = dustIter->second.first + rDir[i];
			int mc = dustIter->second.second + cDir[i];

			if (mr < 0 || mc < 0 || mr >= R || mc >= C || room[mr][mc] == -1) continue;
			room[mr][mc] += spreadDustAmount;
			spreadDir++;
		}

		room[dustIter->second.first][dustIter->second.second] -= spreadDustAmount * spreadDir;
		dustIter++;
	}
}

void airCirculation() {
	vector<int> tempRooms;
	tempRooms.push_back(room[0][0]);
	tempRooms.push_back(room[R - 1][0]);
	for (int c = 0; c < C - 1; ++c) {
		// <------------------------
		room[0][c] = room[0][c + 1];
		room[R - 1][c] = room[R - 1][c + 1];
	}

	tempRooms.push_back(room[airConditional[0]][C - 1]);
	tempRooms.push_back(room[airConditional[1]][C - 1]);
	for (int c = C - 1; c >= 1; --c) {
		// ---------------------->
		room[airConditional[0]][c] = (c == 1) ? 0 : room[airConditional[0]][c - 1];
		room[airConditional[1]][c] = (c == 1) ? 0 : room[airConditional[1]][c - 1];
	}

	for (int r = airConditional[0] - 1; r >= 1; --r) {
		room[r][0] = (r == 1) ? tempRooms[0] : room[r - 1][0];
	}

	for (int r = 0; r < airConditional[0]; ++r) {
		room[r][C - 1] = (r == airConditional[0] - 1) ? tempRooms[2] : room[r + 1][C - 1];
	}

	for (int r = airConditional[1] + 1; r < R - 1; ++r) {
		room[r][0] = (r == R - 2) ? tempRooms[1] : room[r + 1][0];
	}

	for (int r = R - 1; r > airConditional[1]; --r) {
		room[r][C - 1] = (r == airConditional[1] + 1) ? tempRooms[3] : room[r - 1][C - 1];
	}
}

void activateAirconditional() {
	spreadingDust();
	airCirculation();
}

int main() {
	cin >> R >> C >> T;

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> room[r][c];
			if (room[r][c] == -1) {
				airConditional.push_back(r);
			}
		}
	}

	while (T--) {
		activateAirconditional();
	}

	int dustAmount = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (room[r][c] > 0) {
				dustAmount += room[r][c];
			}
		}
	}

	cout << dustAmount;
}