#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> planets[3];
vector<pair<int, pii>> tunnels;

int numOfPlanets = 0;
int parent[100000];
int minCost = 0;

int getParent(int self) {
	if (self == parent[self]) return self;
	return parent[self] = getParent(parent[self]);
}

void unionGroup(int c1, int c2) {
	c1 = getParent(c1);
	c2 = getParent(c2);

	if (c1 != c2) {
		if (c1 < c2) {
			parent[c2] = c1;
		}
		else {
			parent[c1] = c2;
		}
	}
}

bool isSameGroup(int c1, int c2) {
	return getParent(c1) == getParent(c2);
}

int main() {
	cin >> numOfPlanets;

	for (int i = 0; i < numOfPlanets; ++i) {
		int x, y, z;
		cin >> x >> y >> z;

		planets[0].push_back({ x, i });
		planets[1].push_back({ y, i });
		planets[2].push_back({ z, i });
		parent[i] = i;
	}

	sort(planets[0].begin(), planets[0].end());
	sort(planets[1].begin(), planets[1].end());
	sort(planets[2].begin(), planets[2].end());

	for (int i = 0; i < numOfPlanets - 1; ++i) {
		tunnels.push_back(make_pair(abs(planets[0][i + 1].first - planets[0][i].first), make_pair(planets[0][i].second, planets[0][i + 1].second)));
		tunnels.push_back(make_pair(abs(planets[1][i + 1].first - planets[1][i].first), make_pair(planets[1][i].second, planets[1][i + 1].second)));
		tunnels.push_back(make_pair(abs(planets[2][i + 1].first - planets[2][i].first), make_pair(planets[2][i].second, planets[2][i + 1].second)));
	}

	sort(tunnels.begin(), tunnels.end());

	for (int i = 0; i < tunnels.size(); ++i) {
		if (!isSameGroup(tunnels[i].second.first, tunnels[i].second.second)) {
			unionGroup(tunnels[i].second.first, tunnels[i].second.second);
			minCost += tunnels[i].first;
		}
	}

	cout << minCost;
}