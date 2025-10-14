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
	// ������ �ϴ� �÷��� ��ȣ
	int platformToPress = 0;

	while (cin >> platformToPress) {
		// 0���� �Էµɶ����� �ݺ�
		if (platformToPress == 0) break;
		platforms.push_back(platformToPress);
	}

	// �ּ� ���ʽ� �Ҹ� ǥ��
	cout << playDDR(0, 0, platforms.begin());
}