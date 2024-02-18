#include <iostream>

using namespace std;

bool IsPrime[100001];
int PrimeDivisor[100001];
int A, B;

int main() {
	cin >> A >> B;

	fill_n(IsPrime, B + 1, true);
	fill_n(PrimeDivisor, B + 1, 0);
	IsPrime[0] = IsPrime[1] = false;

	for (int i = 2; i <= B; ++i) {
		if (!IsPrime[i]) continue;
		for (int j = i + i; j <= B; j += i) {
			IsPrime[j] = false;
			int buffer = j;
			while (buffer % i == 0) {
				PrimeDivisor[j]++;
				buffer /= i;
			}
		}
	}
	
	int UnderPrime = 0;
	for (int i = A; i <= B; ++i) {
		if (IsPrime[PrimeDivisor[i]]) UnderPrime++;
	}

	cout << UnderPrime;
}