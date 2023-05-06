#include <iostream>
#include <map>
#include <string>

std::map<int, bool> isBroken;

bool isValidNum(int arg) {
	std::string num = std::to_string(arg);

	for (std::string::size_type i = 0; i < num.size(); ++i) {
		if (isBroken[num[i] - '0']) return false;
	}

	return true;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int b;
		std::cin >> b;
		isBroken[b] = true;
	}

	int min_countOfPress = abs(N - 100);
	for (int i = 0; i < 1000000; ++i) {
		if (isValidNum(i)) {
			int countOfPress = 0;
			std::string str = std::to_string(i);
			countOfPress += str.size();
			countOfPress += abs(N - i);
			
			min_countOfPress = std::min(min_countOfPress, countOfPress);
		}
	}

	std::cout << min_countOfPress;
}