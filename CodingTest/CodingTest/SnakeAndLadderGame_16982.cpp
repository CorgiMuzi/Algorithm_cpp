#include <iostream>
#include <map>
#include <queue>

using std::cin, std::cout, std::min;
using std::map, std::queue;

int countOfLadders = 0, countOfSnakes = 0;
map<int, int> ladders, snakes;
bool isVisited[101];

int playing(int start) {
    int diceRoll = 1;
    queue<int> q;
    for (int i = 1; i <= 6; ++i) {
        q.push(start + i);
        isVisited[start + i] = true;
    }

    int stagePerDice = q.size();
    typedef map<int, int>::iterator map_iter;
    while (!q.empty()) {
        if (stagePerDice == 0) {
            diceRoll++;
            stagePerDice = q.size();
        }

        int current = q.front();
        q.pop();
        stagePerDice--;

        if (current == 100) break;

        map_iter ladder = ladders.find(current);
        if (ladder == ladders.end()) {
            map_iter snake = snakes.find(current);
            if (snake != snakes.end()) {
                current = snake->second;
            }
        }
        else {
            current = ladder->second;
        }

        isVisited[current] = true;

        for (int i = 1; i <= 6; ++i) {
            if (current + i > 100) break;
            if (!isVisited[current + i]) {
                q.push(current + i);
                isVisited[current + i] = true;
            }
        }
    }

    return diceRoll;
}

int main() {
    cin >> countOfLadders >> countOfSnakes;

    for (int i = 0; i < countOfLadders; ++i) {
        int start = 0, end = 0;
        cin >> start >> end;
        ladders[start] = end;
    }

    for (int i = 0; i < countOfSnakes; ++i) {
        int start = 0, end = 0;
        cin >> start >> end;
        snakes[start] = end;
    }

    isVisited[1] = true;
    int diceRoll = playing(1);
    cout << diceRoll;
}