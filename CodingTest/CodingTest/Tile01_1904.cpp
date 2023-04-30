#include <iostream>
#include <vector>
using namespace std;

int v[1000000];

int main() {
	int N;
	cin >> N;

	v[0] = 1;
	v[1] = 2;
	for (int i = 2; i < N; i++) {
		v[i] = (v[i - 1] + v[i - 2])%15746;
	}

	cout << v[N-1];

	return 0;
}