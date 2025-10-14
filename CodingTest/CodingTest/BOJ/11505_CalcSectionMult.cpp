#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long lld;

const int Mod = 1'000'000'007;

lld CreateSegmentTree(const vector<int>& input, vector<lld>& tree, int node, int left, int right)
{
    if (left == right) return tree[node] = input[left];

    int mid = (left + right) / 2;
    return tree[node] = CreateSegmentTree(input, tree, node * 2, left, mid) * CreateSegmentTree(input, tree, node * 2 + 1, mid + 1, right) % Mod; 
}

void UpdateSegementTree(int target, int input, vector<lld>& tree, int left, int right, int node = 1)
{
    if (target < left || target > right) return;

    if (left == right) tree[node] = input;
    else
    {
        int mid = (left + right) / 2;
        UpdateSegementTree(target, input, tree, left, mid, node * 2);
        UpdateSegementTree(target, input, tree, mid + 1, right, node * 2 + 1);

        tree[node] = tree[node * 2] * tree[node * 2 + 1] % Mod;
    }
}

lld QuerySegementTree(int start, int end, const vector<lld>& tree, int left, int right, int node = 1)
{
    if (start > right || end < left) return 1;
    if (left >= start && right <= end) return tree[node];

    int mid = (left + right) / 2;
    return QuerySegementTree(start, end, tree, left, mid, node * 2) * QuerySegementTree(start, end, tree, mid + 1, right, node * 2 + 1) % Mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    vector<lld> tree(4 * N);

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    CreateSegmentTree(A, tree, 1, 1, N);

    for (int i = 0; i < M + K; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1)
        {
            UpdateSegementTree(b, c, tree, 1, N);
        }else if (a == 2)
        {
            cout << QuerySegementTree(b, c, tree, 1, N) << "\n";
        }
    }
    
    return 0;
}
