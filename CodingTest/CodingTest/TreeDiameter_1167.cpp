#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int nodeCount = 0;
vector<vector<pair<int, int>>> tree(1, vector<pair<int, int>>(1, make_pair(0, 0)));

int findTreeNode(int start, int preNode, int dist, int maxDist) {
	for (vector<pair<int, int>>::size_type i = 0; i < tree[start].size(); ++i) {

	}
}

int calculateDiameter(int start, int preNode, int dist, int maxDist) {

}

int main() {
	cin >> nodeCount;
	for (int i = 0; i < nodeCount; ++i) {
		int curNode = 0;
		cin >> curNode;
		int nextNode = 0, dist = 0;
		vector<pair<int, int>> neighbors;
		while (cin >> nextNode) {
			if (nextNode == -1) break;
			cin >> dist;

			neighbors.emplace_back(nextNode, dist);
		}

		tree.push_back(neighbors);
	}

	int treeDiameter = 0;
	cout << treeDiameter;
}