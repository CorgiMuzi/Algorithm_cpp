#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

void postorder(int left, int right) {
	if (left >= right) return;
	if (right - 1 == left) {
		cout << tree[left] << "\n";
		return;
	}
	
	int mid = left + 1;
	while (mid < right) {
		if (tree[mid] > tree[left]) break;
		mid++;
	}

	postorder(left + 1, mid);
	postorder(mid, right);

	cout << tree[left] << "\n";
}

int main() {
	int key = 0;

	while (cin >> key) {
		tree.push_back(key);
	}

	postorder(0, tree.size());
}