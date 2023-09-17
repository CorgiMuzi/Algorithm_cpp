#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> isPalindrome;
int palindrome[2501];

int main() {
	string phrase;

	cin >> phrase;

	string::size_type phraseLen = phrase.length();

	isPalindrome = vector<vector<bool>>(phraseLen + 1, vector<bool>(phraseLen + 1, false));

	for (string::size_type i = 0; i < phraseLen; ++i) {
		isPalindrome[i][i] = true;
		isPalindrome[i][i + 1] = (phrase[i] == phrase[i + 1]);
	}

	for (string::size_type end = 2; end < phraseLen; ++end) {
		for (string::size_type beg = 0; end - beg >= 2; ++beg) {
			isPalindrome[beg][end] = (phrase[beg] == phrase[end] && isPalindrome[beg + 1][end - 1]);
		}
	}

	for (string::size_type end = 1; end <= phraseLen; ++end) {
		palindrome[end] = 2501;
		for (string::size_type beg = 1; beg <= end; ++beg) {
			if(isPalindrome[beg - 1][end - 1]) palindrome[end] = min(palindrome[end], palindrome[beg - 1] + 1);
		}
	}

	cout << palindrome[phraseLen];
}