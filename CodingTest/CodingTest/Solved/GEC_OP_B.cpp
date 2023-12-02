#include <iostream>
#include <cmath>

int main() {
	int x, N;
	std::cin >> x >> N;

	while (N--) {
		if (x % 2 == 0) {
			x = (x / 2) ^ 6;
		}
		else {
			x = (x * 2) ^ 6;
		}
	}

	std::cout << x;
}