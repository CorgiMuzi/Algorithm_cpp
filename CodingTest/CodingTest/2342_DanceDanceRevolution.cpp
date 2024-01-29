#include <iostream>
#include <vector>

#define INF 400000

using namespace std;

vector<int> platforms;
int minEnergy[5][5][100000];
int energyCost[5][5] = {
	{0, 2, 2, 2, 2},
	{0, 1, 3, 4, 3},
	{0, 3, 1, 3, 4},
	{0, 4, 3, 1, 3},
	{0, 3, 4, 3, 1}
};

int playDDR(int left, int right, vector<int>::iterator platform) {
	if (platform == platforms.end()) return 0;
	if (minEnergy[left][right][platform - platforms.begin()] != 0) return minEnergy[left][right][platform - platforms.begin()] ;
	
	minEnergy[left][right][platform - platforms.begin()] = min(playDDR(*platform, right, platform + 1) + energyCost[left][*platform], playDDR(left, *platform, platform + 1) + energyCost[right][*platform]);
	return minEnergy[left][right][platform - platforms.begin()];
}

int main() {
	// 눌러야 하는 플랫폼 번호
	int platformToPress = 0;

	while (cin >> platformToPress) {
		// 0번이 입력될때까지 반복
		if (platformToPress == 0) break;
		platforms.push_back(platformToPress);
	}

	// 최소 에너시 소모량 표시
	cout << playDDR(0, 0, platforms.begin());
}