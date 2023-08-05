#include <iostream>

#define MAX_COST 10000001

using namespace std;

int numOfCity = 0, numOfBus = 0;
int busCost[100][100];

int main() {
	cin >> numOfCity >> numOfBus;
	for (int i = 0; i < numOfCity; ++i) {
		for (int j = 0; j < numOfCity; ++j) {
			if (i == j) busCost[i][j] = 0;
			else busCost[i][j] = MAX_COST;
		}
	}

	for (int i = 0; i < numOfBus; ++i) {
		int origin = 0, destination = 0, cost = 0;
		cin >> origin >> destination >> cost;

		busCost[origin - 1][destination - 1] = min(busCost[origin - 1][destination - 1], cost);
	}

	for (int waypoint = 0; waypoint < numOfCity; ++waypoint) {
		for (int origin = 0; origin < numOfCity; ++origin) {
			for (int destination = 0; destination < numOfCity; ++destination) {
				busCost[origin][destination] = min(busCost[origin][destination], busCost[origin][waypoint] + busCost[waypoint][destination]);
			}
		}
	}

	for (int origin = 0; origin < numOfCity; ++origin) {
		for (int destination = 0; destination < numOfCity; ++destination) {
			int cost = busCost[origin][destination];
			if (cost == MAX_COST) cost = 0;
			cout << cost << " ";
		}
		cout << "\n";
	}
}