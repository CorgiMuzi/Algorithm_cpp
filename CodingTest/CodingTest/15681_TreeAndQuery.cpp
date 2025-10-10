#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
vector<int> leaf;

void GetLeafCount(int root, int parent)
{
    leaf[root] = 1;

    for (int child : edge[root])
    {
        if (child == parent) continue;

        GetLeafCount(child, root);
        leaf[root] += leaf[child];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    
    int N, R, Q;
    cin >> N >> R >> Q;

    edge.resize(N + 1);
    leaf.resize(N + 1);
    
    for (int i = 0; i < N - 1; ++i)
    {
        int U, V;
        cin >> U >> V;
        
        edge[U].push_back(V);
        edge[V].push_back(U);
    }

    GetLeafCount(R, 0);

    for (int i = 0; i < Q; ++i)
    {
        int query; cin >> query;
        cout << leaf[query] << "\n";
    }
}