#include <iostream>
#include <vector>
#include <string>

#define SEC_PER_DAY = 86400;

using namespace std;

vector<string> split(const string& str, const char& delimiter= ' ') {
	vector<string> ret;
	string::size_type front = 0, back = front;
	while (str[front] != delimiter) {
		while (str [back] == delimiter) {
			string temp = str.substr(front, back);
			ret.push_back(temp);
			break;
		}
	}


	for (string::size_type front = 0; front < str.size(); ++front) {
		if (str[front] != delimiter) {
			for (string::size_type back = front; back < str.size(); ++back) {
				if (str[back] == delimiter) {
					string temp = str.substr(front, back);
					ret.push_back(temp);
					break;
				}
			}
		}
	}

	return ret;
}

int main() {
	int up, down;
	cin >> up >> down;
	vector<string> upTrains(up), downTrains(down);

	for (vector<string>::size_type i = 0; i < upTrains.size(); ++i) {
		std::cin >> upTrains[i];
	}

	for (vector<string>::size_type i = 0; i < downTrains.size(); ++i) {
		std::cin >> downTrains[i];
	}

	vector<string> upTrainsTimes = split(upTrains[0], ':');
	for (const auto& elem : upTrainsTimes) {
		std::cout << elem << "\n";
	}
}