#include <iostream>
#include <queue>
#include <vector>

#define RIPE 1
#define RAW 0
#define BLANK -1

using std::cin, std::cout, std::queue;
using std::vector, std::pair, std::make_pair;

int M, N, H;
int*** warehouse;

int tomatoRiping(const vector<pair<int, pair<int, int>>>& init) {
    queue<pair<int, pair<int, int>>> Q;
    bool*** isVisited = new bool** [H];
    for (int h = 0; h < H; ++h) {
        isVisited[h] = new bool* [N];
        for (int r = 0; r < N; ++r) {
            isVisited[h][r] = new bool[M] {false};
        }
    }

    for (int i = 0; i < init.size(); ++i) {
        Q.push(init[i]);
        isVisited[init[i].first][init[i].second.first][init[i].second.second] = true;
    }

    int tomatoesPerDay = Q.size();
    int elapsedDay = 0;

    while (!Q.empty()) {
        if (tomatoesPerDay == 0) {
            elapsedDay++;
            tomatoesPerDay = Q.size();
        }

        pair<int, pair<int, int>> tomato = Q.front();
        Q.pop();
        tomatoesPerDay--;

        int h = tomato.first, r = tomato.second.first, c = tomato.second.second;
        if (h + 1 < H && warehouse[h + 1][r][c] == RAW && !isVisited[h + 1][r][c]) {
            Q.push(make_pair(h + 1, make_pair(r, c)));
            warehouse[h + 1][r][c] = RIPE;
            isVisited[h + 1][r][c] = true;
        }

        if (h - 1 >= 0 && warehouse[h - 1][r][c] == RAW && !isVisited[h - 1][r][c]) {
            Q.push(make_pair(h - 1, make_pair(r, c)));
            warehouse[h - 1][r][c] = RIPE;
            isVisited[h - 1][r][c] = true;
        }

        if (r + 1 < N && warehouse[h][r + 1][c] == RAW && !isVisited[h][r + 1][c]) {
            Q.push(make_pair(h, make_pair(r + 1, c)));
            warehouse[h][r + 1][c] = RIPE;
            isVisited[h][r + 1][c] = true;
        }

        if (r - 1 >= 0 && warehouse[h][r - 1][c] == RAW && !isVisited[h][r - 1][c]) {
            Q.push(make_pair(h, make_pair(r - 1, c)));
            warehouse[h][r - 1][c] = RIPE;
            isVisited[h][r - 1][c] = true;
        }

        if (c + 1 < M && warehouse[h][r][c + 1] == RAW && !isVisited[h][r][c + 1]) {
            Q.push(make_pair(h, make_pair(r, c + 1)));
            warehouse[h][r][c + 1] = RIPE;
            isVisited[h][r][c + 1] = true;
        }

        if (c - 1 >= 0 && warehouse[h][r][c - 1] == RAW && !isVisited[h][r][c - 1]) {
            Q.push(make_pair(h, make_pair(r, c - 1)));
            warehouse[h][r][c - 1] = RIPE;
            isVisited[h][r][c - 1] = true;
        }
    }

    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (warehouse[h][r][c] == RAW) return -1;
            }
        }
    }

    return elapsedDay;
}

int main() {
    cin >> M >> N >> H;
    warehouse = new int** [H];
    for (int i = 0; i < H; ++i) {
        warehouse[i] = new int* [N];
    }

    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            warehouse[h][r] = new int[M];
        }
    }


    vector<pair<int, pair<int, int>>> init;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                cin >> warehouse[h][r][c];
                if (warehouse[h][r][c] == RIPE) {
                    init.push_back(make_pair(h, make_pair(r, c)));
                }
            }
        }
    }

    int ans = tomatoRiping(init);
    cout << ans;
}