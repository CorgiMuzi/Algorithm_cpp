#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N = 0;
int sequence[1001];
int seqValue[1001][2];

int getBitonicLength() {
	int left = 2, right = N - 1;
	while (left <= N) {
		int currentValue = -1;
		for (int i = 1; i <= left; ++i) {
			if (sequence[i] < sequence[left] && seqValue[i][0] > currentValue) {
				currentValue = seqValue[i][0];
			}
		}
		seqValue[left++][0] = currentValue + 1;
	}

	while (right >= 1) {
		int currentValue = -1;
		for (int i = N; i >= right; --i) {
			if (sequence[i] < sequence[right] && seqValue[i][1] > currentValue) {
				currentValue = seqValue[i][1];
			}
		}
		seqValue[right--][1] = currentValue + 1;
	}

	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		ret = max(ret, seqValue[i][0] + seqValue[i][1]);
	}

	return ret + 1;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> sequence[i];
	}

	seqValue[1][0] = 0;
	seqValue[N][1] = 0;
	
	int ans = getBitonicLength();

	cout << ans;
}