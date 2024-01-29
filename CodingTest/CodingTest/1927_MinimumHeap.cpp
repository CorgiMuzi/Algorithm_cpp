#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int T;
	priority_queue<int, vector<int>, greater<int>> heap;

	scanf("%d", &T);

	while (T--) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd != 0) {
			heap.push(cmd);
		}
		else {
			if (heap.size() == 0) printf("0\n");
			else {
				printf("%d\n", heap.top());
				heap.pop();
			}
		}
	}
}