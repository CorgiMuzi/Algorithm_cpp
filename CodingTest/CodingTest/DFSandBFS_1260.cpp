#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> links;
std::vector<bool> DFS_Visited;
std::vector<bool> BFS_Visited;

void DFS(int v) {
	std::cout << v << " ";
	DFS_Visited[v] = true;

	for (std::vector<std::pair<int, int>>::size_type i = 0; i < links.size(); ++i) {
		if (links[i].first == v && !DFS_Visited[links[i].second]) {
			DFS(links[i].second);
		}
		else if (links[i].second == v && !DFS_Visited[links[i].first]) {
			DFS(links[i].first);
		}
	}
}

void BFS(int v) {
	std::vector<int> queue;
	queue.push_back(v);
	BFS_Visited[v] = true;

	while (!queue.empty()) {
		int front = queue.front();
		queue.erase(queue.begin());
		std::cout << front << " ";

		for (std::vector<std::pair<int, int>>::size_type i = 0; i < links.size(); ++i) {
			if (links[i].first == front && !BFS_Visited[links[i].second]) {
				BFS_Visited[links[i].second] = true;
				queue.push_back(links[i].second);
			}
			else if (links[i].second == front && !BFS_Visited[links[i].first]) {
				BFS_Visited[links[i].first] = true;
				queue.push_back(links[i].first);
			}
		}
	}
}

int main() {
	int v, e, start;
	std::cin >> v >> e >> start;

	for (int i = 0; i < e; ++i) {
		int v1, v2;
		std::cin >> v1 >> v2;
		if (v1 > v2) links.push_back(std::make_pair(v2, v1));
		else links.push_back(std::make_pair(v1, v2));
	}

	std::sort(links.begin(), links.end(), [](std::pair<int, int> left, std::pair<int, int> right) {
		if (left.first < right.first) return true;
		else if (left.first == right.first) {
			if (left.second < right.second) return true;
			else return false;
		}
		else return false;
		});

	DFS_Visited = std::vector<bool>(v + 1, false);
	BFS_Visited = std::vector<bool>(v + 1, false);

	DFS(start);
	std::cout << "\n";
	BFS(start);
}