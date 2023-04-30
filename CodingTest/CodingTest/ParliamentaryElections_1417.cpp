#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	std::vector<int> parliamentaryElections;
	for (int i = 0; i < N; ++i) {
		int votes;
		std::cin >> votes;
		parliamentaryElections.push_back(votes);
	}

	int bribe = 0;
	if (parliamentaryElections.size() != 1) {
		std::vector<int>::iterator max = std::max_element(parliamentaryElections.begin() + 1, parliamentaryElections.end());
		while (parliamentaryElections[0] <= *max) {
			bribe++;
			parliamentaryElections[0] ++;
			parliamentaryElections[max - parliamentaryElections.begin()]--;
			max = std::max_element(parliamentaryElections.begin() + 1, parliamentaryElections.end());
		}
	}

	std::cout << bribe;

}
