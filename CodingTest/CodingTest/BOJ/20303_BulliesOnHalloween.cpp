#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
int candies[30001];
int parent[30001];
int cries[30001];

int GetParent(int self) {
	if (self == parent[self]) return self;
	return parent[self] = GetParent(parent[self]);
}

void Union(int p1, int p2) {
	p1 = GetParent(p1);
	p2 = GetParent(p2);

	if (p1 != p2) {
		if (p1 > p2) swap(p1, p2);
		parent[p2] = p1;
		candies[p1] += candies[p2];
		cries[p1] += cries[p2];
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> candies[i];
		cries[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int c1, c2;
		cin >> c1 >> c2;
		Union(c1, c2);
	}

	vector<pii> targets;
	vector<int> used(N + 1, false);
	for (int i = 1; i <= N; ++i) {
		int p = GetParent(i);
		if (used[p]) continue;
		targets.emplace_back(cries[p], candies[p]);
		used[p] = true;
	}

	vector<int> bag(K, 0);
	int ans = 0;
	for (const pii& t : targets) {
		for (int i = K - 1; i >= t.first; --i) {
			bag[i] = max(bag[i], bag[i - t.first] + t.second);
			ans = max(ans, bag[i]);
		}
	}

	cout << ans;
}