#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M;
pii brand[51];
int cost;

bool Package(const pii& left, const pii& right);
bool Single(const pii& left, const pii& right);

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> brand[i].first >> brand[i].second;
	}

	sort(brand, brand + M, Package);
	int remainders = N % 6;
	int coin = (N / 6) * brand[0].first;
	if(remainders > 0) coin += brand[0].first;

	cost = coin;
	coin -= brand[0].first;
	
	sort(brand, brand + M, Single);

	if(remainders > 0) {
		coin += (remainders * brand[0].second);

		cost = min(cost, coin);
	}

	cost = min(cost, N * brand[0].second);

	cout << cost;
}

bool Package(const pii& left, const pii& right) {
	return left.first < right.first;
}

bool Single(const pii& left, const pii& right) {
	return left.second < right.second;
}