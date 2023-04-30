#include <iostream>
#include <string>

int main() {
	int elapsedTime = 0;
	const int stair_time = 17, escalator_time = 21;
	for (int i = 0; i < 4; ++i) {
		std::string way;
		int time;
		std::cin >> way >> time;
		if (way == "Es") {
			elapsedTime += time * escalator_time;
		}
		else {
			elapsedTime += time * stair_time;
		}
	}

	std::cout << elapsedTime;
}