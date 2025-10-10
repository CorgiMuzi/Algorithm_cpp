#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
vector<int> relations[MAX];
vector<int> post_order;
vector<bool> visited(MAX, false);
int parent[MAX];
int dp[MAX][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v; cin >> u >> v;
        relations[u].push_back(v);
        relations[v].push_back(u);
    }

    stack<int> stk;
    stk.push(1);
    visited[1] = true;
    parent[1] = 0;

    while (!stk.empty())
    {
        int u = stk.top(); stk.pop();
        post_order.push_back(u);

        for (int v : relations[u])
        {
            if (visited[v]) continue;
            visited[v] = true;
            parent[v] = u;
            stk.push(v);
        }
    }

    reverse(post_order.begin(), post_order.end());

    for (int u : post_order)
    {
        dp[u][0] = 0;
        dp[u][1] = 1;

        for (int v : relations[u])
        {
            if (parent[u] == v) continue;
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }

    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}
