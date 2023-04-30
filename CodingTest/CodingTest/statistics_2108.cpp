#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> vec;
	map<int, int> m;

	int inputValue;
	int sum = 0;

	for (int i = 0; i < N; ++i) {
		cin >> inputValue;
		sum += inputValue;
		vec.push_back(inputValue);
		++m[inputValue];
	}

	sort(vec.begin(), vec.end());

	int avg = sum / N;
	int mid = vec[(N - 1) / 2];
	int range = *(vec.end() - 1) - vec.front();

	int max_elem = -1;
	int max_count = -1;
	int second_max_elem = -1;
	int second_max_count = -1;

	for (auto it : m)
	{
		if (it.second > max_count)
		{
			second_max_elem = max_elem;
			second_max_count = max_count;
			max_elem = it.first;
			max_count = it.second;
		}
		else if (it.second > second_max_count)
		{
			second_max_elem = it.first;
			second_max_count = it.second;
		}
	}

	if (second_max_elem != -1) {
		max_elem = second_max_elem;
	}

	//cout << avg << "\n" << mid << "\n" << max_elem << "\n" << range;
	cout <<"avg: " << avg << "\nmid: " << mid << "\nmax_elem: " << max_elem << "\nrange: " << range;

	return 0;
}