#include <iostream>
#include <stack>

using namespace std;

typedef long long lld;
typedef pair<int, lld> pil;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    stack<pil> stk;

    lld pair_cnt = 0;

    for (int i = 0; i < N; ++i)
    {
        int height; cin >> height;

        lld cnt = 1;
        
        while (!stk.empty() && stk.top().first <= height)
        {
            auto top = stk.top();
            stk.pop();

            pair_cnt += top.second;

            if (top.first == height) cnt += top.second;
        }

        if (!stk.empty()) pair_cnt++;

        stk.emplace(height, cnt);
    }

    cout << pair_cnt;
}