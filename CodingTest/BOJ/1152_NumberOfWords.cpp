#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout;
using std::string, std::getline;
using std::vector;

vector<string> split(const string& str, const char& delimiter) {
	vector<string> ret;

	string::size_type front = str[0] != ' ' ? 0 : 1;
	
	string::size_type end = str.find(delimiter, front);
	while (end != string::npos) {
		ret.push_back(str.substr(front, end - front));
		front = end + 1;
		end = str.find(delimiter, front);
	}

	string last_word = str.substr(front, end - front);
	if (last_word.length() > 0) {
		ret.push_back(last_word);
	}

	return ret;
}

int main() {
	string temp;
	getline(cin, temp);
	
	vector<string> ans = split(temp , ' ');

	cout << ans.size();
}