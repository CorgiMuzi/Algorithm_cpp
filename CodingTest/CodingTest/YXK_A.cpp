#include <iostream>
#include <string>

#define YONSEI "YONSEI"
#define KOREA "KOREA"

using namespace std;

int main() {
	string fortune;
	std::cin >> fortune;

	int yonsei = 0, korea = 0, current = 0;

	while (current < fortune.size()) {
		char c = fortune[current];
		if (c == YONSEI[yonsei]) {
			yonsei++;
		}

		if (c == KOREA[korea]) {
			korea++;
		}

		if (yonsei == sizeof(YONSEI) / sizeof(*YONSEI) - 1) {
			std::cout << "YONSEI";
			break;
		}
		else if (korea == sizeof(KOREA) / sizeof(*KOREA) - 1) {
			std::cout << "KOREA";
			break;
		}

		current++;
	}
}