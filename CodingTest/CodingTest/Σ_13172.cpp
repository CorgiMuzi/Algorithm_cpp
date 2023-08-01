#include <iostream>
#include <cmath>

#define MOD 1000000007

using namespace std;
typedef long long lld;

lld gcd(lld m, lld n) {
	return n ? gcd(n, m % n) : m;
}

lld powlld(lld base, lld mult) {
	if (mult == 1) return base;
	if (mult % 2 == 1) {
		return base * powlld(base, mult - 1) % MOD;
	}

	lld half = powlld(base, mult / 2);
	return (half * half) % MOD;
}

int main() {
	int dice = 0;
	cin >> dice;

	lld ans = 0;
	for (int i = 0; i < dice; ++i) {
		lld face = 0, sum = 0;
		cin >> face >> sum;
		
		lld divisor = gcd(face, sum);
		face /= divisor;
		sum /= divisor;

		int inverseElement = powlld(face, MOD - 2);
		ans += sum * inverseElement % MOD;
		ans %= MOD;
	}

	cout << ans;
}