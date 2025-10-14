#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    const int Mod = 10'007;
    vector<vector<int>> prob(53, vector<int>(53, 0));

    for (int i = 0; i < prob.size(); ++i)
    {
        prob[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            prob[i][j] = (prob[i - 1][j - 1] + prob[i - 1][j]) % Mod;
        }
    }

    int N; cin >> N;

    int answer = 0;

    for (int i = 1; i * 4 <= N; ++i)
    {
        int unit = (prob[13][i] * prob[52 - 4 * i][N - 4 * i]) % Mod;

        if (i % 2)
        {
            answer = (answer + unit) % Mod;
        }else
        {
            answer = (answer - unit + Mod) % Mod;
        }
    }

    cout << answer << "\n";

    return 0;
}
