#include <cstdio>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	int ans = a * b;
	while (b != 0) {
		printf("%d\n", a * (b % 10));
		b /= 10;
	}

	printf("%d", ans);
}