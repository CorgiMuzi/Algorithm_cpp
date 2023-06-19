#include <cstdio>

using namespace std;

int parent[1000001];

int getParent(int x) {
	if (x == parent[x]) return x;

	return parent[x] = getParent(parent[x]);
}

void mergeSet(int arg1, int arg2) {
	int p_arg1 = getParent(arg1), p_arg2 = getParent(arg2);
	if (p_arg1 > p_arg2) parent[p_arg1] = p_arg2;
	else parent[p_arg2] = p_arg1;
}

bool isSameSet(int arg1, int arg2) {
	int p_arg1 = getParent(arg1), p_arg2 = getParent(arg2);
	if (p_arg1 == p_arg2) return true;
	else return false;
}

int main() {
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; ++i) {
		parent[i] = i;
	}

	while (M--) {
		int cmd = 0;
		scanf("%d", &cmd);

		int arg1 = 0, arg2 = 0;

		scanf("%d %d", &arg1, &arg2);
		if (cmd == 1) {
			printf((isSameSet(arg1, arg2) ? "YES\n" : "NO\n"));
		}
		else if (cmd == 0) {
			mergeSet(arg1, arg2);
		}
	}
}