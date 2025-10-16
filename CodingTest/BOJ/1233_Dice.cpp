#include <iostream>
#include <algorithm>

using namespace std;

int s1, s2, s3;

int stack[80];
int ans = 0, occurence = 0;

int main() {
	cin >> s1 >> s2 >> s3;

	fill_n(stack, 80, 0);

	for (int i = 1; i <= s1; ++i) {
		for (int j = 1; j <= s2; ++j) {
			for (int k = 1; k <= s3; ++k) {
				stack[i + j + k]++;
			}
		}
	}

	for (int i = 1; i <= s1 + s2 + s3; ++i) {
		if (occurence < stack[i]) {
			occurence = stack[i];
			ans = i;
		}
	}

	cout << ans;
}