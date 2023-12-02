#include <iostream>

using namespace std;

int main() {
	int h = 0, m = 0;
	cin >> h >> m;

	int t;
	cin >> t;

	if (t >= 60) {
		h += (t / 60);
		t %= 60;
	}

	m += t;
	if (m >= 60) {
		h++;
		m -= 60;
	}

	if (h >= 24) h -= 24;

	cout << h << " " << m;
}