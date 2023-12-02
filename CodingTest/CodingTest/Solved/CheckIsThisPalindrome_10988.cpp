#include <iostream>

using namespace std;

int main() {
	string phrase;
	cin >> phrase;

	string::iterator left = phrase.begin(), right = phrase.end() - 1;
	bool isPalindrome = true;
	while (left < right) {
		if (*left != *right) isPalindrome = false;
		left++;
		right--;
	}

	cout << (isPalindrome ? 1 : 0) << "\n";
}