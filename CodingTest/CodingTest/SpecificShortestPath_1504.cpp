#include <iostream>
#include <vector>
#include <queue>

#define INF 2400000

using namespace std;

typedef pair<int, int> pii;

int N = 0, E = 0;
vector<pii> edges[801];
int elapsedDist[801];

void dijkstra(int beg) {
	for (int i = 1; i <= N; ++i) {
		elapsedDist[i] = INF;
	}
	elapsedDist[beg] = 0;

	priority_queue<pii> trail;
	trail.push(make_pair(0, beg));

	while (!trail.empty()) {
		int curDist = -trail.top().first;
		int curNode = trail.top().second;
		trail.pop();

		if (elapsedDist[curNode] < curDist) continue;

		for (vector<pii>::size_type i = 0; i < edges[curNode].size(); ++i) {
			int nxtDist = edges[curNode][i].first + curDist;
			int nxtNode = edges[curNode][i].second;

			if (nxtDist < elapsedDist[nxtNode]) {
				elapsedDist[nxtNode] = nxtDist;
				trail.push(make_pair(-elapsedDist[nxtNode], nxtNode));
			}
		}
	}
}

int main() {
	cin >> N >> E;

	int beg = 0, end = 0, dist = 0;
	for (int i = 0; i < E; ++i) {
		cin >> beg >> end >> dist;

		edges[beg].push_back(make_pair(dist, end));
		edges[end].push_back(make_pair(dist, beg));
	}

	int u = 0, v = 0;
	cin >> u >> v;

	int begToU = 0, begToV = 0;
	dijkstra(1);
	begToU = elapsedDist[u];
	begToV = elapsedDist[v];

	int uToV = 0, uToN = 0;
	dijkstra(u);
	uToV = elapsedDist[v];
	uToN = elapsedDist[N];

	int vToN = 0;
	dijkstra(v);
	vToN = elapsedDist[N];

	int ans = INF;
	ans = min(ans, begToU + uToV + vToN);
	ans = min(ans, begToV + uToV + uToN);

	cout << (ans >= INF ? -1 : ans);
}