#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	long long L;
	std::cin >> N >> L;
	
	std::vector<int> students(N);

	for (std::vector<int>::size_type i = 0; i < N; ++i) {
		std::cin >> students[i];
	}	

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax = std::minmax_element(students.begin(), students.end());
	std::vector<int>::iterator max, min;
	min = minmax.first;
	max = minmax.second;

	std::vector<int>::iterator front, back;
	front = students.begin();
	back = students.end();
	while (L > 0) {
		if (min == back) {
			back -= 1;
			min = std::min_element(front, back);
		}
		if (max == front) {
			front += 1;
			max = std::max_element(front, back);
		}

		if (*min < *(min + 1)) {
			std::swap(*min, *(min + 1));
			min += 1;
			--L;
		}

		if (*max < *(max - 1)) {
			std::swap(*max, *(max + 1));
			max -= 1;
			--L;
		}
	}

	int time = 0;


	std::cout << time;
}