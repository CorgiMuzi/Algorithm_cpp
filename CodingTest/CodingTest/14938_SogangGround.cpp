#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_LEN 16

using namespace std;

vector<pair<int, int>> field[101];
int items[101] = { 0 };
int dist[101] = { MAX_LEN };

// 지역 갯수, 수색 범위, 간선 갯수
int n = 0, m = 0, r = 0;

void dijkstra(int start) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = MAX_LEN;
	}

	bool isVisited[101] = { false };

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push(make_pair(dist[start], start));

	while (!pq.empty()) {
		int len = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (!isVisited[cur_node]) {
			isVisited[cur_node] = true;

			for (vector<pair<int, int>>::iterator next_node = field[cur_node].begin(); next_node != field[cur_node].end(); ++next_node) {
				if (dist[next_node->first] > len + next_node->second) {
					dist[next_node->first] = len + next_node->second;
					pq.push(make_pair(dist[next_node->first], next_node->first));
				}
			}
		}
	}

}

int main() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i) {
		cin >> items[i];
	}

	for (int i = 0; i < r; ++i) {
		int beg = 0, end = 0, len = 0;
		cin >> beg >> end >> len;
		field[beg].push_back(make_pair(end, len));
		field[end].push_back(make_pair(beg, len));
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
		int item = 0;
		for (int j = 1; j <= n; ++j) {
			if (dist[j] <= m) item += items[j];
		}
		ans = max(ans, item);
	}

	cout << ans;
}