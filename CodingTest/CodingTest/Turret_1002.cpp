#include <iostream>

using namespace std;

int main() {
	int T = 0;
	cin >> T;

	while (T--) {
		int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dist = pow(x2 - x1, 2) + pow(y2 - y1, 2);
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1\n";
		}
		else if (dist == (r1 + r2) * (r1 + r2) || dist == (r1 - r2) * (r1 - r2)) {
			cout << "1\n";
		}
		else if (dist < (r1 + r2) * (r1 + r2) && dist > (r1 - r2) * (r1 - r2)) {
			cout << "2\n";
		}
		else {
			cout << "0\n";
		}


	}
}