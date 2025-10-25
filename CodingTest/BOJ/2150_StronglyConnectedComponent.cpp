#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(10001, vector<int>());
vector<vector<int>> r_graph(10001, vector<int>());
vector<bool> visited(10001, false);

stack<int> stk;

void forward(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (visited[v]) continue;
        forward(v);
    }
    stk.push(u);
}

void backward(int u, vector<int>& scc)
{
    visited[u] = true;
    scc.push_back(u);
    
    for (int v : r_graph[u])
    {
        if (visited[v]) continue;
        backward(v, scc);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int V, E; cin >> V >> E;

    for (int i = 0; i < E; ++i)
    {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        r_graph[v].emplace_back(u);
    }

    for (int i = 1; i <= V; ++i)
    {
        if (visited[i]) continue;
        forward(i);
    }

    vector<bool>(V + 1, false).swap(visited);

    vector<vector<int>> answer;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        if (visited[u]) continue;

        vector<int> scc;
        backward(u, scc);
        sort(scc.begin(), scc.end());
        answer.emplace_back(scc);
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (const auto& scc : answer)
    {
        for (const int u : scc)
        {
            cout << u << " ";
        }
        cout << -1 << "\n";
    }
}