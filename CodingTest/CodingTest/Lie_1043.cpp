#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getRoot(int node) {
	if (node == parent[node]) return node;

	return parent[node] = getRoot(parent[node]);
}

void mergeGroups(int n1, int n2) {
	int r1 = getRoot(n1), r2 = getRoot(n2);
	if (r1 == r2) return;

	if (r1 > r2) parent[r1] = r2;
	else parent[r2] = r1;
}

bool isSameRoot(int n1, int n2) {
	int r1 = getRoot(n1), r2 = getRoot(n2);
	if (r1 == r2) return true;
	else return false;
}

int main() {
	int people = 0, parties = 0;
	cin >> people >> parties;

	for (int person = 0; person <= people; ++person) {
		parent.push_back(person);
	}

	int wb = 0, wbRoot = 0;
	cin >> wb;

	int firstWb = 0;
	for (int i = 0; i < wb; ++i) {
		if (firstWb == 0) cin >> firstWb;
		else {
			int _wb = 0;
			cin >> _wb;
			mergeGroups(firstWb, _wb);
		}
	}

	wbRoot = getRoot(firstWb);

	vector<int> roots;
	for (int i = 0; i < parties; ++i) {
		int participants = 0;
		cin >> participants;

		if (participants == 1) {
			int p = 0;
			cin >> p;
			roots.push_back(getRoot(p));
		}
		else {
			int last = 0;
			for (int j = 0; j < participants; ++j) {
				int p = 0;
				cin >> p;
				if (j == 0) last = p;
				else {
					mergeGroups(last, p);
				}
			}

			roots.push_back(getRoot(last));
		}
	}

	int ans = 0;
	for (vector<int>::size_type i = 0; i < roots.size(); ++i) {
		if (getRoot(roots[i]) != getRoot(wbRoot)) ans++;
	}
	cout << ans;
}
