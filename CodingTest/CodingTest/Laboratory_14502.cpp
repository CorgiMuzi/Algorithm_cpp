#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<vector<int>> lab(8, vector<int>(8, 0));
vector<pair<int, int>> virus;
int hDir[4] = { -1, 1, 0, 0 };
int wDir[4] = { 0, 0, -1, 1 };

int infected(vector<vector<int>> l) {
	queue<pair<int, int>> q;
	for (vector<pair<int, int>>::iterator iter = virus.begin(); iter != virus.end(); ++iter) {
		q.push(*iter);
	}

	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		l[v.first][v.second] = 2;

		for (int i = 0; i < 4; ++i) {
			int mh = v.first + hDir[i];
			int mw = v.second + wDir[i];

			if (mh < 0 || mw < 0 || mh >= N || mw >= M || l[mh][mw] != 0) continue;

			q.push(make_pair(mh, mw));
		}
	}

	int ret = 0;
	for (int r = 0; r < N; ++r) {
		ret += count(l[r].begin(), l[r].begin() + M, 0);
	}
	
	return ret;
}

int settingWalls() {
	int ret = 0;
	for (int r1 = 0; r1 < N; ++r1) {
		for (int c1 = 0; c1 < M; ++c1) {
			if (lab[r1][c1] != 0) continue;
			lab[r1][c1] = 1;

			for (int r2 = r1; r2 < N; ++r2) {
				for (int c2 = 0; c2 < M; ++c2) {
					if (lab[r2][c2] != 0) continue;
					lab[r2][c2] = 1;

					for (int r3 = r2; r3 < N; ++r3) {
						for (int c3 = 0; c3 < M; ++c3) {
							if (lab[r3][c3] != 0) continue;
							lab[r3][c3] = 1;
							ret = max(ret, infected(lab));
							lab[r3][c3] = 0;
						}
					}
					lab[r2][c2] = 0;
				}
			}
			lab[r1][c1] = 0;
		}
	}

	return ret;
}

int main() {
	cin >> N >> M;

	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			cin >> lab[row][col];
			if (lab[row][col] == 2) {
				virus.push_back(make_pair(row, col));
			}
		}
	}

	int ans = settingWalls();
	cout << ans;
}

//#include <stdio.h>
//
//int arr[10][10];
//int arr2[10][10];
//int virus[64][2];
//int num;
//int n, m;
//
//int xx[4] = { 0,0,-1,1 };
//int yy[4] = { 1,-1,0,0 };
//
//void dfs(int x, int y) {
//	for (int i = 0; i < 4; i++) {
//		int X = x + xx[i];
//		int Y = y + yy[i];
//
//		if (X > 0 && X <= n && Y > 0 && Y <= m && !arr2[X][Y]) {
//			arr2[X][Y] = 2;
//			dfs(X, Y);
//		}
//	}
//
//	return;
//}
//
//int main() {
//	int x1, x2, x3, y1, y2, y3;
//	int ans = 0;
//
//	scanf("%d %d", &n, &m);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			scanf("%d", &arr[i][j]);
//			arr2[i][j] = arr[i][j];
//
//			if (arr[i][j] == 2) {
//				virus[num][0] = i;
//				virus[num][1] = j;
//				num++;
//			}
//		}
//
//	for (int i = 0; i < n * m; i++) {
//		x1 = i / m + 1; y1 = i % m + 1;
//		if (!arr2[x1][y1])
//			for (int j = i + 1; j < n * m; j++) {
//				x2 = j / m + 1; y2 = j % m + 1;
//				if (!arr2[x2][y2])
//					for (int k = j + 1; k < n * m; k++) {
//						x3 = k / m + 1; y3 = k % m + 1;
//						if (!arr2[x3][y3]) {
//							arr2[x1][y1] = 1;
//							arr2[x2][y2] = 1;
//							arr2[x3][y3] = 1;
//
//							for (int p = 0; p < num; p++)
//								dfs(virus[p][0], virus[p][1]);
//
//							int cnt = 0;
//
//							for (int p = 1; p <= n; p++)
//								for (int q = 1; q <= m; q++)
//									if (!arr2[p][q]) cnt++;
//
//							if (ans < cnt)
//								ans = cnt;
//
//							for (int p = 1; p <= n; p++)
//								for (int q = 1; q <= m; q++)
//									arr2[p][q] = arr[p][q];
//						}
//					}
//			}
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}