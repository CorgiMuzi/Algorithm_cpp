#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spaceSize, elapsedTime = 0, sharkSize = 2, shark_h = 0, shark_w = 0, sharkExp = 0;
int space[21][21];

int hDir[4] = { -1, 0, 0, 1 };
int wDir[4] = { 0, -1, 1, 0 };

// 상어의 먹이 탐색 -> 상어가 먹이를 찾아서 먹었을 경우 True, 못찾았을 경우 False 반환
bool searchingPrey() {
	queue<pair<int, int>> searchingNodes; // 상어가 앞으로 탐색할 칸
	pair<int, int> prey = make_pair(spaceSize, spaceSize); // 상어가 먹을 먹이
	searchingNodes.push(make_pair(shark_h, shark_w)); // 현재 상어 위치부터 탐색 시작

	// 실제로 상어가 먹이를 먹는데 사용한 시간 || 상어가 먹이를 탐색하는데 사용한 시간 || 각 소요한 시간마다 상어가 탐색 가능한 칸 수
	int eatTime = 0, expectTime = 1, nodesPerSec = searchingNodes.size();
	vector<vector<bool>> isVisited(spaceSize, vector<bool>(spaceSize, false));

	// BFS
	while (!searchingNodes.empty()) {
		// 상어가 탐색 가능한 모든 칸을 탐색했을 때
		if (nodesPerSec == 0) {
			if (prey.first != spaceSize) break; // 먹이를 찾았다면 종료
			nodesPerSec = searchingNodes.size(); // 1초 후에 상어가 탐색 가능한 칸 수 새로 갱신
			expectTime++; // 탐색하는데 사용한 시간에 1초 추가
		}

		pair<int, int> cur_node = searchingNodes.front(); // 탐색하려고 하는 칸 위치
		searchingNodes.pop();
		nodesPerSec--;

		int h = cur_node.first, w = cur_node.second;
		isVisited[h][w] = true;

		for (int i = 0; i < 4; ++i) {
			int mh = h + hDir[i], mw = w + wDir[i]; // 위쪽 우선, 왼쪽 우선

			if (mh < 0 || mw < 0 || mh >= spaceSize || mw >= spaceSize || space[mh][mw] > sharkSize || isVisited[mh][mw]) continue;

			if (space[mh][mw] != 0 && space[mh][mw] < sharkSize) {
				// 같은 행일때 왼쪽 열의 생선을 먹이로 설정
				if (prey.first == mh && prey.second > mw) {
					prey.second = mw;
					eatTime = expectTime;
				}
				// 위쪽 행의 생선을 먹이로 설정
				else if (prey.first > mh) {
					prey.first = mh;
					prey.second = mw;
					eatTime = expectTime;
				}
			}

			searchingNodes.push(make_pair(mh, mw));
		}
	}

	// 먹이가 탐색 되었을 경우
	if (prey.first != spaceSize) {
		// 상어의 위치를 먹이 위치로 변경
		shark_h = prey.first;
		shark_w = prey.second;

		// 먹이 먹어버리기
		space[shark_h][shark_w] = 0;
		elapsedTime += eatTime;
		// 상어 성장 상태 적용
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
	// 더이상 상어가 먹이를 못찾아 먹을때까지 반복
	while (isSharkHungry) {
		isSharkHungry = searchingPrey();
	}

	// 소요된 시간 반환
	cout << elapsedTime;
}