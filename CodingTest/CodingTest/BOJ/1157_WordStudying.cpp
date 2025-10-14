#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	string phrase;
	cin >> phrase;
	map<char, int> dict;
	for (string::size_type i = 0; i < phrase.length(); ++i) {
		dict[toupper(phrase[i])]++;
	}

	char frequentChar = dict.begin()->first;
	int frequency = dict.begin()->second;

	for (map<char, int>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
		if (frequency < iter->second) {
			frequency = iter->second;
			frequentChar = iter->first;
		}
	}

	int max_count = 0;
	for (map<char, int>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
		if (frequency == iter->second) {
			max_count++;
		}
	}

	if (max_count > 1) cout << "?";
	else cout << frequentChar;
}