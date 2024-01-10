#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pairCmp {
	bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
		if (left.first == right.first) return left.second < right.second;
		return left.first < right.first;
	}
};

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, pairCmp> pq_pInt;
vector<pair<int, int>> roads[2][1001];
vector<vector<int>> distances(2, vector<int>(1001, 100001));

void move(const int& startNode, const int& isReversed) {
	distances[isReversed][startNode] = 0;
	pq_pInt pq;
	pq.push(make_pair(startNode, distances[isReversed][startNode]));

	while (!pq.empty()) {
		int endNode = pq.top().first;
		int dist = pq.top().second;
		pq.pop();
		
		if (dist > distances[isReversed][endNode]) continue;

		for (int i = 0; i < roads[isReversed][endNode].size(); ++i) {
			int nextNode = roads[isReversed][endNode][i].first;
			int nextDist = dist + roads[isReversed][endNode][i].second;

			if (nextDist < distances[isReversed][nextNode]) {
				distances[isReversed][nextNode] = nextDist;
				pq.push(make_pair(nextNode, nextDist));
			}
		}
	}
}

int main() {
	int N = 0, M = 0, X = 0;
	cin >> N >> M >> X;

	int beg = 0, end = 0, time = 0;
	for (int i = 0; i < M; ++i) {
		cin >> beg >> end >> time;
		
		roads[0][beg].push_back(make_pair(end, time));
		roads[1][end].push_back(make_pair(beg, time));
	}
	move(X, 0);
	move(X, 1);

	int maxDist = 0;
	for (int i = 1; i <= N; ++i) {
		maxDist = max(maxDist, distances[0][i] + distances[1][i]);
	}
	cout << maxDist;
}