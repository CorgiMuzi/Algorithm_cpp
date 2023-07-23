#include <iostream>

using namespace std;

int digits[10] = { 0 };

int main() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	int mul = a * b * c;

	while (mul) {
		digits[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		cout << digits[i] << "\n";
	}
}