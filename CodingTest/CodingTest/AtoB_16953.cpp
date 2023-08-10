#include <iostream>

using namespace std;

typedef long long lld;
lld A = 0, B = 0;

int main() {
	cin >> A >> B;

	int stack = 0;
	while (B > A) {
		if (B % 10 == 1) {
			B /= 10;
		}
		else {
			if (B % 2 != 0) break;
			B /= 2;
		}
		stack++;
	}

	if (A == B) {
		cout << stack + 1 << "\n";
	}
	else {
		cout << "-1\n";
	}
}