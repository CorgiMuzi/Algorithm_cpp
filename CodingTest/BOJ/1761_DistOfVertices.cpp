#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

const int MaxJump = 16;

vector<vector<pii>> vertices(40001);
vector<vector<int>> parent(40001, vector<int>(MaxJump, 0));
vector<int> depth(40001);
vector<int> root_distance(40001);
vector<bool> visited(40001, false);



int GetCommonParentVertex(int v1, int v2)
{
    if (depth[v1] < depth[v2]) swap(v1, v2);

    for (int i = MaxJump - 1; i >= 0; --i)
    {
        if (depth[v1] - (1 << i) >= depth[v2]) v1 = parent[v1][i];
    }

    if (v1 == v2) return v1;

    for (int i = MaxJump - 1; i >= 0; --i)
    {
        if (parent[v1][i] != parent[v2][i])
        {
            v1 = parent[v1][i];
            v2 = parent[v2][i];
        }
    }

    return parent[v1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    
    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        vertices[v1].emplace_back(v2, d);
        vertices[v2].emplace_back(v1, d);
    }

    for (int i = 0; i < N; ++i) parent[i][0] = i;

    stack<int> stk;
    stk.push(1);
    visited[1] = true;
    root_distance[1] = 0;

    while (!stk.empty())
    {
        int cur = stk.top();
        bool isNxtExist = false;

        for (const pii& nxt : vertices[cur])
        {
            if (visited[nxt.first]) continue;
            stk.push(nxt.first);
            visited[nxt.first] = true;

            parent[nxt.first][0] = cur;
            depth[nxt.first] = depth[cur] + 1;
            root_distance[nxt.first] = root_distance[cur] + nxt.second;
            
            isNxtExist = true;
            break;
        }

        if (!isNxtExist)
        {
            stk.pop();
        }
    }

    for (int j = 1; j < MaxJump; ++j)
    {
        for (int i = 1; i <= N; ++i)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    
    int M; cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2; cin >> v1 >> v2;
        int common_root = GetCommonParentVertex(v1, v2);

        cout << root_distance[v1] + root_distance[v2] - 2 * root_distance[common_root] << "\n";
    }
}