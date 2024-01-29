#include <cstdio>

int baskets[100]= { 0 };

int main() {
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int beg = 0, end = 0, ball = 0;
		scanf("%d %d %d", &beg, &end, &ball);

		for (int j = beg; j <= end; ++j) {
			baskets[j] = ball;
		}
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", baskets[i]);
	}
}