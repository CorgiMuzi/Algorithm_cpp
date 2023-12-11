#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int parent[1'000'000];
int depth[1'000'000];
int used[1'000'000];
bool board[1000][1000];
int N, M;
pii dir[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int GetParent(int self) {
	if (self == parent[self]) return self;
	return parent[self] = GetParent(parent[self]);
}

bool Union(int p1, int p2) {
	p1 = GetParent(p1);
	p2 = GetParent(p2);

	if (p1 != p2) {
		if (p1 < p2) {
			parent[p2] = p1;
			depth[p1] += depth[p2];
		}
		else {
			parent[p1] = p2;
			depth[p2] += depth[p1];
		}

		return true;
	}

	return false;
}

void CheckUnion(int row, int col) {
	for (const pii& d : dir) {
		int nxt_r = row + d.first;
		int nxt_c = col + d.second;
		if (nxt_r < 0 || nxt_c < 0 || nxt_r >= N || nxt_c >= M || board[nxt_r][nxt_c]) continue;
		if (Union(row * M + col, nxt_r * M + nxt_c)) {
			CheckUnion(nxt_r, nxt_c);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			char num;
			cin >> num;
			if (num == '1') board[r][c] = true;
			else board[r][c] = false;

			parent[r * M + c] = r * M + c;
			depth[r * M + c] = 1;
		}
	}

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (!board[r][c]) CheckUnion(r, c);
		}
	}

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			int side = 0;
			if (board[r][c]) {
				side = 1;
				fill_n(used, N * M, -1);
				int stack = 0;
				for (const pii& d : dir) {
					int nxt_r = r + d.first;
					int nxt_c = c + d.second;

					if (nxt_r < 0 || nxt_c < 0 || nxt_r >= N || nxt_c >= M || board[nxt_r][nxt_c]) continue;

					int nxt = GetParent(nxt_r * M + nxt_c);
					if (find(used, used + stack, nxt) != used + stack) continue;
					used[stack++] = nxt;
				}

				for (const int& p : used) {
					if(p == -1) break;
					side += depth[p];
				}
			}

			cout << (side % 10);
		}
		cout << "\n";
	}
}