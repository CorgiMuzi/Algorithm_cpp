#include <iostream>
#include <cmath>

using namespace std;

typedef long long lld;

lld A = 0, B = 0, C = 0;
lld one[55];

lld countNumber(lld arg) {
	lld ret = arg & 1;
	for (int i = 54; i > 0; --i) {
		if (arg & (1LL << i)) {
			ret += one[i - 1] + (arg - (1LL << i) + 1);
			arg -= 1LL << i;
		}
	}

	return ret;a
}

int main() {
	cin >> A >> B;

	one[0] = 1;
	for (int i = 1; i < 55; ++i) {
		one[i] = 2 * one[i - 1] + (1LL << i);
	}
	
	cout << countNumber(B) - countNumber(A - 1);
}