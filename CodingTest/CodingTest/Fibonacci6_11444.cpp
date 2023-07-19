#include <iostream>
#include <map>

using namespace std;

map<int, int> fib;

long long fibonacci(long long N) { 
	if (fib.find(N) == fib.end()) {
		long long neighbor = 0;
		long long self = fibonacci(N / 2);
		if (N % 2 == 0) {
			neighbor = fibonacci(N / 2 - 1);

			fib[N] = (self * (self + 2 * neighbor)) % 1000000007;
		}
		else {
			neighbor = fibonacci(N / 2 + 1);

			fib[N] = (self * self + neighbor * neighbor) % 1000000007;
		}
	}

	return fib[N];
}

int main() {
	long long N = 0;
	cin >> N;

	fib[0] = 0;
	fib[1] = 1;

	cout << fibonacci(N);
}