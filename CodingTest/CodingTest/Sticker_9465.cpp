#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> scores[2];
vector<int> stickers[2];

int main() {
	int T = 0;
	cin >> T;

	while (T--) {
		int N = 0;
		cin >> N;

		
		for (int i = 0; i < 2; ++i) {
			scores[i] = vector<int>(N, 0);
			stickers[i] = vector<int>(N, 0);

			for (int j = 0; j < N; ++j) {
				cin >> stickers[i][j];
			}
		}

		scores[0][0] = stickers[0][0];
		scores[1][0] = stickers[1][0];
		scores[0][1] = scores[1][0] + stickers[0][1];
		scores[1][1] = scores[0][0] + stickers[1][1];

		for (int i = 2; i < N; ++i) {
			scores[0][i] = max(scores[1][i - 2], scores[1][i - 1]) + stickers[0][i];
			scores[1][i] = max(scores[0][i - 2], scores[0][i - 1]) + stickers[1][i];
		}

		int max_score = max(scores[0][N - 1], scores[0][N - 2]);
		max_score = max(max_score, scores[1][N - 1]);
		max_score = max(max_score, scores[1][N - 2]);

		cout << max_score << "\n";
	}
}