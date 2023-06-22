#include <iostream>

using namespace std;

int main() {
	int first = 0, second = 0, third = 0;

	cin >> first >> second >> third;

	if (first == second && second == third) {
		cout << (10000 + first * 1000);
	}
	else {
		if (first == second || first == third) {
			cout << (1000 + first * 100);
		}
		else if (second == third) {
			cout << (1000 + second * 100);
		}
		else {
			int maxVal = max(first, second);
			maxVal = max(maxVal, third);

			cout << maxVal * 100;
		}
	}
}