#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 300001

using namespace std;

int N = 0, K = 0;
pair<int, int> jewel[MAX];
int bag[MAX];

int main() {
	cin >> N >> K;
	int M = 0, V = 0;
	for (int i = 0; i < N; ++i) {
		cin >> M >> V;
		jewel[i] = make_pair(M, V);
	}

	int C = 0;
	for (int i = 0; i < K; ++i) {
		cin >> bag[i];
	}

	sort(jewel, jewel + N);
	sort(bag, bag + K);

	priority_queue<int> jewelQ;
	long long value = 0;
	int jewelNum = 0;
	for (int i = 0; i < K; ++i) {
		while (jewelNum < N && jewel[jewelNum].first <= bag[i]) {
			jewelQ.push(jewel[jewelNum++].second);
		}

		if (!jewelQ.empty()) {
			value += jewelQ.top();
			jewelQ.pop();
		}
	}

	cout << value;
}