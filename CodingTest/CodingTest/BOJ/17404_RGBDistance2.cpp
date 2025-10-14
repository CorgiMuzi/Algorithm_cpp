#include <iostream>

using namespace std;

enum COLOR {
	RED = 0,
	GREEN,
	BLUE,
	MAX_VAL
};

const int MAX_COST = 1'000'001;
int N;
int house[1000][3];
int minCost = MAX_COST;

int main() {
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> house[i][RED] >> house[i][GREEN] >> house[i][BLUE];
	}

	for(int i = 0; i < MAX_VAL; ++i) {
		int cost[1000][3];
		for(int j = 0; j < MAX_VAL; ++j) {
			cost[0][j] = i == j ? house[0][j] : MAX_COST;
		}
		
		for(int j = 1; j < N; ++j) {
			cost[j][RED] = min(cost[j - 1][GREEN], cost[j - 1][BLUE]) + house[j][RED];
			cost[j][GREEN] = min(cost[j - 1][RED], cost[j - 1][BLUE]) + house[j][GREEN];
			cost[j][BLUE] = min(cost[j - 1][RED], cost[j - 1][GREEN]) + house[j][BLUE];
		}

		for(int j = 0; j < MAX_VAL; ++j) {
			if(i == j) continue;
			minCost = min(minCost, cost[N - 1][j]);
		}
	}
	
	cout << minCost;
}