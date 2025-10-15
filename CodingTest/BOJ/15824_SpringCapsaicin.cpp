#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int Mod = 1'000'000'007;

vector<long long> powers(300001, -1);

long long powi(int exp)
{
    if (powers[exp] != -1) return powers[exp];
    return powers[exp] = (2 * powi(exp - 1)) % Mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    powers[0] = 1;

    int N; cin >> N;
    vector<int> menu(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> menu[i];
    }

    sort(menu.begin(), menu.end());

    long long total = 0;
    
    for (int i = 0; i < N; ++i)
    {
        long long max_val = (menu[i] * powi(i)) % Mod;
        long long min_val = (menu[i] * powi(N - i - 1)) % Mod;

        long long min_max_val = (max_val - min_val + Mod) % Mod;
        total += min_max_val;
        total %= Mod;
    }

    cout << total << endl;
    
    return 0;
}
