#include <iostream>

using namespace std;

int main() {
	int minNum = 1000000001, maxNum = -1000000001;
	int n = 0;
	cin >> n;
	int num = 0;
	while (n--) {
		cin >> num;

		minNum = min(minNum, num);
		maxNum = max(maxNum, num);
	}

	cout << minNum << " " << maxNum;
}