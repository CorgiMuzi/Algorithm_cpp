#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> CreateMinMaxTree(const vector<int>& input, vector<pair<int, int>>& tree, int node, int left, int right)
{
    if (left == right) return tree[node] = make_pair(input[left], input[right]);
    int mid = (left + right) / 2;
    pair<int, int> p1, p2;
    p1 = CreateMinMaxTree(input, tree, node * 2, left, mid);
    p2 = CreateMinMaxTree(input, tree, node * 2 + 1, mid + 1, right);

    int minVal = min(p1.first, p2.first);
    int maxVal = max(p1.second, p2.second);
    return tree[node] = {minVal, maxVal};
}

pair<int, int> QueryMinMaxTree(const vector<pair<int, int>>& tree, int node, int left, int right, const int start, const int end)
{
    if (right < start || left > end) return {INT_MAX, INT_MIN};

    if (left <= start && right >= end) return tree[node];
    int mid = (start + end) / 2;

    pair<int,int> p1, p2;
    p1 = QueryMinMaxTree(tree, node * 2, left, right, start, mid);
    p2 = QueryMinMaxTree(tree, node * 2 + 1, left, right, mid + 1, end);
    
    return {min(p1.first, p2.first), max(p1.second, p2.second)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<pair<int, int>> tree(4 * N);
    CreateMinMaxTree(A, tree, 1, 1, N);

    for (int i = 0; i < M; ++i)
    {
        int l, r; cin >> l >> r;
        pair<int, int> p = QueryMinMaxTree(tree, 1, l, r, 1, N);
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}
