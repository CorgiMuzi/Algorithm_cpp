#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ApplePrice(int, int, vector<int>);

int main() {
	int k = 4;
	int m = 3;

	vector<int> score = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

	cout << ApplePrice(k, m, score);

}

int ApplePrice(int k, int m, vector<int> score) {
	int answer = 0;
	int price = 0;

	sort(score.begin(), score.end());
	
	int trash = score.size() % m;

	score.erase(score.begin(), score.begin() + trash);

	sort(score.rbegin(), score.rend());

	for (int i = 0; i < score.size() / m; i++) {
		vector<int> box;

		for (int j = 0; j < m; j++) {
			box.push_back(score[i * m + j]);
		}
		price += box[box.size()-1] * m;
	}

	answer = price;

	return answer;
}