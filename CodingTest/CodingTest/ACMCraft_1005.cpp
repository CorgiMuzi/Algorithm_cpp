#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N = 0, K = 0, W = 0;
int buildCost[1001];
int buildCond[1001];
int elapsedTime[1001];
vector<int> blueprint[1001];

void build() {
	queue<int> buildQ;
	for (int i = 1; i <= N; ++i) {
		if (buildCond[i] == 0) {
			buildQ.push(i);
			elapsedTime[i] = buildCost[i];
		}
	}

	for (int i = 0; i < N; ++i) {
		if (buildQ.empty()) {
			return;
		}

		int curBuild = buildQ.front();
		buildQ.pop();

		for (int j = 0; j < blueprint[curBuild].size(); ++j) {
			int nxtBuild = blueprint[curBuild][j];
			buildCond[nxtBuild]--;

			elapsedTime[nxtBuild] = max(elapsedTime[nxtBuild], elapsedTime[curBuild] + buildCost[nxtBuild]);
			if (buildCond[nxtBuild] == 0) buildQ.push(nxtBuild);
		}
	}
}

void clear() {
	for (int i = 1; i <= N; ++i) {
		vector<int>().swap(blueprint[i]);
		elapsedTime[i] = 0;
	}
}

int main() {
	int TC = 0;
	cin >> TC;

	for (int i = 1; i < 1001; ++i) {
		elapsedTime[i] = 0;
	}

	while (TC--) {
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) {
			cin >> buildCost[i];
		}

		for (int i = 0; i < K; ++i) {
			int cond = 0, build = 0;
			cin >> cond >> build;

			buildCond[build]++;
			blueprint[cond].push_back(build);
		}

		build();

		cin >> W;
		cout << elapsedTime[W] << "\n";	
		clear();
	}
}