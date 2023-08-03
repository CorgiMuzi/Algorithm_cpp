#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node* parent;
	int self = -1;
};

int numOfNode = 0;
vector<int> links[100001];
Node tree[100001];

void linkChildNode(Node* pNode) {
	if (links[pNode->self].empty()) return;

	for (const int& childNum : links[pNode->self]) {
		if (tree[childNum].self != -1) continue;
		Node childNode;
		childNode.parent = pNode;
		childNode.self = childNum;

		tree[childNum] = childNode;

		linkChildNode(&tree[childNum]);
	}
}

int main() {
	cin >> numOfNode;
	for (int i = 0; i < numOfNode - 1; ++i) {
		int p1 = 0, p2 = 0;
		cin >> p1 >> p2;

		links[p1].push_back(p2);
		links[p2].push_back(p1);
	}

	tree[1] = { nullptr, 1 };
	linkChildNode(&tree[1]);

	for (int i = 2; i <= numOfNode; ++i) {
		cout << tree[i].parent->self << "\n";
	}
}