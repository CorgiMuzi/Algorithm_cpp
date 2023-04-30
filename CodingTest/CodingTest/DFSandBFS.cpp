#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;
void DFS(int node, vector<pair<int, int>> edge) {
	if (*find(stack.begin(), stack.end(), node) != node) {
		stack.emplace_back(node);
	}

	cout << stack.back();
	stack.pop_back();

	for (pair<int, int> v : edge) {
		if (v.first == node && (*find(stack.begin(), stack.end(), v.second) != v.second)) {
			stack.emplace_back(v.second);
		}
		else if (v.second == node && (*find(stack.begin(), stack.end(), v.first) != v.first)) {
			stack.emplace_back(v.first);
		}
	}

	if (stack.empty()) {
		return;
	}
	else {
		DFS(stack.back(), edge);
	}
}

void BFS(int start, vector<pair<int, int>> edge) {

}

int main() {
	int V = 0, E = 0, S = 0;
	// V = vertex, E = Edge, S = Start
	cin >> V >> E >> S;

	vector<pair<int, int>> edgeVec;
	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edgeVec.emplace_back(v1, v2);
	}

	DFS(S, edgeVec);
	BFS(S, edgeVec);


	return 0;
}