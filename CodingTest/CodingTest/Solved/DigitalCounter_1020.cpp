#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

typedef long long lld;

constexpr int INF_LINE = 106;
int lines[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
lld ten[16];
lld counter[16][INF_LINE];
string numStr;
lld num = 0;
lld ans;

void InitCounter();

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	getline(cin, numStr);

	InitCounter();

	ans = ten[numStr.length()];

	for (int i = 1; i <= numStr.length(); ++i) {
		num += ten[numStr.length() - i] * (numStr[i - 1] - '0');
	}

	for (int val = 0; val < 10; ++val) {
		lld digit = numStr.back() - '0';
		if (lines[digit] == lines[val] && digit != val) {
			if (val > digit) {
				ans = min(ans, val - digit);
			}
			else {
				ans = min(ans, ten[numStr.length()] + val - digit);
			}
		}
	}

	lld lineCount = lines[numStr.back() - '0'];

	for(int n = 2; n < numStr.length() + 1; ++n) {
		lld digit = num % ten[n];

		lineCount += lines[numStr[numStr.length() - n] - '0'];

		for(int nn = 0; nn < 10; ++nn) {
			if(lineCount - lines[nn] >= (n - 1) * 2) {
				lld p = ten[n - 1] * nn;
				lld t = counter[n - 1][lineCount - lines[nn]];

				if(digit != p + t && t != LLONG_MAX) {
					lld val = p + t - digit;
					if(val <= 0) {
						val += ten[numStr.length()];
					}

					ans = min(ans, val);
				}
			}
		}
	}

	cout << ans;
}

void InitCounter() {
	fill_n(&counter[0][0], sizeof(counter) / sizeof(**counter), LLONG_MAX);

	ten[0] = 1;
	for (int i = 1; i < 16; ++i) ten[i] = ten[i - 1] * 10;

	for (int i = 0; i < 10; ++i) counter[1][lines[i]] = min(counter[1][lines[i]], (lld)i);

	for (int len = 2; len < numStr.length() + 1; ++len) {
		for (int curLine = 2; curLine < 8; ++curLine) {
			lld minLine = (len - 1) * 2;
			lld maxLine = (len - 1) * 7;
			for (lld usedLine = minLine; usedLine < maxLine + 1; ++usedLine) {
				counter[len][curLine + usedLine] = min(counter[len][curLine + usedLine], counter[len - 1][usedLine] + ten[len - 1] * counter[1][curLine]);
			}
		}
	}
}