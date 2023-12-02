#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numOfCity = 0, numOfBus = 0;
vector<pair<int, int>> busRoute[1001];
int minCost[1001];

void calcMinCost(int start, int end) {
	priority_queue<pair<int, int>> busCost;
	minCost[start] = 0;
	busCost.push(make_pair(-minCost[start], start));

	while (!busCost.empty()) {
		int curCost = -busCost.top().first;
		int curBus = busCost.top().second;
		busCost.pop();

		if (minCost[curBus] < curCost) continue;

		for (vector<pair<int, int>>::size_type stop = 0; stop < busRoute[curBus].size(); ++stop) {
			int nxtCost = curCost + busRoute[curBus][stop].first;
			int nxtBus = busRoute[curBus][stop].second;

			if (nxtCost < minCost[nxtBus]) {
				minCost[nxtBus] = nxtCost;
				busCost.push(make_pair(-minCost[nxtBus], nxtBus));
			}
		}
	}

	cout << minCost[end] << "\n";
}

int main() {
	cin >> numOfCity >> numOfBus;

	for (int stop = 1; stop <= numOfCity; ++stop) {
		minCost[stop] = 100000000;
	}

	for (int bus = 0; bus < numOfBus; ++bus) {
		int departure = 0, destination = 0, cost = 0;
		cin >> departure >> destination >> cost;

		busRoute[departure].push_back(make_pair(cost, destination));
	}

	int departure = 0, destination = 0;
	cin >> departure >> destination;

	calcMinCost(departure, destination);
}