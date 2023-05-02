#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void calcKevinBacon(const vector<pair<int, int>>& rels, vector<vector<int>>& kb, int kevin) {
	queue<int> Q;
	Q.push(kevin);
	int degree = 1, nodesPerDegree = Q.size();
	while (!Q.empty()) {
		if (nodesPerDegree == 0) {
			degree++;
			nodesPerDegree = Q.size();
		}

		int k = Q.front();
		Q.pop();
		nodesPerDegree--;

		for (vector<pair<int, int>>::size_type i = 0; i < rels.size(); ++i) {
			if (rels[i].first == k && kevin != rels[i].second && kb[kevin][rels[i].second] == 0) {
				kb[kevin][rels[i].second] = degree;
				kb[rels[i].second][kevin] = degree;
				Q.push(rels[i].second);
			}
			else if (rels[i].second == k && kevin != rels[i].first && kb[kevin][rels[i].first] == 0) {
				kb[kevin][rels[i].first] = degree;
				kb[rels[i].first][kevin] = degree;
				Q.push(rels[i].first);
			}
		}
	}
}

int findMinKevinBacon(const vector<pair<int, int>>& rels, vector<vector<int>>& kevinBacons) {
	int ret = 0;

	for (int i = 0; i < kevinBacons.size(); ++i) {
		calcKevinBacon(rels, kevinBacons, i);
	}

	vector<int> sumOfKBs;
	for (vector<vector<int>>::size_type i = 0; i < kevinBacons.size(); ++i) {
		sumOfKBs.push_back(accumulate(kevinBacons[i].begin(), kevinBacons[i].end(), 0));
	}

	for (const auto& elem : sumOfKBs) {
		cout << elem << " ";
	}
	cout << "\n";

	ret = min_element(sumOfKBs.begin(), sumOfKBs.end()) - sumOfKBs.begin();
	 
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> kevinBacons(N, vector<int>(N, 0));

	vector<pair<int, int>> relationships(M);
	for (vector<pair<int, int>>::size_type i = 0; i < relationships.size(); ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		relationships[i] = make_pair(v1-1, v2-1);
	}

	sort(relationships.begin(), relationships.end(), [](pair<int, int> left, pair<int, int> right) {
		if (left.first < right.first) return true;
		if (left.first == right.first && left.second < right.second) return true;
		return false;
		});

	int ans = findMinKevinBacon(relationships, kevinBacons) + 1;

	cout << ans;
}