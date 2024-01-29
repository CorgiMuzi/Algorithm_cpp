#include <cstdio>

int tileFiling[1001];

long long tiling(int N) {
	long long ret;
	const int divisor = 10007;
	tileFiling[1] = 1;
	tileFiling[2] = 2;
	for (int i = 3; i <= N; ++i) {
		tileFiling[i] = (tileFiling[i -  2] + tileFiling[i - 1]) % divisor;
	}

	ret = tileFiling[N];

	return ret;
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%lld", tiling(N));
}