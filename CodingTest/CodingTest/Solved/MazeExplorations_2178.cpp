#include <iostream>
#include <queue>

using std::cout, std::cin, std::queue, std::pair, std::make_pair;

short** maze;
bool** isVisited;
int N, M;

int findingPath() {
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    isVisited[0][0] = true;
    int elapsedTime = 1;
    int cellPerTime = Q.size();

    while (!Q.empty()) {
        if (cellPerTime == 0) {
            ++elapsedTime;
            cellPerTime = Q.size();
        }


        int x = Q.front().second, y = Q.front().first;
        Q.pop();
        cellPerTime--;

        if (x == M - 1 && y == N - 1) break;

        if (x + 1 < M && !isVisited[y][x + 1] && maze[y][x + 1] == 1) {
            Q.push(make_pair(y, x + 1));
            isVisited[y][x + 1] = true;
        }

        if (x - 1 >= 0 && !isVisited[y][x - 1] && maze[y][x - 1] == 1) {
            Q.push(make_pair(y, x - 1));
            isVisited[y][x - 1] = true;
        }

        if (y + 1 < N && !isVisited[y + 1][x] && maze[y + 1][x] == 1) {
            Q.push(make_pair(y + 1, x));
            isVisited[y + 1][x] = true;
        }

        if (y - 1 >= 0 && !isVisited[y - 1][x] && maze[y - 1][x] == 1) {
            Q.push(make_pair(y - 1, x));
            isVisited[y - 1][x] = true;
        }
    }

    return elapsedTime;
}

int main() {
    cin >> N >> M;

    maze = new short* [N];
    for (int i = 0; i < N; ++i) {
        maze[i] = new short[M];
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            char ch;
            cin >> ch;
            maze[r][c] = ch - '0';
        }
    }

    isVisited = new bool* [N];
    for (int i = 0; i < N; ++i) {
        isVisited[i] = new bool[M] {false};
    }

    int ans = findingPath();
    cout << ans;
}