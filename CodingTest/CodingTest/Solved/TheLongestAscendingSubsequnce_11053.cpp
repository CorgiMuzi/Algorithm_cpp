#include <iostream>

using namespace std;

int sizeOfSequence = 0;
int sequence[1000] = { 0, }, subsequence[1000] = { 0, };

int main() {
	cin >> sizeOfSequence;

	for (int unit = 0; unit < sizeOfSequence; ++unit) {
		cin >> sequence[unit];
		subsequence[unit] = 1;
	}

	int ans = 1;
	for (int i = 1; i < sizeOfSequence; ++i) {
		int maxLen = 0;
		for (int j = 0; j < i; ++j) {
			if (sequence[j] < sequence[i] && maxLen < subsequence[j]) {
				maxLen = subsequence[j];
			}
		}

		subsequence[i] = maxLen + 1;
		ans = max(ans, subsequence[i]);
	}

	cout << ans;
}