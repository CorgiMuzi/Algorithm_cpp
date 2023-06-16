#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MBTIFriends(const vector<string>& MBTI) {
	int ans = 8; // 최대 심리적 거리

	if (MBTI.size() > 32) {
		return 0;
	}

	for (int i = 0; i < MBTI.size() - 2; ++i) {
		for (int j = i + 1; j < MBTI.size() - 1; ++j) {
			for (int k = j + 1; k < MBTI.size(); ++k) {
				int IJ_diff = 0, IK_diff = 0, JK_diff = 0;
				for (int idx = 0; idx < 4; ++idx) {
					if (MBTI[i][idx] != MBTI[j][idx]) {
						IJ_diff++;
					}

					if (MBTI[i][idx] != MBTI[k][idx]) {
						IK_diff++;
					}

					if (MBTI[j][idx] != MBTI[k][idx]) {
						JK_diff++;
					}
				}

				ans = min(ans, IJ_diff + IK_diff + JK_diff);
			}
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int students;
		cin >> students;

		vector<string> MBTI(students);
		for (int i = 0; i < students; ++i) {
			cin >> MBTI[i];
		}

		int ans = MBTIFriends(MBTI);

		cout << ans << '\n';
	}
}