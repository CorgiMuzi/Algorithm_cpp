#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    vector<long> A, B, C, D;
    for (int i = 0; i < N; ++i)
    {
        long a, b, c, d; cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    vector<long> AB, CD;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    long answer = 0;
    sort(CD.begin(), CD.end());
    for (long ab : AB)
    {
        vector<long>::iterator upper = upper_bound(CD.begin(), CD.end(), -ab);
        vector<long>::iterator lower = lower_bound(CD.begin(), CD.end(), -ab);

        answer += (upper - lower);
    }

    cout << answer;
}