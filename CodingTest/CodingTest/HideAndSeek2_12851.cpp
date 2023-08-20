#include <iostream>

using namespace std;

int N = 0, K = 0;
pair<int, int> map[100002];

void hideAndSeek() {
	for (int i = 0; i <= N; ++i) {
		map[i] = make_pair(N - i, 1);
	}

	for (int sb = N + 1; sb <= K; ++sb) {
		pair<int, int> forward = make_pair(map[sb - 1].first + 1, map[sb - 1].second);

		if (sb % 2 == 0) {
			pair<int, int> jump = make_pair(map[sb / 2].first + 1, map[sb / 2].second);

			if (forward.first < jump.first) {
				map[sb] = forward;
			}
			else if (forward.first > jump.first) {
				map[sb] = jump;
			}
			else {
				map[sb] = make_pair(forward.first, map[sb - 1].second + map[sb / 2].second);
			}
		}
		else {
			pair<int, int> jump = make_pair(map[(sb + 1) / 2].first + 2, map[(sb + 1) / 2].second);

			if (forward.first < jump.first) {
				map[sb] = forward;
			}
			else if (forward.first > jump.first) {
				map[sb] = jump;
			}
			else {
				map[sb] = make_pair(forward.first, forward.second + jump.second);
			}
		}
	}
}

int main() {
	cin >> N >> K;

	hideAndSeek();

	cout << map[K].first << "\n";
	cout << map[K].second;
}