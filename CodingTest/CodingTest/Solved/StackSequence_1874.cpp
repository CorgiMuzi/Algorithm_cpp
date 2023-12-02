#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> outputs(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> outputs[i];
	}

	std::vector<char> commands(n);
	std::vector<int> stack;
	int current = 1, top = 0;


	for (int i = 0; i < n; ++i) {
		if (top < outputs[i]) {
			while (top < outputs[i]) {
				++top;
				stack.push_back(current++);
			}
		}
	}
	
}