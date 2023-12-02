#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_DIST 101

using namespace std;

int city_size = 0, max_shop = 0, chicken_dist = MAX_DIST * 13;
vector<pair<int, int>> house, shop;
vector<vector<int>> dist;

void calcChickenDist(int open, int last) {
	if (open == max_shop) {
		int ret = 0;
		for (vector<vector<int>>::iterator iter = dist.begin(); iter != dist.end(); ++iter) {
			ret += *min_element(iter->begin(), iter->end());
		}
		
		chicken_dist = min(ret, chicken_dist);
		return;
	}

	for (vector<vector<int>>::size_type i = last; i < shop.size(); ++i) {
		for (vector<int>::size_type j = 0; j < house.size(); ++j) {
			dist[j][i] += MAX_DIST;
		}

		calcChickenDist(open - 1, i + 1);

		for (vector<int>::size_type j = 0; j < house.size(); ++j) {
			dist[j][i] -= MAX_DIST;
		}
	}
}

int main() {
	cin >> city_size >> max_shop;

	for (int r = 0; r < city_size; ++r) {
		for (int c = 0; c < city_size; ++c) {
			int value = 0;
			cin >> value;
			if (value == 1) {
				house.push_back(make_pair(r, c));
			}
			else if (value == 2) {
				shop.push_back(make_pair(r, c));
			}
		}
	}

	dist = vector<vector<int>>(house.size(), vector<int>(shop.size()));

	for (vector<vector<int>>::size_type i = 0; i < house.size(); ++i) {
		for (vector<int>::size_type j = 0; j < shop.size(); ++j) {
			dist[i][j] = abs(house[i].first - shop[j].first) + abs(house[i].second - shop[j].second);
		}
	}

	calcChickenDist(shop.size(), 0);

	cout << chicken_dist;
}