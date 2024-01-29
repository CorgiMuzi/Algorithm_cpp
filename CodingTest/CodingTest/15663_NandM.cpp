#include <iostream>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
int sequence[8] = { 0 };
int output[8] = { 0 };
bool isUsed[8] = { false };

void subsequence(int cur) {
	if (cur == M) {
		for (int i = 0; i < M; ++i) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}
		
	int lastNum = -1;
	for (int i = 0; i < N; ++i) {
		if (!isUsed[i] && sequence[i] != lastNum) {
			output[cur] = sequence[i];
			lastNum = output[cur];

			isUsed[i] = true;
			subsequence(cur + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> sequence[i];
	}

	sort(sequence, sequence + N);

	subsequence(0);
}