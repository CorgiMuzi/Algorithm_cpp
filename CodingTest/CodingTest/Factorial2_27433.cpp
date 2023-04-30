#include <cstdio>

long long Factorial(int N) {
	if (N == 0) return 1;
	else return N * Factorial(N - 1);
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%lld", Factorial(N));
}