#include <iostream>

using namespace std;

int main() {
	int cur = 0, asc = 0, desc = 0;
	for (int i = 1; i <= 8; ++i) {
		cin >> cur;
		if (cur == i) asc++;
		else if (cur == 8 - i + 1) desc++;
	}

	if (asc == 8) cout << "ascending\n";
	else if (desc == 8) cout << "descending\n";
	else cout << "mixed\n";
}