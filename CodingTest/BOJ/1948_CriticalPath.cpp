#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> roads(10001);
vector<vector<pair<int, int>>> r_roads(10001);
vector<int> entries(10001, 0);
vector<int> max_times(10001, -1);
vector<bool> visited(10001, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, t; cin >> u >> v >> t;
        roads[u].emplace_back(v, t);
        entries[v]++;
    }
    int s, e; cin >> s >> e;

    max_times[s] = 0;
    
    queue<int> q;
    q.emplace(s);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const pair<int, int>& nxt : roads[cur])
        {
            max_times[nxt.first] = max(max_times[nxt.first], max_times[cur] + nxt.second);
            entries[nxt.first]--;
            if (entries[nxt.first] == 0) q.push(nxt.first);
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (const pair<int, int>& p : roads[i])
        {
            r_roads[p.first].emplace_back(i, p.second);
        }
    }

    set<pair<int, int>> paths;
    
    queue<int>().swap(q);
    q.emplace(e);
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (const pair<int, int>& nxt : r_roads[cur])
        {
            if (nxt.second + max_times[nxt.first] != max_times[cur]) continue;
            paths.insert({cur, nxt.first});
            
            if (visited[nxt.first]) continue;
            q.push(nxt.first);
            visited[nxt.first] = true;
        }
    }

    cout << max_times[e] << "\n" << paths.size();
    
    return 0;
}   
