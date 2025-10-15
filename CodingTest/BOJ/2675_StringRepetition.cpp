#include <iostream>

using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		int repeat = 0;
		string str;
		cin >> repeat >> str;

		for (int i = 0; i < str.length(); ++i) {
			for (int j = 0; j < repeat; ++j) {
				cout << str[i];
			}
		}
		cout << '\n';
	}
}