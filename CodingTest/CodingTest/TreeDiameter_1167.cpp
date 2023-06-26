#include <iostream>
#include <vector>

using namespace std;

int nodes = 0, maxDist = 0, endNode = 0;
vector<vector<pair<int, int>>> edges;
vector<bool> isVisited;

void findDistance(int beg, int dist) {
	if (isVisited[beg]) return;

	isVisited[beg] = true;

	if (maxDist < dist) {
		maxDist = dist;
		endNode = beg;
	}

	for (int i = 0; i < edges[beg].size(); ++i) {
		findDistance(edges[beg][i].first, dist + edges[beg][i].second);
	}
}


int main() {
	cin >> nodes;
	isVisited = vector<bool>(nodes + 1, false);
	edges = vector<vector<pair<int, int>>>(nodes + 1);

	int beg = 0, end = 0, dist = 0;
	for (int i = 0; i < nodes; ++i) {
		cin >> beg;

		while (cin >> end) {
			if (end == -1) break;
			cin >> dist;

			edges[beg].push_back(make_pair(end, dist));
		}
	}

	findDistance(1, 0);
	isVisited = vector<bool>(nodes + 1, false);
	findDistance(endNode, 0);
	cout << maxDist;
}