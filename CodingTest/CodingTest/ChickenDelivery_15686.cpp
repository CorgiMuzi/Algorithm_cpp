#include <iostream>
#include <vector>

using namespace std;

int N = 0, M = 0;
int city[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<vector<int>> houseToChickenDist;

int calcDist(const pair<int, int>& p1, const pair<int, int>& p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void calcChickenDist() {
	typedef vector<pair<int, int>>::size_type vpii_sz;

	for (vpii_sz i = 0; i < house.size(); ++i) {
		vector<int> dist(chicken.size());
		for (vpii_sz j = 0; j < chicken.size(); ++j) {
			 dist[j] = calcDist(house[i], chicken[j]);
		}
		houseToChickenDist.push_back(dist);
	}
}

void closingChickenHouse(int stack, int cur) {
	if (stack == M) {
		
	}

	for (int i = cur; i < chicken.size(); ++i) {

	}
}

int main() {
	cin >> N >> M;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> city[r][c];
			if (city[r][c] == 1) {
				house.push_back(make_pair(r, c));
			}
			else if (city[r][c] == 2) {
				chicken.push_back(make_pair(r, c));
			}
		}
	}
	
	calcChickenDist();

	cout << "------------------\n";
	for (const auto& elem : chickenDist) {
		for (const auto& dist : elem) {
			cout << dist << " ";
		}
		cout << "\n";
	}
}