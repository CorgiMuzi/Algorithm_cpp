#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct Shark {
public:
	int r, c, s, d, z;
	bool isEmpty = true;
};

int R, C, M;
pii dir[5] = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
Shark sea[100][100];
int bucket = 0;

void Fishing(int fisher) {
	for (int r = 0; r < R; ++r) {
		if (!sea[r][fisher].isEmpty) {
			sea[r][fisher].isEmpty = true;
			bucket += sea[r][fisher].z;
			return;
		}
	}
}

void SharkMoving() {
	vector<Shark> alive;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (!sea[r][c].isEmpty) {
				alive.push_back(sea[r][c]);
				sea[r][c].isEmpty = true;
			}
		}
	}

	for (Shark& shark : alive) {
		int move;
		if (shark.d < 3) {
			// 위 아래
			move = shark.s % (2 * (R - 1));
			for(int pos = 1; pos <= move; ++pos) {
				shark.r += dir[shark.d].first;
				if(shark.r >= R) {
					shark.d = 1;
					shark.r = R - 2;
				}else if(shark.r < 0) {
					shark.d = 2;
					shark.r = 1;
				}
			}
		}
		else {
			move = shark.s % (2 * (C - 1));
			for(int pos = 1; pos <= move; ++pos) {
				shark.c += dir[shark.d].second;
				if(shark.c >= C) {
					shark.d = 4;
					shark.c = C - 2;
				}else if(shark.c < 0) {
					shark.d = 3;
					shark.c = 1;
				}
			}
		}
	}

	for (Shark& shark : alive) {
		if (sea[shark.r][shark.c].isEmpty || sea[shark.r][shark.c].z < shark.z) {
			sea[shark.r][shark.c] = shark;
		}
	}
}

void Process(int fisher) {
	while (++fisher < C) {
		Fishing(fisher);
		SharkMoving();
	}
}

int main() {
	cin >> R >> C >> M;

	if(M == 0) {
		cout << 0;
		return 0;
	}

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			sea[r][c] = Shark();
		}
	}

	for (int m = 0; m < M; ++m) {
		Shark shark;
		cin >> shark.r >> shark.c >> shark.s >> shark.d >> shark.z;
		shark.r--;
		shark.c--;
		shark.isEmpty = false;

		sea[shark.r][shark.c] = shark;
	}
	
	Process(-1);

	cout << bucket;
}