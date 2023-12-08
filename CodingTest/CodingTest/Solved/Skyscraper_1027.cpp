#include <iostream>

using namespace std;

typedef long long lld;
typedef pair<lld, lld> pll;

int N;
int b[50];
int ans = 0;

bool CCW(pll p1, pll p2, bool rHandDir) {
	lld dir = p1.first * p2.second - p1.second * p2.first; 
	return rHandDir ? dir > 0 : dir < 0;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> b[i];
	}

	for(int i = 0; i < N; ++i) {
		int lCount = 0, rCount = 0;
		lld cx =0, cy = 0;
		for(int j = i - 1; j >= 0; --j) {
			if(j == i - 1) {
				lCount++;
				cx = j - i;
				cy = b[j] - b[i];
				continue;
			}

			if(CCW(make_pair(cx, cy), make_pair(j - i, b[j] - b[i]), false)) {
				lCount++;
				cx = j - i;
				cy = b[j] - b[i];
			}
		}
		
		for(int j = i + 1; j < N; ++j) {
			if(j == i + 1) {
				rCount++;
				cx = j - i;
				cy = b[j] - b[i];
				continue;
			}

			if(CCW(make_pair(cx, cy), make_pair(j - i, b[j] - b[i]), true)) {
				rCount++;
				cx = j - i;
				cy = b[j] - b[i];
			}
		}

		ans = max(ans, lCount + rCount);
	}

	cout << ans << "\n";
}