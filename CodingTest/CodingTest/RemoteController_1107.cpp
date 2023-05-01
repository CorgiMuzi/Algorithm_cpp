#include <iostream>
#include <map>
#include <string>

std::string N;
std::map<int, bool> brokenButtons;

int findNumber() {
	int ret = 0;

	std::string upper, lower;
	for (std::string::size_type i = 0; i < N.size(); ++i) {
		int num = N[i] - '0';
		while (brokenButtons[num]) {
			num--;
			if (num < 0) num += 10;
		}
		lower.push_back(num);

		num = N[i] - '0';
		while (brokenButtons[num]) {
			num++;
			if (num > 9) num -= 10;
		}
		upper.push_back(num);
	}

	int base = upper.size();
	int upper_int = std::stoi(upper), lower_int = std::stoi(lower);

	ret = upper_int - 100 < lower_int - 100 ? upper_int - 100 : lower_int - 100;
	ret += base;

	return ret;
}

int main() {
	int M;
	
	std::cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int broken;
		std::cin >> broken;
		brokenButtons[broken] = true;
	}

	int count = 0;
	count = findNumber();
	
	std::cout << count;
}