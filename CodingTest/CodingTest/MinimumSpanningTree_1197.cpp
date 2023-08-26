#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int V = 0, E = 0, W = 0;
int A = 0, B = 0, C = 0;
vector<pair<int, pii>> graph;
int parent[10001];

int getParent(const int& node) {
	if (parent[node] == node) return node;

	return getParent(parent[node]);
}

bool unionNode(const int& node1, const int& node2) {
	int p1 = getParent(node1);
	int p2 = getParent(node2);

	if (p1 != p2) {
		parent[p2] = p1;
		return true;
	}

	return false;
}

int main() {
	cin >> V >> E;
		
	for (int node = 1; node <= V; ++node) {
		parent[node] = node;
	}

	for (int i = 0; i < E; ++i) {
		cin >> A >> B >> C;
		graph.push_back(make_pair(C, make_pair(A, B)));
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < E; ++i) {
		if (unionNode(graph[i].second.first, graph[i].second.second)) {
			W += graph[i].first;
		}
	}

	cout << W;
}