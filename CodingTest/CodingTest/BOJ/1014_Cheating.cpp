#include <iostream>
#include <vector>

using namespace std;

int N, M;
int examinee[10];
int seats[10][1 << 10];
vector<int> frontLine;

void FirstSeat(int idx, int line) {
	if (idx == M) {
		frontLine.push_back(line);
		return;
	}

	FirstSeat(idx + 1, line);
	if (idx - 1 >= 0 && line & (1 << (idx - 1))) return;
	FirstSeat(idx + 1, line | (1 << idx));
}

int TakeSeats(int row, int lastLine) {
	if (row == N) return 0;
	if(-1 < seats[row][lastLine]) return seats[row][lastLine];
	
	int maxStudent = 0;
	for (const int& mask : frontLine) {
		int curLine = 0;
		int student = 0;
		
		for (int idx = 0; idx < M; ++idx) {
			if ((mask & (1 << idx)) == 0) continue;
			if ((examinee[row] & (1 << idx)) == 0) continue;
			if(idx - 1 >= 0 && (lastLine & (1 << (idx - 1)))) continue;
			if(idx + 1 < M && (lastLine & (1 << (idx + 1)))) continue;
			
			student++;
			curLine |= (1 << idx);
		}

		maxStudent = max(maxStudent, TakeSeats(row + 1, curLine) + student);
	}

	seats[row][lastLine] = maxStudent;
	return maxStudent;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--) {
		frontLine.clear();
		fill_n(examinee, sizeof(examinee) / sizeof(*examinee), 0);
		fill_n(*seats, sizeof(seats) / sizeof(**seats), -1);
		cin >> N >> M;
		for (int r = 0; r < N; ++r) {
			for (int c = M - 1; c >= 0; --c) {
				char desk;
				cin >> desk;
				if (desk == '.') examinee[r] |= (1 << c);
			}
		}

		FirstSeat(0, 0);

		cout << TakeSeats(0, 0) << "\n";
	}
}