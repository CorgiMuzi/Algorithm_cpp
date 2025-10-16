#include <iostream>

int Factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * Factorial(n - 1);
}

int main() {

	int N;
	std::cin >> N;

	std::cout << Factorial(N);

	return 0;
}