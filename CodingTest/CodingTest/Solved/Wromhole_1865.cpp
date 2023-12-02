#include <iostream>
#include <vector>

#define INF 5000001

using namespace std;

int N = 0, M = 0, W = 0;
vector<pair<pair<int, int>, int>> road;
int timeDist[501];

bool timeTravel() {
	for (int i = 1; i <= N; ++i) timeDist[i] = INF;

	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < road.size(); ++j) {
			int beg = road[j].first.first;
			int end = road[j].first.second;
			int cost = road[j].second;

			if (timeDist[beg] + cost < timeDist[end]) {
				if (i == N) return true;
				timeDist[end] = timeDist[beg] + cost;
			}
		}
	}

	return false;
}

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		road.clear();
		cin >> N >> M >> W;
		
		int S = 0, E = 0, D = 0;

		for (int i = 0; i < M; ++i) {
			cin >> S >> E >> D;
			road.push_back(make_pair(make_pair(S, E), D));
			road.push_back(make_pair(make_pair(E, S), D));
		}

		for (int i = 0; i < W; ++i) {
			cin >> S >> E >> D;
			road.push_back(make_pair(make_pair(S, E), -D));
		}

		cout << (timeTravel() ? "YES\n" : "NO\n");
	}
}