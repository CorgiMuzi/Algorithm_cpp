#include <iostream>
using namespace std;

int main() {
	long long edge[100] = { 1, 1, 1, };
	int testTry = 0;
	cin >> testTry;

	for (int i = 0; i < testTry; i++) {
		int N;
		cin >> N;

		if (N < 4) {
			cout << edge[N - 1] << '\n';
		}
		else {
			for (int i = 3; i < N; i++) {
				edge[i] = edge[i - 2] + edge[i - 3];
			}

			cout << edge[N - 1] << '\n';
		}
	}

}