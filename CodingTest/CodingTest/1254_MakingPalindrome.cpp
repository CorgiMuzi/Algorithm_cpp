#include <iostream>

using namespace std;

string phrase;

bool IsPalindrome(int left) {
	int right = phrase.length() - 1;
	while (left < right) {
		if (phrase[left++] != phrase[right--]) return false;
	}
	
	return true;
}

int main() {
	cin >> phrase;
	int left = 0;
	for (left = 0; left < phrase.length(); ++left) {
		if (IsPalindrome(left)) break;
	}

	int Answer = phrase.length() + left;
	cout << Answer;
}