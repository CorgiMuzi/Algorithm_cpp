#include <iostream>
#include <queue>

using namespace std;

char map[1001][1001];
int visit[1001][1001][2] = { 0, };
int hDir[4] = { -1, 1, 0, 0 };
int wDir[4] = { 0, 0, -1, 1 };
int N = 0, M = 0;

struct point {
public:
    int row = 0;
    int col = 0;
    int power = 1;
};

int travel(int r, int c) {
    queue<point> nodes;
    point p;
    p.row = r;
    p.col = c;
    p.power = 1;

    nodes.push(p);
    visit[p.row][p.col][p.power] = 1;

    while (!nodes.empty()) {
        point cur = nodes.front();
        nodes.pop();

        if (cur.row + 1 == N && cur.col + 1 == M) {
            return visit[cur.row][cur.col][cur.power];
        }

        point next;
        for (int i = 0; i < 4; ++i) {
            int mr = cur.row + hDir[i];
            int mc = cur.col + wDir[i];

            if (mr < 0 || mc < 0 || mr >= N || mc >= M) continue;

            if (map[mr][mc] == '1' && cur.power == 1) {
                visit[mr][mc][0] = visit[cur.row][cur.col][cur.power] + 1;
                next.power = 0;
                next.row = mr;
                next.col = mc;

                nodes.push(next);
            }

            if (map[mr][mc] == '0' && visit[mr][mc][cur.power] == 0) {
                visit[mr][mc][cur.power] = visit[cur.row][cur.col][cur.power] + 1;
                next.power = cur.power;
                next.row = mr;
                next.col = mc;

                nodes.push(next);
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    int tiles = travel(0, 0);
    cout << tiles;
}