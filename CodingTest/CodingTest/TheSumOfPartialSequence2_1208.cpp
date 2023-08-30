#include <iostream>

using namespace std;

int N = 0, S = 0;
long long cnt = 0;
int sequence[41];
int partialSum[6000001];

void leftGroup(int mid, int sum) {
	if (mid == N / 2) {
		partialSum[sum + 2000000]++;
		return;
	}

	leftGroup(mid + 1, sum + sequence[mid]);
	leftGroup(mid + 1, sum);
}

void rightGroup(int mid, int sum) {
	if (mid == N) {
		cnt += partialSum[S - sum + 2000000];
		return;
	}

	rightGroup(mid + 1, sum + sequence[mid]);
	rightGroup(mid + 1, sum);
}


int main() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> sequence[i];
	}

	leftGroup(0, 0);
	rightGroup(N/2, 0);	

	cout << ((S == 0) ? cnt - 1 : cnt);
}