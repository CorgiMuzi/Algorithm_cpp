#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
    stack<char> infix;

    map<char, int> importance;
    importance['('] = 0;
    importance['+'] = 1;
    importance['-'] = 1;
    importance['*'] = 2;
    importance['/'] = 2;

    char value;
    string ans = "";
    while (cin >> value) {
        if (value == '(') {
            infix.push(value);
        }
        else if (value == '+' || value == '-') {
            while (!infix.empty() && importance[infix.top()] >= importance[value]) {
                ans += infix.top();
                infix.pop();
            }

            infix.push(value);
        }
        else if (value == '*' || value == '/') {
            while (!infix.empty() && importance[infix.top()] >= importance[value]) {
                ans += infix.top();
                infix.pop();
            }

            infix.push(value);
        }
        else if (value == ')') {
            while (!infix.empty() && infix.top() != '(') {
                ans += infix.top();
                infix.pop();
            }

            infix.pop();
        }
        else {
            ans += value;
        }
    }

    while (!infix.empty()) {
        ans += infix.top();
        infix.pop();
    }

    cout << ans;
}