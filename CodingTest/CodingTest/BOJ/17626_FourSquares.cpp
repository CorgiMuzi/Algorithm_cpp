#include <iostream>

using namespace std;

int squares[50001];

int main() {
	int target;
	cin >> target;

	squares[0] = 0;
	squares[1] = 1;

	for (int i = 2; i <= target; ++i) {
		int expression = 50001;
		for (int j = 1; j * j <= i; ++j) {
			int pos = i - j * j;
			expression = min(expression, squares[pos]);
		}
		squares[i] = expression + 1;
	}

	cout << squares[target];
}