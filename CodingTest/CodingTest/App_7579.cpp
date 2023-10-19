#include <iostream>

using namespace std;

int N = 0, M = 0, maxCost = 0;
int memory[101] = {0}, cost[101] = {10001}, gc[101][10001];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> memory[i];
	}

	for (int i = 1; i <= N; ++i) {
		cin >> cost[i];
		maxCost += cost[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= maxCost; ++j) {
			if (j - cost[i] >= 0) {
				gc[i][j] = max(gc[i][j], gc[i - 1][j - cost[i]] + memory[i]);
			}

			gc[i][j] = max(gc[i][j], gc[i - 1][j]);
		}
	}

	for (int i = 0; i <= maxCost; ++i) {
		if (gc[N][i] >= M) {
			cout << i << "\n";
			break;
		}
	}
}