#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;

int N, M;
int ans = 11;

vvc board;
pii hole;

void flipBoard(vvc& b) {
	vvc bb = vvc(b[0].size(), vector<char>(b.size()));
	for(int r = 0; r < b.size(); ++r) {
		for(int c = 0; c < b[r].size(); ++c) {
			bb[c][r] = b[r][c];
		}
	}

	b = bb;
}
int TiltLeft(pii& r, pii& b, vvc& bb) {
	if (b.first == hole.first && b.second > hole.second) {
		if(find(bb[b.first].begin() + hole.second, bb[b.first].begin() + b.second, '#') == bb[b.first].begin() + b.second) return -1;
	}
	if (r.first == hole.first && r.second > hole.second) {
		if(find(bb[r.first].begin() + hole.second, bb[r.first].begin() + r.second, '#') == bb[r.first].begin() + r.second) return 1;
	}

	bb[r.first][r.second] = '.';
	bb[b.first][b.second] = '.';

	if (r.first == b.first) {
		pii* left, *right;
		if (r.second < b.second) {
			left = &r;
			right = &b;
		}
		else {
			left = &b;
			right = &r;
		}

		for (int c = left->second; c >= 0; --c) {
			if (bb[left->first][c] == '#') {
				left->second = c + 1;
				break;
			}
		}

		for (int c = right->second; c >= 0; --c) {
			if (bb[right->first][c] == '#' || c == left->second) {
				right->second = c + 1;
				break;
			}
		}
	}else {
		for(int c = r.second; c >= 0; --c) {
			if(bb[r.first][c] == '#') {
				r.second = c + 1;
				break;
			}
		}
		
		for(int c = b.second; c >= 0; --c) {
			if(bb[b.first][c] == '#') {
				b.second = c + 1;
				break;
			}
		}
	}
	
	bb[r.first][r.second] = 'R';
	bb[b.first][b.second] = 'B';

	return 0;
}
int TiltRight(pii& r, pii& b, vvc& bb) {
	if (b.first == hole.first && b.second < hole.second) {
		if(find(bb[b.first].begin() + b.second, bb[b.first].begin() + hole.second, '#') == bb[b.first].begin() + hole.second) return -1;
	}
	if (r.first == hole.first && r.second < hole.second) {
		if(find(bb[r.first].begin() + r.second, bb[r.first].begin() + hole.second, '#') == bb[r.first].begin() + hole.second) return 1;
	}

	bb[r.first][r.second] = '.';
	bb[b.first][b.second] = '.';

	if (r.first == b.first) {
		pii* left, *right;
		if (r.second < b.second) {
			left = &r;
			right = &b;
		}
		else {
			left = &b;
			right = &r;
		}

		for (int c = right->second; c < bb[right->first].size(); ++c) {
			if (bb[right->first][c] == '#') {
				right->second = c - 1;
				break;
			}
		}
		
		for (int c = left->second; c < bb[left->first].size(); ++c) {
			if (bb[left->first][c] == '#' || c == right->second) {
				left->second = c - 1;
				break;
			}
		}
	}else {
		for(int c = r.second; c < M; ++c) {
			if(bb[r.first][c] == '#') {
				r.second = c - 1;
				break;
			}
		}
		
		for(int c = b.second; c < M; ++c) {
			if(bb[b.first][c] == '#') {
				b.second = c - 1;
				break;
			}
		}
	}
	
	bb[r.first][r.second] = 'R';
	bb[b.first][b.second] = 'B';

	return 0;
}
int TiltUp(pii& r, pii& b, vvc& bb) {
	flipBoard(bb);
	swap(r.first, r.second);
	swap(b.first, b.second);
	swap(hole.first, hole.second);
	int res = TiltLeft(r, b, bb);
	swap(r.first, r.second);
	swap(b.first, b.second);
	swap(hole.first, hole.second);
	flipBoard(bb);
	
	return res;
}
int TiltDown(pii& r, pii& b, vvc& bb) {
	flipBoard(bb);
	swap(r.first, r.second);
	swap(b.first, b.second);
	swap(hole.first, hole.second);
	int res = TiltRight(r, b, bb);
	swap(r.first, r.second);
	swap(b.first, b.second);
	swap(hole.first, hole.second);
	flipBoard(bb);
	
	return res;
}

void EscapeMarble(int tilt, pii red, pii blue, vvc bb) {
	if(tilt == 11 || tilt > ans) return;

	pii r = red, b = blue;
	vvc bbb = bb;

	int res = TiltLeft(r, b, bbb);
	if(res == 1) {
		ans = min(ans, tilt);
		return;
	}
	if(res == -1 || bb != bbb) EscapeMarble(tilt + 1, r, b, bbb);

	r = red;
	b = blue;
	bbb = bb;

	res = TiltRight(r, b, bbb);
	if(res == 1) {
		ans = min(ans, tilt);
		return;
	}
	if(res == -1 || bb != bbb) EscapeMarble(tilt + 1, r, b, bbb);

	r = red;
	b = blue;
	bbb = bb;
	res = TiltUp(r, b, bbb);
	if(res == 1) {
		ans = min(ans, tilt);
		return;
	}
	
	if(res == -1 || bb != bbb) EscapeMarble(tilt + 1, r, b, bbb);

	r = red;
	b = blue;
	bbb = bb;
	
	res = TiltDown(r, b, bbb);
	if(res == 1) {
		ans = min(ans, tilt);
		return;
	}
	
	if(res == -1 || bb != bbb) EscapeMarble(tilt + 1, r, b, bbb);
}

int main() {
	cin >> N >> M;
	board = vvc(N, vector<char>(M));
	pii blue, red;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> board[r][c];
			if (board[r][c] == 'R') red = make_pair(r, c);
			else if (board[r][c] == 'B') blue = make_pair(r, c);
			else if (board[r][c] == 'O') hole = make_pair(r, c);
		}
	}

	EscapeMarble(1, red, blue, board);
	cout << (ans == 11 ? -1 : ans);
}