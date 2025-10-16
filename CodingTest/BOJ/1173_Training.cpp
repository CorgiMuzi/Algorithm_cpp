#include <iostream>

using namespace std;

int N, m, M, T, R;
int Train = 0, Rest = 0, Pulse = m;

int main() {
	cin >> N >> m >> M >> T >> R;

	Pulse = m;

	if (T > M - m) {
		cout << -1;
		return 0;
	}

	while (Train < N) {
		if (Pulse + T > M) {
			Rest++;
			Pulse -= R;
			if (Pulse < m) Pulse = m;
		}
		else {
			Pulse += T;
			Train++;
		}
	}

	cout << Train + Rest;
}