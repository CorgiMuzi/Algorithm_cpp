#include <iostream>
using namespace std;

int N = 0;
int numbers[100][10][1024];

int stairNum(int digit, int num, int bitFlag) {

	if (numbers[digit][num][bitFlag] != 0) return numbers[digit][num][bitFlag];
	if (digit == N - 1) return bitFlag == 1023 ? 1 : 0;

	int combination = 0;
	if (num < 9) combination += stairNum(digit + 1, num + 1, bitFlag | 1 << (num + 1));
	if (num > 0) combination += stairNum(digit + 1, num - 1, bitFlag | 1 << (num - 1));

	return numbers[digit][num][bitFlag] = combination %= 1000000000;
}

int main() {
	cin >> N;

	int ans = 0;
	for (int bit = 1; bit < 10; ++bit) {
		ans += stairNum(0, bit, 1 << bit);
		ans %= 1000000000;
	}

	cout << ans;
}