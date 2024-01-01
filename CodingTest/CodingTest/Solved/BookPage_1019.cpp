#include <iostream>

using namespace std;

int N;
int ten[11];
int ans[10];

int CountNum(int target, int digit, int num) {
	int ret = 0;

	int mult = target / ten[digit + 1];
	if (num == 0 && mult == 0) return 0;

	ret += mult * ten[digit];

	int last = target / ten[digit] % 10;
	if (last == num) {
		ret += target % ten[digit] + 1;
	}
	else if (last > num) {
		ret += ten[digit];
	}

	if (num == 0) ret -= ten[digit];
	return ret;
}

int main() {
	cin >> N;

	ten[0] = 1;
	for (int i = 1; i < 11; ++i) {
		ten[i] = ten[i - 1] * 10;
	}

	int digit = 0;
	while(ten[digit] <= N) {
		for (int i = 0; i < 10; ++i) {
			ans[i] += CountNum(N, digit, i);
		}
		digit++;
	}
	
	for (const int& count : ans) {
		cout << count << " ";
	}
}