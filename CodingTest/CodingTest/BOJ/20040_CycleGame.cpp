#include <iostream>

using namespace std;

int parent[500000];
int n, m;
int ans = 0;

int GetParent(int self) {
	if(self == parent[self]) return self;
	return parent[self] = GetParent(parent[self]);
}

bool Union(int p1, int p2) {
	p1 = GetParent(p1);
	p2 = GetParent(p2);

	if(p1 != p2) {
		if(p1 < p2) parent[p2] = p1;
		else parent[p1] = p2;

		return true;
	}
	return false;
}

int main() {
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		parent[i] = i;
	}

	for(int i = 1; i <= m; ++i) {
		int beg, end;
		cin >> beg >> end;
		if(!Union(beg, end)) {
			ans = i;
			break;
		}
	}

	cout << ans;
}