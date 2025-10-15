#include <iostream>

using namespace std;

int N, K;
int a, b = 0;

int CountBits(int num);

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	int a = CountBits(N);
	while(a > K) {
		b++;
		N++;
		a = CountBits(N);
	}

	cout << b;
}

int CountBits(int num) {
	int ret = 0;
	while(num > 0) {
		if(num % 2 == 1) ret++;
		num /= 2;
	}

	return ret;
}
