#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int sum = n;

	while (n--) {
		sum += n;
	}
	printf("%d", sum);
}