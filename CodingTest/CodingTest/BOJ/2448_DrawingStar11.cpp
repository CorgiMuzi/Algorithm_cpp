#include <iostream>

#define MAX_SIZE 3072

using namespace std;

int pyramid[MAX_SIZE + 1][2 * MAX_SIZE] = { 0, };
int N = 0;

void drawStar(int height, int x, int y) {
	if (height == 3) {
		pyramid[y][x] = pyramid[y + 1][x - 1] = pyramid[y + 1][x + 1] = 1;
		for (int i = 0; i < 5; ++i) {
			pyramid[y + 2][x - 2 + i] = 1;
		}
	}
	else {
		drawStar(height / 2, x, y);
		drawStar(height / 2, x - height / 2, y + height / 2);
		drawStar(height / 2, x + height / 2, y + height / 2);
	}
}

int main() {
	cin >> N;

	drawStar(N, N, 1);

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= 2 * N; ++c) {
			cout << (pyramid[r][c] == 1 ? '*' : ' ');
		}
		cout << "\n";
	}
}