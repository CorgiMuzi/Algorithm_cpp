#include <iostream>

using namespace std;

void DrawStar(int starSize) {
	int subStarSize = starSize / 3;

	if (subStarSize == 0) return;

	for (int row = 0; row < 3; ++row){
		for (int col = 0; col < 3; ++col) {
			if (row == 1 && col == 1) {
				for (int subRow = 0; subRow < subStarSize; ++subRow) {
					for (int subCol = 0; subCol < subStarSize; ++subCol) {
						if (subRow == 0 || subRow == subStarSize-1) cout << "*";
						else if (subCol == 0 || subCol == subStarSize - 1) {
							cout << "*";
						}
					}
					cout << "\n";
				}
			}
			else {
				DrawStar(subStarSize);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	DrawStar(N);

	return 0;
}