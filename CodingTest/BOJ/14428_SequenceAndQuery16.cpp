#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CreateSegmentTree(const vector<int>& input, vector<int>& tree, int node, int left, int right)
{
    if (left == right) return tree[node] = left;
    int mid = (left + right) / 2;

    int l_val = CreateSegmentTree(input, tree, node * 2, left, mid);
    int r_val = CreateSegmentTree(input, tree, node * 2 + 1, mid + 1, right);
    
    return tree[node] = input[l_val] <= input[r_val] ? l_val : r_val;
}

void UpdateSegmentTree(vector<int>& input, vector<int>& tree, const int target, const int val, int node, int left, int right)
{
    if (target < left || target > right) return;

    if (left == right)
    {
        input[target] = val;
        return;
    }
    
    int mid = (left + right) / 2;
    if (target <= mid) UpdateSegmentTree(input, tree, target, val, node * 2, left, mid);
    else UpdateSegmentTree(input, tree, target, val, node * 2 + 1, mid + 1, right);

    int l_val = tree[node * 2];
    int r_val = tree[node * 2 + 1];
    tree[node] = input[l_val] <= input[r_val] ? l_val : r_val; 
}

int QuerySegmentTree(const vector<int>& input, const vector<int>& tree, const int node, const int start, const int end, int left, int right)
{
    if (right < start || left > end) return -1;
    if (start <= left && end >= right) return tree[node];

    int mid = (left + right) / 2;
    int l_val = QuerySegmentTree(input, tree, node * 2, start, end, left, mid);
    int r_val = QuerySegmentTree(input, tree, node * 2 + 1, start, end, mid + 1, right);

    if (l_val < 0) return r_val;
    if (r_val < 0) return l_val;
    
    return input[l_val] <= input[r_val] ? l_val : r_val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> input(N + 1);
    for (int i = 1 ; i <= N; ++i)
    {
        cin >> input[i];
    }

    vector<int> tree(4 * N + 1);
    CreateSegmentTree(input, tree, 1, 1, N);

    int M; cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            UpdateSegmentTree(input, tree, b, c, 1, 1, N);
        }else if (a == 2)
        {
            cout << QuerySegmentTree(input, tree, 1, b, c, 1, N) << "\n";
        }
    }
    
    return 0;
}
