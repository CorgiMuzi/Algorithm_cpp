#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string Numbers[101][1001];

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> Numbers[0][i];
	}

	int MaxLen = Numbers[0][0].length();

	int len = 1;
	for (len; len <= MaxLen; ++len) {
		bool answer = true;
		for (int i = 0; i < N; ++i) {
			Numbers[len][i] = Numbers[0][i].substr(MaxLen - len, len);
		}

		for (int i = 0; i < N; ++i) {
			if (find(&Numbers[len][i + 1], &Numbers[len][N], Numbers[len][i]) != &Numbers[len][N]) {
				answer = false;
				break;
			}
		}

		if (answer) break;
	}

	if (len > MaxLen) len = MaxLen;
	cout << len;
}