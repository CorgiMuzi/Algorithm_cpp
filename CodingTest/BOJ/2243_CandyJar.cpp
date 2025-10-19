#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void UpdateTree(int taste, int num, vector<long long>& tree, int node, int left, int right)
{
    if (taste < left || taste > right) return;
    if (left == right)
    {
        tree[node] += num;
        return;
    }
    
    int mid = (left + right) / 2;
    UpdateTree(taste, num, tree, node * 2, left, mid);
    UpdateTree(taste, num, tree, node * 2 + 1, mid + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int QueryTree(int rank, vector<long long>& tree, int node, int left, int right)
{
    if (left == right) return left;
    int mid = (left + right) / 2;
    if (rank <= tree[node * 2]) return QueryTree(rank, tree, node * 2, left, mid);
    return QueryTree(rank - tree[node * 2], tree, node * 2 + 1, mid + 1, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    const int Max = 1'000'000;
    
    int N; cin >> N;
    vector<long long> tree(4 * Max);
    for (int i = 0; i < N; ++i)
    {
        int a, b; cin >> a >> b;
        if (a == 1)
        {
            int c = QueryTree(b, tree, 1, 1, Max);
            UpdateTree(c, -1, tree, 1, 1, Max);
            cout << c << "\n";
        }else if (a == 2)
        {
            int c; cin >> c;
            UpdateTree(b, c, tree, 1, 1, Max);
        }
    }
    return 0;
}
