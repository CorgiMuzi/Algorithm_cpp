#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spaceSize, elapsedTime = 0, sharkSize = 2, shark_h = 0, shark_w = 0, sharkExp = 0;
int space[21][21];

int hDir[4] = { -1, 0, 0, 1 };
int wDir[4] = { 0, -1, 1, 0 };

// ����� ���� Ž�� -> �� ���̸� ã�Ƽ� �Ծ��� ��� True, ��ã���� ��� False ��ȯ
bool searchingPrey() {
	queue<pair<int, int>> searchingNodes; // �� ������ Ž���� ĭ
	pair<int, int> prey = make_pair(spaceSize, spaceSize); // �� ���� ����
	searchingNodes.push(make_pair(shark_h, shark_w)); // ���� ��� ��ġ���� Ž�� ����

	// ������ �� ���̸� �Դµ� ����� �ð� || �� ���̸� Ž���ϴµ� ����� �ð� || �� �ҿ��� �ð����� �� Ž�� ������ ĭ ��
	int eatTime = 0, expectTime = 1, nodesPerSec = searchingNodes.size();
	vector<vector<bool>> isVisited(spaceSize, vector<bool>(spaceSize, false));

	// BFS
	while (!searchingNodes.empty()) {
		// �� Ž�� ������ ��� ĭ�� Ž������ ��
		if (nodesPerSec == 0) {
			if (prey.first != spaceSize) break; // ���̸� ã�Ҵٸ� ����
			nodesPerSec = searchingNodes.size(); // 1�� �Ŀ� �� Ž�� ������ ĭ �� ���� ����
			expectTime++; // Ž���ϴµ� ����� �ð��� 1�� �߰�
		}

		pair<int, int> cur_node = searchingNodes.front(); // Ž���Ϸ��� �ϴ� ĭ ��ġ
		searchingNodes.pop();
		nodesPerSec--;

		int h = cur_node.first, w = cur_node.second;
		isVisited[h][w] = true;

		for (int i = 0; i < 4; ++i) {
			int mh = h + hDir[i], mw = w + wDir[i]; // ���� �켱, ���� �켱

			if (mh < 0 || mw < 0 || mh >= spaceSize || mw >= spaceSize || space[mh][mw] > sharkSize || isVisited[mh][mw]) continue;

			if (space[mh][mw] != 0 && space[mh][mw] < sharkSize) {
				// ���� ���϶� ���� ���� ������ ���̷� ����
				if (prey.first == mh && prey.second > mw) {
					prey.second = mw;
					eatTime = expectTime;
				}
				// ���� ���� ������ ���̷� ����
				else if (prey.first > mh) {
					prey.first = mh;
					prey.second = mw;
					eatTime = expectTime;
				}
			}

			searchingNodes.push(make_pair(mh, mw));
		}
	}

	// ���̰� Ž�� �Ǿ��� ���
	if (prey.first != spaceSize) {
		// ����� ��ġ�� ���� ��ġ�� ����
		shark_h = prey.first;
		shark_w = prey.second;

		// ���� �Ծ������
		space[shark_h][shark_w] = 0;
		elapsedTime += eatTime;
		// ��� ���� ���� ����
		if (++sharkExp == sharkSize) {
			sharkSize++;
			sharkExp = 0;
		}
		return true;
	}

	return false;
}

int main() {
	cin >> spaceSize;

	for (int i = 0; i < spaceSize; ++i) {
		for (int j = 0; j < spaceSize; ++j) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				shark_h = i;
				shark_w = j;
				space[i][j] = 0;
			}
		}
	}

	bool isSharkHungry = searchingPrey();
	// ���̻� �� ���̸� ��ã�� ���������� �ݺ�
	while (isSharkHungry) {
		isSharkHungry = searchingPrey();
	}

	// �ҿ�� �ð� ��ȯ
	cout << elapsedTime;
}