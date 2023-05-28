#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, strLength, ans = 0; 
	cin >> N >> strLength;

	string str;
	cin >> str;

	for (string::size_type i = 0; i < str.length(); ++i) {
		if (str[i] == 'I') {
			int unit_cnt = 0;
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				unit_cnt++;

				if (unit_cnt == N) {
					unit_cnt--;
					ans++;
				}

				i += 2;
			}
		}
	}

	cout << ans;
}