#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using std::cin, std::cout;
using std::vector, std::queue, std::string;
using std::pair, std::make_pair;

int target;
char cmd_type[4] = { 'D', 'S', 'L', 'R' };
bool isVisited[10000];

string operateDSLR(int current) {
    queue<pair<int, string>> Q;
    Q.push(make_pair(current, ""));

    while (!Q.empty()) {
        pair<int, string> front = Q.front();
        Q.pop();

        if (front.first == target) {
            return front.second;
        }

        int temp;
        for (int i = 0; i < 4; ++i) {
            if (cmd_type[i] == 'D') {
                temp = (front.first * 2) % 10000;
            }
            else if (cmd_type[i] == 'S') {
                temp = front.first - 1 < 0 ? 9999 : front.first - 1;
            }
            else if (cmd_type[i] == 'L') {
                temp = ((front.first % 1000) * 10) + (front.first / 1000);
            }
            else if (cmd_type[i] == 'R') {
                temp = ((front.first % 10) * 1000) + (front.first / 10);
            }

            if (!isVisited[temp]) {
                isVisited[temp] = true;
                Q.push(make_pair(temp, front.second + cmd_type[i]));
            }
        }
    }

    return "";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int current = 0;
        cin >> current >> target;

        std::memset(isVisited, false, sizeof(isVisited) / sizeof(*isVisited));

        isVisited[current] = true;
        string ans = operateDSLR(current);
        cout << ans << "\n";
    }
}