#include <iostream>
#include <string>

int bitmask;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M;
	std::cin >> M;

	while (M--) {
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "add") {
			int arg;
			std::cin >> arg;
			bitmask |= (1 << arg);
		}
		else if (cmd == "remove") {
			int arg;
			std::cin >> arg;
			bitmask &= ~(1 << arg);
		}
		else if (cmd == "check") {
			int arg;
			std::cin >> arg;
			if (bitmask & (1 << arg)) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
			
		}
		else if (cmd == "toggle") {
			int arg;
			std::cin >> arg;
			bitmask ^= (1 << arg);
		}
		else if (cmd == "all") {
			bitmask = (1 << 21) - 1;
		}
		else if (cmd == "empty") {
			bitmask = 0;
		}
	}
}