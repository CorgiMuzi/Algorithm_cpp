#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int minCost[1001];
int busRoute[1001];
vector<pair<int, int>> busCost[1001];
int numOfCity = 0, numOfBus = 0;

void dijkstra(int start) {
	priority_queue<pair<int, int>> route;
	route.push({ 0, start });
	minCost[start] = 0;

	while (!route.empty()) {
		int cost = -route.top().first;
		int curRoute = route.top().second;
		route.pop();

		if (cost > minCost[curRoute]) continue;

		for (int i = 0; i < busCost[curRoute].size(); ++i) {
			int dest = busCost[curRoute][i].first;
			int routeCost = cost + busCost[curRoute][i].second;

			if (minCost[dest] > routeCost) {
				minCost[dest] = routeCost;
				route.push({ -minCost[dest], dest });
				busRoute[dest] = curRoute;
			}
		}
	}
}

int main() {
	cin >> numOfCity >> numOfBus;

	for (int i = 1; i <= numOfCity; ++i) {
		minCost[i] = INF;
	}

	for (int i = 0; i < numOfBus; ++i) {
		int dept = 0, dest = 0, cost = 0;
		cin >> dept >> dest >> cost;
		busCost[dept].push_back({ dest, cost });
	}

	int departure = 0, destination = 0;
	cin >> departure >> destination;

	dijkstra(departure);

	cout << minCost[destination] << "\n";

	vector<int> trail;
	int point = destination;
	while (point != 0) {
		trail.push_back(point);
		point = busRoute[point];
	}

	cout << trail.size() << "\n";

	for (vector<int>::reverse_iterator stop = trail.rbegin(); stop != trail.rend(); ++stop) {
		cout << *stop << " ";
	}
}