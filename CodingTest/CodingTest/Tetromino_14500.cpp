#include <iostream>

using namespace std;

int width, height;
int** board;

int hDir[4] = { 1, -1, 0, 0 };
int wDir[4] = { 0, 0, 1, -1 };

int placeTetromino(int ph, int pw, int h, int w, int sum, int stack) {
    if (stack == 4) return sum;

    int score[4] = { -1, -1, -1, -1 };
    for (int i = 0; i < 4; ++i) {
        int mh = h + hDir[i];
        int mw = w + wDir[i];

        if (mh < 0 || mw < 0 || mh >= height || mw >= width || (mh == ph && mw == pw)) continue;

        score[i] = placeTetromino(h, w, mh, mw, sum + board[mh][mw], stack + 1);
    }

    int max = score[0];
    for (int i = 1; i < 4; ++i) {
        if (max < score[i]) max = score[i];
    }

    return max;
}

int placeTTetromino() {
    int T_max = -1;
    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            int score[4] = { -1, -1, -1, -1 };
            if (h - 1 >= 0 && w - 1 >= 0 && w + 1 < width) score[0] = board[h - 1][w - 1] + board[h - 1][w] + board[h - 1][w + 1];
            if (h - 1 >= 0 && w - 1 >= 0 && h + 1 < height) score[3] = board[h - 1][w - 1] + board[h][w - 1] + board[h + 1][w - 1];
            if (h - 1 >= 0 && w + 1 < width && h + 1 < height) score[1] = board[h - 1][w + 1] + board[h][w + 1] + board[h + 1][w + 1];
            if (w - 1 >= 0 && w + 1 < width && h + 1 < height) score[2] = board[h + 1][w - 1] + board[h + 1][w] + board[h + 1][w + 1];

            for (int i = 0; i < 4; ++i) {
                score[i] += board[h][w];
                if (T_max < score[i]) T_max = score[i];
            }
        }
    }
    return T_max;
}

int main() {
    cin >> height >> width;
    board = new int* [height];
    for (int i = 0; i < height; ++i) {
        board[i] = new int[width];
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }

    int total_max = 0;
    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            int part_max = placeTetromino(-1, -1, h, w, board[h][w], 1);
            if (total_max < part_max) total_max = part_max;
        }
    }

    int T_max = placeTTetromino();

    if (total_max < T_max) total_max = T_max;

    cout << total_max;

    for (int i = 0; i < height; ++i) {
        delete[] board[i];
    }
    delete board;
}