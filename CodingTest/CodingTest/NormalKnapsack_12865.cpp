#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numOfStuff = 0, junW = 0;
pair<int, int> stuff[100];
pair<int, vector<int>> knapsack[100001];

int main() {
	cin >> numOfStuff >> junW;

	int stuffW = 0, stuffV = 0;
	for (int i = 0; i < numOfStuff; ++i) {
		cin >> stuffW >> stuffV;

		stuff[i] = make_pair(stuffW, stuffV);
	}

	knapsack[0] = { 0, vector<int>() };
	for (int i = 1; i <= junW; ++i) {
		for (int j = 0; j < numOfStuff; ++j) {
			if (stuff[j].first <= i) {
				if (find(knapsack[i - stuff[j].first].second.begin(), knapsack[i - stuff[j].first].second.end(), j) != knapsack[i - stuff[j].first].second.end()) continue;
				if (knapsack[i].first < knapsack[i - stuff[j].first].first + stuff[j].second) {
					knapsack[i].first = knapsack[i - stuff[j].first].first + stuff[j].second;
					knapsack[i].second = knapsack[i - stuff[j].first].second;
					knapsack[i].second.push_back(j);
				}
			}
		}
	}

	int maxW = 0;
	for (int i = 1; i <= junW; ++i) {
		maxW = max(maxW, knapsack[i].first);
	}
	cout << maxW;
}