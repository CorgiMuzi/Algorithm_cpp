#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
	int registeredPokemon = 0, testCase = 0;
	std::cin >> registeredPokemon >> testCase;
	
	std::map<int, std::string> numOfPokes;
	std::map<std::string, int> nameOfPokes;
	for (int i = 0; i < registeredPokemon; ++i) {
		std::string pokeName;
		std::cin >> pokeName;
		numOfPokes[i] = pokeName;
		nameOfPokes[pokeName] = i;
	}

	std::vector<std::string> tests(testCase);
	for (int i = 0; i < testCase; ++i) {
		std::cin >> tests[i];
	}

	for (const auto& elem : tests) {
		try {
			std::cout << numOfPokes[std::stoi(elem)-1] << "\n";
		}
		catch (std::invalid_argument &e) {
			std::cout << nameOfPokes[elem]+1 << "\n";
		}
	}

	return 0;
}