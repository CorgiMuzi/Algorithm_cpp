#include <iostream>
#include <vector>

using namespace std;

char red = 'R', green = 'G', blue = 'B', yellow = 'Y';
int image_size;
char** image;
bool** isVisited;

int dirX[4] = { 1, -1, 0, 0 }, dirY[4] = { 0, 0, 1, -1 };

void analyzeImage(int x, int y) {
    isVisited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dirX[i], new_y = y + dirY[i];

        if (new_x >= image_size || new_y >= image_size || new_x < 0 || new_y < 0) continue;
        if (!isVisited[new_y][new_x] && image[new_y][new_x] == image[y][x]) {
            analyzeImage(new_x, new_y);
        }
    }

}

int main() {
    cin >> image_size;
    image = new char* [image_size];
    isVisited = new bool* [image_size];

    for (int i = 0; i < image_size; ++i) {
        image[i] = new char[image_size];
        isVisited[i] = new bool[image_size];
    }

    for (int i = 0; i < image_size; ++i) {
        for (int j = 0; j < image_size; ++j) {
            cin >> image[i][j];
        }
    }

    int pixelArea = 0;
    for (int r = 0; r < image_size; ++r) {
        for (int c = 0; c < image_size; ++c) {
            if (!isVisited[r][c]) {
                analyzeImage(c, r);
                pixelArea++;
            }
        }
    }
    cout << pixelArea << " ";

    pixelArea = 0;
    for (int i = 0; i < image_size; ++i) {
        for (int j = 0; j < image_size; ++j) {
            if (image[i][j] == 'G') {
                image[i][j] = 'R';
            }

            isVisited[i][j] = false;
        }
    }

    for (int r = 0; r < image_size; ++r) {
        for (int c = 0; c < image_size; ++c) {
            if (!isVisited[r][c]) {
                analyzeImage(c, r);
                pixelArea++;
            }
        }
    }

    cout << pixelArea;
}