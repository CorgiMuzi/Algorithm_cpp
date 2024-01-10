#include <iostream>

using namespace std;

int N = 0, K = 0;
int pos[100001];

void hideAndSeek() {
	for (int i = 0; i <= N; ++i) {
		pos[i] = N - i;
	}

	if (K <= N) return;

	for (int sb = N + 1; sb <= K; ++sb) {
		if (sb % 2 == 0) {
			pos[sb] = min(pos[sb - 1] + 1, pos[sb / 2]);
		}
		else {
			pos[sb] = min(pos[sb - 1] + 1, pos[(sb + 1) / 2] + 1);
		}
	}
}

int main() {
	cin >> N >> K;

	hideAndSeek();

	cout << pos[K];
}