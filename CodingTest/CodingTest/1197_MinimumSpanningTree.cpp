#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind
{
	UnionFind(int V)
	{
		hierarchy.resize(V + 1);
		for (int i = 0; i < V + 1; ++i)
		{
			hierarchy[i] = i;
		}
	}

	int FindParent(int p)
	{
		if (p == hierarchy[p]) return p;
		return hierarchy[p] = FindParent(hierarchy[p]);
	}

	bool UnionGroup(int p1, int p2)
	{
		p1 = FindParent(p1);
		p2 = FindParent(p2);

		if (p1 != p2)
		{
			hierarchy[p1] = p2;
			return true;
		}

		return false;
	}
    
	vector<int> hierarchy;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
	freopen("input.txt", "r", stdin);

	int V, E;
	cin >> V >> E;

	UnionFind group(V);
	vector<vector<int>> edge(E, vector<int>(3, 0));

	for (int i = 0; i < E; ++i)
	{
		cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
	}

	sort(edge.begin(), edge.end(), [](const auto& v1, const auto& v2)
	{
		return v1[2] < v2[2];
	});

	int weight = 0;
	int edge_count = 0;
    
	for (vector<int>& e : edge)
	{
		if (group.UnionGroup(e[0], e[1]))
		{
			weight += e[2];
			edge_count++;
		}

		if (edge_count == V - 1) break;
	}

	cout << weight << "\n";
}
