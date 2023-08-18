#include <iostream>

#define A 65

using namespace std;

bool vAlphabet[26];
char board[20][20];
int R = 0, C = 0;
int maxCell = 0;
int rDir[4] = { -1, 1, 0, 0 };
int cDir[4] = { 0, 0, -1, 1 };

void traveling(int r, int c, int traveledCell) {
    int nextR = r, nextC = c;

    for (int dir = 0; dir < 4; ++dir) {
        nextR = r + rDir[dir], nextC = c + cDir[dir];

        if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) continue;
        if (vAlphabet[board[nextR][nextC] - A]) continue;

        vAlphabet[board[nextR][nextC] - A] = true;
        traveling(nextR, nextC, traveledCell + 1);
        vAlphabet[board[nextR][nextC] - A] = false;
    }
    maxCell = max(maxCell, traveledCell);
}

int main() {
    cin >> R >> C;

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> board[r][c];
        }
    }

    for (int alpahbet = 0; alpahbet < 26; ++alpahbet) {
        vAlphabet[alpahbet] = false;
    }
    vAlphabet[board[0][0] - A] = true;
    traveling(0, 0, 1);

    cout << maxCell;

}