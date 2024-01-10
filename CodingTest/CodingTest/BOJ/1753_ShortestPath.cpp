#include <iostream>
#include <vector>
#include <queue>

#define INF 200001

using namespace std;

int V = 0, E = 0, K = 0;
vector<pair<int, int>> edges[20001];
int dist[20001];

void dijkstra(int start) {
	for (int i = 1; i <= V; ++i) dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>> trail;
	trail.push(make_pair(0, start));

	while (!trail.empty()) {
		int curDist = -trail.top().first;
		int curNode = trail.top().second;

		trail.pop();

		if (curDist < dist[curNode]) continue;

		for (vector<pair<int, int>>::size_type i = 0; i < edges[curNode].size(); ++i) {
			int nxtDist = edges[curNode][i].first + curDist;
			int nxtNode = edges[curNode][i].second;

			if (nxtDist < dist[nxtNode]) {
				dist[nxtNode] = nxtDist;
				trail.push(make_pair(-dist[nxtNode], nxtNode));
			}
		}
	}
}

int main(){
	cin >> V >> E >> K;

	for (int i = 0; i < E; ++i) {
		int beg = 0, end = 0, w = 0;
		cin >> beg >> end >> w;

		edges[beg].push_back(make_pair(w, end));
	}

	dijkstra(K);

	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}