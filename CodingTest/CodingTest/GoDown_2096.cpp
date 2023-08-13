#include <iostream>

using namespace std;

int lines[100000][3] = { 0, };
int numOfLines = 0;

int main() {
	cin >> numOfLines;

	for (int i = 0; i < numOfLines; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> lines[i][j];
		}
	}

	pair<int, int> minMaxPair[3] = { {0, 0}, {0, 0}, {0, 0} };
	for (int r = 0; r < numOfLines; ++r) {
		if (r == 0) {
			for (int i = 0; i < 3; ++i) {
				minMaxPair[i] = { lines[r][i], lines[r][i] };
			}
			continue;
		}
		
		pair<int, int> tempMinMax[3] = { minMaxPair[0], minMaxPair[1], minMaxPair[2] };

		minMaxPair[0].first = min(tempMinMax[0].first, tempMinMax[1].first) + lines[r][0];
		minMaxPair[0].second = max(tempMinMax[0].second, tempMinMax[1].second) + lines[r][0];

		minMaxPair[1].first = min(min(tempMinMax[0].first, tempMinMax[1].first), tempMinMax[2].first) + lines[r][1];
		minMaxPair[1].second = max(max(tempMinMax[0].second, tempMinMax[1].second), tempMinMax[2].second) + lines[r][1];

		minMaxPair[2].first = min(tempMinMax[1].first, tempMinMax[2].first) + lines[r][2];
		minMaxPair[2].second = max(tempMinMax[1].second, tempMinMax[2].second) + lines[r][2];
	}

	int minNum = minMaxPair[0].first, maxNum = minMaxPair[0].second;
	for (int i = 1; i < 3; ++i) {
		minNum = min(minNum, minMaxPair[i].first);
		maxNum = max(maxNum, minMaxPair[i].second);
	}

	cout << maxNum << " " << minNum;
}