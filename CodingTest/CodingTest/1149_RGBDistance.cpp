#include <cstdio>
#include <algorithm>

using namespace std;

int houseCount = 0;
int paintCost[1001][3], houseCost[1001][3];

int main() {
	scanf("%d", &houseCount);

	for (int i = 1; i <= houseCount; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &paintCost[i][j]);
		}
	}

	for (int i = 1; i <= houseCount; ++i) {
		houseCost[i][0] = min(houseCost[i - 1][1], houseCost[i - 1][2]) + paintCost[i][0];
		houseCost[i][1] = min(houseCost[i - 1][0], houseCost[i - 1][2]) + paintCost[i][1];
		houseCost[i][2] = min(houseCost[i - 1][0], houseCost[i - 1][1]) + paintCost[i][2];
	}

	int minCost = houseCost[houseCount][0];
	if (minCost > houseCost[houseCount][1]) minCost = houseCost[houseCount][1];
	if (minCost > houseCost[houseCount][2]) minCost = houseCost[houseCount][2];

	printf("%d", minCost);
}