#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int count = 0;
	for (int i = 5; i <= N; i *= 5) {
		count += (N / i);
	}

	std::cout << count;
}