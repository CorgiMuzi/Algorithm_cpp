#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> vvc;

int N, M;
vvc board;

void TiltLeft(vvc b) {
	
}

int EscapeMarble(int t, vvc b) {
	return 0;
}

int main() {
	cin >> N >> M;
	board = vvc(N, vector<char>(M));
	for(int r = 0; r < N; ++r) {
		for(int c = 0; c < M; ++c) {
			cin >> board[r][c];
		}
	}
	
	for(int r = 0; r < N; ++r) {
		for(int c = 0; c < M; ++c) {
			cout << board[r][c] << " ";
		}cout << "\n";
	}
	
	// int ans = EscapeMarble(10, board);
	// cout << ans;
}