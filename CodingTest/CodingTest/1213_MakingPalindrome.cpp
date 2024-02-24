#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

string str;
char Alphabets[26];
deque<char> Buffer;

int main() {
	fill_n(Alphabets, 26, 0);
	cin >> str;
	for (const char& c : str) {
		Alphabets[c - 'A']++;
	}

	bool IsOddExitsMoreThanOne = false;
	for (int i = 0; i < 26; ++i) {
		int cnt = Alphabets[i];
		if (cnt % 2 != 0) {
			if (IsOddExitsMoreThanOne) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}

			IsOddExitsMoreThanOne = true;
			Buffer.push_back(i + 'A');
			Alphabets[i]--;
		}
	}

	for (int i = 25; i >= 0; --i) {
		while (Alphabets[i]) {
			Buffer.push_back(i + 'A');
			Buffer.push_front(i + 'A');

			Alphabets[i] -= 2;
		}
	}

	while (!Buffer.empty()) {
		cout << Buffer.front();
		Buffer.pop_front();
	}
}