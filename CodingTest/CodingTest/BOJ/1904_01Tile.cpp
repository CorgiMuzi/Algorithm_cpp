#include <iostream>

using namespace std;

int method[1000001];

int main() {
	method[1] = 1;
	method[2] = 2;

	int N = 0;
	cin >> N;
	for (int i = 3; i <= N; ++i) {
		method[i] = (method[i - 1]  + method[i - 2]) % 15746;
	}

	cout << method[N];
}