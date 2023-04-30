#include <iostream>
#include <unordered_map>

int main() {
	int N, M;
	scanf("%d", &N);
	std::unordered_map<int, int> uoMap(N);
	int inputValue;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &inputValue);
		++uoMap[inputValue];
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &inputValue);
		printf("%d ", uoMap[inputValue]);
	}
	return 0;
}