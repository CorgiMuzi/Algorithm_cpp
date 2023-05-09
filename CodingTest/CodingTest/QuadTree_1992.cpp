#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

int** vid;

bool isSamePixelColor(int x, int y, int size) {
    int defaultColor = vid[x][y];
    for (int r = x; r < x + size; ++r) {
        for (int c = y; c < y + size; ++c) {
            if (defaultColor != vid[r][c]) return false;
        }
    }

    return true;
}

void analyzeVideo(int x, int y, int size, vector<char>& buffer) {
    if (isSamePixelColor(x, y, size)) {
        buffer.push_back(vid[x][y] + '0');
    }
    else {
        buffer.push_back('(');
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
                int pixelSize = size / 2;
                analyzeVideo(x + r * pixelSize, y + c * pixelSize, pixelSize, buffer);
            }
        }
        buffer.push_back(')');
    }
}

int main() {
    int N;
    cin >> N;

    vid = new int* [N];
    for (int i = 0; i < N; ++i) {
        vid[i] = new int[N];
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            char ch;
            cin >> ch;
            vid[r][c] = ch - '0';
        }
    }

    vector<char> buffer;
    analyzeVideo(0, 0, N, buffer);

    for (const auto& elem : buffer) {
        cout << elem;
    }
}