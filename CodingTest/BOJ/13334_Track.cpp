#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    vector<pair<int, int>> track;
    for (int i = 0; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        track.emplace_back(u, v);
    }

    int L;
    cin >> L;

    sort(track.begin(), track.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        if (lhs.second == rhs.second) return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    });

    priority_queue<int, vector<int>, greater<>> pq;
    int max_count = 0;
    for (const pair<int, int>& t : track)
    {
        int start = t.second - L;

        while (!pq.empty() && pq.top() < start)
        {
            pq.pop();
        }

        if (t.first >= start)
        {
            pq.push(t.first);
        }

        max_count = max(max_count, static_cast<int>(pq.size()));
    }

    cout << max_count << "\n";
    return 0;
}
