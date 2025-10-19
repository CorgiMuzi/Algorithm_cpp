
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> group(1 << 15, vector<long long>(100, 0));
vector<long long> factorial(16);
vector<int> remainders(15);
vector<int> ten_pow(51);

long long GCD(long long n1, long long n2)
{
    if (n2 == 0) return n1;
    return GCD(n2, n1 % n2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    vector<string> input(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> input[i];
    }
    int K;
    cin >> K;

    ten_pow[0] = 1;
    factorial[0] = 1;
    for (int i = 1; i <= 50; ++i) ten_pow[i] = (ten_pow[i - 1] * 10) % K;
    for (int i = 1; i <= N; ++i) factorial[i] = factorial[i - 1] * i;

    for (int i = 0; i < N; ++i)
    {
        int rem = 0;
        for (char c : input[i])
        {
            int ic = c - '0';
            rem = (rem * 10 + ic) % K;
        }
        remainders[i] = rem;
    }

    group[0][0] = 1;
    for (int i = 0; i < (1 << N); ++i)
    {
        for (int rem = 0; rem < K; ++rem)
        {
            if (group[i][rem] == 0) continue;

            for (int j = 0; j < N; ++j)
            {
                if (i & (1 << j)) continue;
                int new_rem = (rem * ten_pow[input[j].length()] + remainders[j]) % K;
                group[i | (1 << j)][new_rem] += group[i][rem];
            }
        }
    }

    long long result = group[(1 << N) - 1][0];
    long long total = factorial[N];
    
    long long gcd = GCD(total, result);

    result /= gcd;
    total /= gcd;

    cout << result << "/" << total << "\n";

    return 0;
}
