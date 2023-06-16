#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int univ_width = 0, univ_height = 0;
int hDir[4] = { -1, 1, 0, 0 };
int wDir[4] = { 0, 0, -1, 1 };

int roamingCampus(const vector<string>& univ, pair<int, int> st) {
	int ret = 0;

	vector<vector<bool>> isVisited(univ_height, vector<bool>(univ_width, false));
	queue<pair<int, int>> rooms;
	rooms.push(st);

	while (!rooms.empty()) {
		// 현재 헌내기 위치
		pair<int, int> cur_st = rooms.front();
		rooms.pop();

		if (univ[cur_st.first][cur_st.second] == 'P') ret++;

		for (int i = 0; i < 4; ++i) {
			int mh = cur_st.first + hDir[i], mw = cur_st.second + wDir[i];
			if (mh >= univ_height || mh < 0 || mw >= univ_width || mw < 0 || univ[mh][mw] == 'X' || isVisited[mh][mw]) continue;
			isVisited[mh][mw] = true;
			rooms.push(make_pair(mh, mw));
		}
	}

	return ret;
}

int main() {
	cin >> univ_height >> univ_width;
	vector<string> univ(univ_height);
	// 헌내기 위치
	pair<int, int> oldStudent(-1, -1);
	// 캠퍼스 내 구조 및 학생 위치 입력
	for (vector<vector<int>>::size_type r = 0; r < univ_height; ++r) {
		cin >> univ[r];
		if (univ[r].find('I') != string::npos) {
			oldStudent.first = r;
			oldStudent.second = univ[r].find('I');
		}
	}

	int ans = roamingCampus(univ, oldStudent);

	if (ans == 0) {
		cout << "TT";
	}
	else {
		cout << ans;
	}
}