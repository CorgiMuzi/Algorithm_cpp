#include <iostream>
#include <vector>
#include <queue>
#include <map>

std::priority_queue<int, std::vector<int>, std::less<int>> maxQ;
std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;
std::map<int, int> isRemainInQ;

void add(int arg);
void delMin();
void delMax();

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		isRemainInQ.clear();
		maxQ = std::priority_queue<int, std::vector<int>, std::less<int>>();
		minQ = std::priority_queue<int, std::vector<int>, std::greater<int>>();
		int k;
		std::cin >> k;

		while (k--) {
			char cmd;
			int arg;

			std::cin >> cmd >> arg;
			if (cmd == 'I') {
				add(arg);
			}
			else if (cmd == 'D') {
				if (arg == 1) {
					delMax();
				}
				else if (arg == -1) {
					delMin();
				}

				while (!minQ.empty() && isRemainInQ[minQ.top()] == 0) {
					minQ.pop();
				}

				while (!maxQ.empty() && isRemainInQ[maxQ.top()] == 0) {
					maxQ.pop();
				}
			}
		}

		if (minQ.empty() || maxQ.empty()) {
			std::cout << "EMPTY" << "\n";
		}
		else {
			std::cout << maxQ.top() << " " << minQ.top() << "\n";
		}
	}
}

void add(int arg) {
	isRemainInQ[arg] += 1;
	maxQ.push(arg);
	minQ.push(arg);
}

void delMin() {
	if (!minQ.empty()) {
		isRemainInQ[minQ.top()] -= 1;
		minQ.pop();
	}
}

void delMax() {
	if (!maxQ.empty()) {
		isRemainInQ[maxQ.top()] -= 1;
		maxQ.pop();
	}
}