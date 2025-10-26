#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pattern(1000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    pattern[0] = 0;
    
    int j = 0;
    for (int i = 1; i < P.length(); ++i)
    {
        while (j > 0 && P[i] != P[j])
        {
            j = pattern[j - 1];
        }

        if (P[i] == P[j]) j++;
        pattern[i] = j;
    }

    int t = 0;
    int p = 0;

    vector<int> find_pos;

    while (t < T.length())
    {
        if (T[t] == P[p])
        {
            t++;
            p++;
        }

        if (p == P.length())
        {
            find_pos.push_back(t - p + 1);
            p = pattern[p - 1];
        }else if (T[t] != P[p])
        {
            if (p > 0) p = pattern[p - 1];
            else t++;
        }
    }

    cout << find_pos.size() << "\n";
    for (int pos : find_pos) cout << pos << " ";

    return 0;
}
