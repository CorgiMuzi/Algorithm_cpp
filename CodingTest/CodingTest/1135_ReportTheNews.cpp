#include <iostream>
#include <algorithm>

using namespace std;

int N;
int boss[51];

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	fill_n(boss, N, 0);
	for(int i = 1; i < N; ++i) {
		cin >> boss[i];
	}
}