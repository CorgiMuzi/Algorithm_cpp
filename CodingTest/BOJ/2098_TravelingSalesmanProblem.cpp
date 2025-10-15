#include <iostream>

#define INF 2e9

using namespace std;

int road[16][16];
int trail[16][1 << 16];
int N = 0, finish = 0;

int salesman(int cur, int visited) {
	if (visited == finish) {
		if (road[cur][0] > 0) return road[cur][0];
		return INF;
	}

	if (trail[cur][visited] != 0) return trail[cur][visited];

	trail[cur][visited] = INF;

	for (int next = 0; next < N; ++next) {
		if (road[cur][next] == 0) continue;
		if (visited & (1 << next)) continue;

		int roadCost = salesman(next, visited | 1 << next);
		trail[cur][visited] = min(trail[cur][visited], road[cur][next] + roadCost);
	}

	return trail[cur][visited];
}

int main() {
	cin >> N;
	finish = (1 << N) - 1;

	for (int depart = 0; depart < N; ++depart) {
		for (int arrive = 0; arrive < N; ++arrive) {
			cin >> road[depart][arrive];
		}
	}

	cout << salesman(0, 1	);
}