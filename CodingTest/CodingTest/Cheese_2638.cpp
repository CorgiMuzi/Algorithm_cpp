#include <iostream>
#include <queue>

using namespace std;

int N = 0, M = 0, elapsedTime = 0;
int room[101][101];
int rDir[4] = { -1, 1, 0, 0 };
int cDir[4] = { 0, 0, -1, 1 };
bool isVisit[101][101];

void meltingCheese(const vector<pair<int, int>>& start) {
	if (start.empty()) return;
	queue<pair<int, int>> outside;
	for (vector<pair<int, int>>::const_iterator s = start.begin(); s != start.end(); ++s) {
		outside.push(*s);
	}

	vector<pair<int, int>> newOutside;
	while (!outside.empty()) {
		int cur_row = outside.front().first, cur_col = outside.front().second;
		outside.pop();

		if (room[cur_row][cur_col] == 0) isVisit[cur_row][cur_col] = true;


		for (int dir = 0; dir < 4; ++dir) {
			int m_row = cur_row + rDir[dir], m_col = cur_col + cDir[dir];

			if (m_row < 0 || m_col < 0 || m_row >= N || m_col >= M || isVisit[m_row][m_col]) continue;

			if (room[m_row][m_col] > 0) {
				room[m_row][m_col]++;
			}
			outside.push(make_pair(m_row, m_col));

		}
	}

	elapsedTime++;

	meltingCheese(newOutside);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << room[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> N >> M;

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> room[r][c];
		}
	}

	memset(isVisit, 0, sizeof(isVisit));
	isVisit[0][0] = true;
	isVisit[N - 1][0] = true;
	isVisit[0][M - 1] = true;
	isVisit[N - 1][M - 1] = true;

	vector<pair<int, int>> corners;
	corners.push_back(make_pair(0, 0));
	corners.push_back(make_pair(N - 1, 0));
	corners.push_back(make_pair(0, M - 1));
	corners.push_back(make_pair(N - 1, M - 1));

	meltingCheese(corners);

	cout << elapsedTime;
}