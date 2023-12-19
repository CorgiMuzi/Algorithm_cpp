#include <iostream>
#include <algorithm>

using namespace std;

int enemies[2][10000];
int choragi[10001][3];
int N, W;
const int INF = 2e9;

void raid() {
	for(int i = 2; i <= N; ++i) {
		int outRaid = enemies[0][i - 2] + enemies[0][i - 1] <= W ? 1 : 2;
		int inRaid = enemies[1][i - 2] + enemies[1][i - 1] <= W ? 1 : 2;
		int colRaid = enemies[0][i - 1] + enemies[1][i - 1] <= W ? 1 : 2;

		choragi[i][0] = min({choragi[i - 1][0] + colRaid, choragi[i - 1][1] + outRaid + 1, choragi[i - 1][2] + inRaid + 1, choragi[i - 2][0] + outRaid + inRaid});
		choragi[i][1] = min(choragi[i - 1][2] + inRaid, choragi[i - 1][0] + 1);
		choragi[i][2] = min(choragi[i - 1][1] + outRaid, choragi[i - 1][0] + 1);
	}
}

int main() {
	int T; cin >> T;
	while(T--) {
		int raider = INF;
		cin >> N >> W;
		
		for(int line = 0; line < 2; ++line) {
			for(int section = 0; section < N; ++section) {
				cin >> enemies[line][section];
			}
		}

		if(N == 1) {
			raider = min(raider, (enemies[0][0] + enemies[1][0] <= W ? 1 : 2));
		}else {
			int outSector = enemies[0][0], inSector = enemies[1][0];

			choragi[0][0] = choragi[1][0] = 0;
			choragi[1][0] = enemies[0][0] + enemies[1][0] <= W ? 1 : 2;
			choragi[1][1] = choragi[1][2] = 1;
			raid();
			raider = min(raider, choragi[N][0]);

			if(enemies[0][0] + enemies[0][N - 1] <= W) {
				choragi[1][0] = 2;
				choragi[1][1] = choragi[1][2] = 1;
				enemies[0][0] = INF;
				raid();
				raider = min(raider, choragi[N][1]);
				enemies[0][0] = outSector;
			}

			if(enemies[1][0] + enemies[1][N - 1] <= W) {
				choragi[1][0] = 2;
				choragi[1][1] = choragi[1][2] = 1;
				enemies[1][0] = INF;
				raid();
				raider = min(raider, choragi[N][2]);
				enemies[1][0] = inSector;
			}

			if(enemies[0][0] + enemies[0][N - 1] <= W && enemies[1][0] + enemies[1][N - 1] <= W) {
				choragi[1][0] = 2;
				choragi[1][1] = choragi[1][2] = 1;
				enemies[0][0] = enemies[1][0] = INF;
				raid();
				raider = min(raider, choragi[N - 1][0]);
				enemies[0][0] = outSector;
				enemies[1][0] = inSector;
			}
		}

		cout << raider << "\n";
	}
}