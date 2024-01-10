#include <cstdio>

int arr[100001];

int main() {
	int N, T;
	scanf("%d %d", &N, &T);

	arr[0] = 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}

	while (T--) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		printf("%d\n", arr[end] - arr[begin - 1]);
	}
}