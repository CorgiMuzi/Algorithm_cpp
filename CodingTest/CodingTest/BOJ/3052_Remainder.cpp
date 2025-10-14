#include <iostream>

using namespace std;

int remainders[42] = { 0, };

int main() {
	for (int i = 0; i < 10; ++i) {
		int target = 0;
		cin >> target;

		remainders[target % 42]++;
	}

	int ans = 0;
	for (int i = 0; i < 42; ++i) {
		if (remainders[i] > 0) ans++;
	}

	cout << ans;
}