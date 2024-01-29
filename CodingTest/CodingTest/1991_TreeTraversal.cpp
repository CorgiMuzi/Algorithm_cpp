#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N = 0;
map<char, vector<char>> tree;

void preorder(char p) {
	cout << p;
	for (int i = 0; i < 2; ++i) {
		if (tree[p][i] == '.') continue;
		preorder(tree[p][i]);
	}
}

void inorder(char p) {
	for (int i = 0; i < 2; ++i) {
		if (i == 1) cout << p;
		if (tree[p][i] == '.') continue;
		inorder(tree[p][i]);
	}
}

void postorder(char p) {
	for (int i = 0; i < 2; ++i) {
		if (tree[p][i] == '.') continue;
		postorder(tree[p][i]);
	}
	cout << p;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		char parent;
		cin >> parent;
		char lchild, rchild;
		cin >> lchild >> rchild;
		tree[parent].push_back(lchild);
		tree[parent].push_back(rchild);
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}