#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    int M; cin >> M;
    vector<vector<int>> C(M, vector<int>(3, 0));

    for (int i = 0; i < M; ++i)
    {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }

    priority_queue<pair<int, vector<int>>> pq;
    map<vector<int>, int> dist;

    vector<int> target{A};
    sort(target.begin(), target.end());

    dist[A] = 0;
    pq.emplace(0, A);

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        vector<int> state = pq.top().second;
        pq.pop();

        if (dist.find(state) != dist.end() && dist[state] < cost) continue;

        for (const vector<int>& cmd : C)
        {
            int newCost = cost + cmd[2];
            vector<int> newState{state};
            swap(newState[cmd[0]], newState[cmd[1]]);

            if (dist.find(newState) == dist.end() || newCost < dist[newState])
            {
                dist[newState] = newCost;
                pq.emplace(-newCost, newState);
            }
        }
    }

    if (dist.find(target) != dist.end()) cout << dist[target];
    else cout << -1;
    
    return 0;
}
