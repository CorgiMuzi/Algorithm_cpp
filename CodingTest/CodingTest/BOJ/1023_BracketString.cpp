#include <iostream>

using namespace std;

typedef long long lld;

lld nbstr[51][101];

int N;
lld K;

string solve();

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	fill_n(&nbstr[0][0], 101, 1);
	nbstr[0][50] = 0;
	
	for(int r = 1; r <= N; ++r) {
		fill_n(&nbstr[r][0], 50, pow(2, r));
	}

	for(int r = 1; r <= N; ++r) {
		for(int c = 50; c <= 100; ++c) {
			nbstr[r][c] = nbstr[r - 1][c - 1] + nbstr[r - 1][c + 1];
		}
	}

	cout << solve();
}

string solve() {
	if(nbstr[N][50] > K) return "-1";


	
	//return ret; 
}
