#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long lld;
typedef pair<int, lld> pil;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    
    while (true)
    {
        int N; cin >> N;
        
        if (N == 0) break;

        lld max_area = 0;
        stack<pil> stk;
        int h; cin >> h;
        stk.emplace(h, h);
        for (int i = 1; i < N; ++i)
        {
            cin >> h;

            pil top = stk.top();
            int top_h = top.first;
            lld top_a = top.second;

            if (h > top_h)
            {
                stk.emplace(h, h);
                continue;
            }

            if (h == top_h)
            {
                stk.top().second += h;
                continue;
            }

            lld stack_area = 1;
            
            while (top_h > h)
            {
                max_area = max(max_area, top_a);
                
                lld temp_area = top_a / top_h;
                stack_area = temp_area + 1;
                
                stk.pop();
                if (stk.empty()) break;

                top = stk.top();
                top_h = top.first;
                top_a = top.second + temp_area * top_h;
            }

            
            if (stk.empty() || stk.top().first != h)
            {
                stk.emplace(h, stack_area * h);
            }else
            {
                stk.top().second += stack_area * top_h;
            }            
        }
        
        while (!stk.empty())
        {
            max_area = max(max_area, stk.top().second);

            if (stk.top().first == 0)
            {
                stk.pop();
                continue;
            }
            
            lld stack_area = stk.top().second / stk.top().first;
            stk.pop();

            if (stk.empty()) break;
            stk.top().second += stack_area * stk.top().first;
        }

        cout << max_area << "\n";
    }
    
    
    
    return 0;
}   
