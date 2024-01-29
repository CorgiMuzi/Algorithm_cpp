#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::vector, std::sort;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end(), std::greater<int>());

	int charge = K;
	int coin_count = 0;
	for (int i = 0; i < coins.size(); ++i) {
		if (coins[i] > charge) continue;

		coin_count += (charge / coins[i]);
		charge = charge % coins[i];

		if (charge == 0) break;
	}

	cout << coin_count;
}