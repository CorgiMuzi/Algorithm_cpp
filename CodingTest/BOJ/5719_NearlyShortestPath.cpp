#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int depart, const vector<vector<pii>>& path, vector<int>& dist)
{
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[depart] = 0;
    pq.emplace(0, depart);

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        int cur_dist = cur.first;
        int cur_vert = cur.second;

        if (cur_dist > dist[cur_vert]) continue;

        for (const pair<int, int>& nxt : path[cur_vert])
        {
            int nxt_dist = cur_dist + nxt.first;
            int nxt_vert = nxt.second;

            if (nxt_dist < dist[nxt_vert])
            {
                dist[nxt_vert] = nxt_dist;
                pq.emplace(nxt_dist, nxt_vert);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    
    int N, M;

    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        int depart, arrive; cin >> depart >> arrive;

        vector<vector<pii>> path(N, vector<pii>());
        vector<vector<pii>> r_path(N, vector<pii>());
        vector<int> dist(path.size(), 1e9);
        vector<int> r_dist(r_path.size(), 1e9);

        for (int i = 0; i < M; ++i)
        {
            int u, v, p; cin >> u >> v >> p;
            path[u].emplace_back(p, v);
            r_path[v].emplace_back(p, u);
        }

        dijkstra(depart, path, dist);
        dijkstra(arrive, r_path, r_dist);

        vector<vector<pii>> alt_path(N, vector<pii>());
        for (int from = 0; from < N; ++from)
        {
            for (const pii& p : path[from])
            {
                int weight = p.first;
                int to = p.second;

                if (dist[from] + weight + r_dist[to] == dist[arrive]) continue;
                alt_path[from].emplace_back(weight, to);
            }
        }

        vector<int>(alt_path.size(), 1e9).swap(dist);
        dijkstra(depart, alt_path, dist);

        cout << (dist[arrive] < 1e9 ? dist[arrive] : -1) << "\n";
    }
    
    return 0;
}
