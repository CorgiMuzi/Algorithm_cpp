#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
enum DIR {
	L = 0,
	R,
	U,
	D
};
char pipeMap[1000][1000];
int parent[1'000'000];
bool endpoint[1'000'000];
int row, col;

int GetParent(int self) {
	if(self == parent[self]) return self;
	return parent[self] = GetParent(parent[self]);
}

void Union(int p1, int p2) {
	p1 = GetParent(p1);
	p2 = GetParent(p2);

	if(p1 != p2) {
		if(p1 < p2) parent[p2] = p1;
		else parent[p1] = p2;
	}
}

void PlayPipe() {
	for(int r = 0; r < row; ++r) {
		for(int c = 0; c < col; ++c) {
			int cur = r * col + c;
			int nxt;
			if(pipeMap[r][c] == 'L') {
				nxt = (r + dir[L].first) * col + c + dir[L].second;
			}else if(pipeMap[r][c] == 'R') {
				nxt = (r + dir[R].first) * col + c + dir[R].second;
			}else if(pipeMap[r][c] == 'D') {
				nxt = (r + dir[D].first) * col + c + dir[D].second;
			}else {
				nxt = (r + dir[U].first) * col + c + dir[U].second;
			}

			Union(cur, nxt);
		}
	}
}

int main() {
	cin >> row >> col;
	for(int r = 0; r < row; ++r) {
		for(int c = 0; c < col; ++c) {
			cin >> pipeMap[r][c];
			parent[r * col + c] = r * col + c;
		}
	}

	PlayPipe();
	
	for(int i = 0; i < row * col; ++i) {
		parent[i] = GetParent(i);
		if(!endpoint[parent[i]]) endpoint[parent[i]] = true; 
	}

	int ans = count(endpoint, endpoint + row * col, true);
	cout << ans;
}