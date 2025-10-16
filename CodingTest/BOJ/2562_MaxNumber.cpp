#include <iostream>

using namespace std;

int main() {
	int max = 0, num = 0, maxNum = 0;
	for (int i = 1; i <= 9; ++i) {
		cin >> num;
		if (maxNum < num) {
			maxNum = num;
			max = i;
		}
	}

	cout << maxNum << '\n' << max;
}