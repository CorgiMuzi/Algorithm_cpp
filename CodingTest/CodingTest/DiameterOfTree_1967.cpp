#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> tree[10001];
bool isVisited[10001] = { false, };
int max_dist = 0, leaf = 0;

void DFS(int root, int dist) {
	if (isVisited[root]) return;

	isVisited[root] = true;

	if (max_dist < dist) {
		max_dist = dist;
		leaf = root;
	}

	for (int i = 0; i < tree[root].size(); ++i) {
		DFS(tree[root][i].first, tree[root][i].second + dist);
	}
}

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int n1 = 0, n2 = 0, weight = 0;
		cin >> n1 >> n2 >> weight;

		tree[n1].push_back({ n2, weight });
		tree[n2].push_back({ n1, weight });
	}

	DFS(1, 0);

	fill(isVisited, isVisited + 10001, false);

	DFS(leaf, 0);

	cout << max_dist;
}