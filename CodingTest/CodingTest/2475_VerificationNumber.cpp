#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int sum = 0;
	int num = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> num;
		sum += (num * num);
	}
	cout << sum % 10;
}