#include <iostream>
#include <vector>

using namespace std;

int vertexNum = 0, edgeNum = 0;
vector<vector<pair<int, int>>> distances(801);

void travel() {

}

int main() {
	cin >> vertexNum >> edgeNum;

	int beg = 0, end = 0, dist = 0;
	for (int i = 0; i < vertexNum; ++i) {
		cin >> beg >> end >> dist;
		distances[beg].push_back(make_pair(end, dist));
		distances[end].push_back(make_pair(beg, dist));
	}

	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
}