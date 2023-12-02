#include <iostream>

using namespace std;

int Fibonacci(int n_1, int n_2, int cycle) {
	if (cycle == 0) return 0;
	else if (cycle == 1) return n_2;
	return Fibonacci(n_2, n_1 + n_2, --cycle);
}

int main() {
	int cycle;
	cin >> cycle;

	cout << Fibonacci(0, 1, cycle);

	return 0;
}