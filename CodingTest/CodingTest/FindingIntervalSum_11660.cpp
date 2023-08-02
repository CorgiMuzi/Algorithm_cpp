#include <iostream>

using namespace std;

int table[1025][1025];
int N = 0, M = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			cin >> table[r][c];
			table[r][c] += (table[r - 1][c] + table[r][c - 1] - table[r - 1][c - 1]);
		}
	}

	for (int test_case = 0; test_case < M; ++test_case) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		cout << table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1] << "\n";
	}
}