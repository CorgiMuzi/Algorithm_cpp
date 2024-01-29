#include <iostream>
#include <algorithm>

using namespace std;

typedef long long lld;

bool sieve[1000001];
lld lower, upper;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> lower >> upper;

	for(lld i = 2; i * i <= upper; ++i) {
		lld square = i * i;
		lld n = lower / square;
		if(lower % (i * i)) n++;
		for(lld j = n; j * square <= upper; ++j) {
			sieve[j * square - lower] = true;
			n++;
		}
	}

	lld ans = count(sieve, sieve + (upper - lower) + 1, false);
	cout << ans;
}
