#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long lld;

constexpr lld MAX = 1e15;
string str_num;
lld number = 0;
lld ten[16];
int lines[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
// digit[a][b] : b value를 가지는 a 자리수 숫자 조합
lld digit[16][106];
lld ans;

void InitDP();

int main() {
	getline(cin, str_num);
	for (int index = str_num.length() - 1; index >= 0; --index) {
		number += (str_num[index] - '0') * ten[index];
	}

	InitDP();

	ans = ten[str_num.length()];
	lld criteria = number % 10;
	for (int n = 0; n < 10; ++n) {
		if (lines[n] == lines[criteria] && n != criteria) {
			if (n > criteria) {
				ans = min(ans, n - criteria);
			}
			else {
				ans = min(ans, ten[str_num.length()] + n - criteria);
			}
		}
	}

	int used = lines[criteria];
	for (int index = 2; index < str_num.length(); ++index) {
		
	}
}

void InitDP() {
	ten[0] = 1;
	for (int i = 1; i < 16; ++i) {
		ten[i] = ten[i - 1] * 10;
	}

	fill_n(&digit[0][0], size(digit) * size(digit[0]), MAX);

	for (int i = 0; i < 10; ++i) {
		digit[1][lines[i]] = min(digit[1][lines[i]], static_cast<lld>(i));
	}

	for (int a = 2; a <= number.length(); ++a) {
		for (int val = 2; val < 8; ++val) {
			int lower = (a - 1) * 2;
			int upper = (a - 1) * 7;

			for (int b = lower; b < upper + 1; ++b) {
				digit[a][val + b] = min(digit[a][val + b], ten[a - 1] * digit[1][val] + digit[a - 1][b]);
			}
		}
	}
}