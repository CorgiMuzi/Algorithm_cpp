#include <iostream>
#include <string>
#include <vector>

using namespace std;

int makeHamburger(vector<int>& ingredient);

int solution(vector<int> ingredient) {
	/*
		ingredient
		----------------------
		»§ : 1
		¾ßÃ¤ : 2
		°í±â : 3
	*/
	int answer = 0;
	int hamburger_cnt = 0;

	hamburger_cnt = makeHamburger(ingredient);

	answer = hamburger_cnt;
	return answer;
}

int makeHamburger(vector<int>& ingredient) {
	int hamburger_cnt = 0;

	if (ingredient.size() < 4) return hamburger_cnt;
	int state = 0;

	for (vector<int>::size_type i = 0; i < ingredient.size();) {
		
		switch (state) {
		case 0: default:
			if (ingredient[i] == 1) {
				state = 1;
			}
			i++;
			break;
		case 1:
			if (ingredient[i] == 2) {
				state = 2;
			}
			else {
				if (ingredient[i] == 1)
				{
					state = 1;
				}
				else {
					state = 0;
				}
			}

			i++;
			break;
		case 2:
			if (ingredient[i] == 3) {
				state = 3;
			}
			else {
				if (ingredient[i] == 1)
				{
					state = 1;
				}
				else {
					state = 0;
				}
			}
			i++;
			break;
		case 3:
			if (ingredient[i] == 1) {
				hamburger_cnt++;
				ingredient.erase(ingredient.begin() + i - 3, ingredient.begin() + i + 1);
				if (ingredient.empty()) break;
				if (i < 5) { i = 0; }
				else {
					i -= 5;
				}
				if (ingredient[i] == 1) {
					state = 1;
				}
				else {
					state = 0;
				}
			}
			else {
				if (ingredient[i] == 1)
				{
					state = 1;
				}
				else {
					state = 0;
				}
			}
			i++;
			break;
		}
	}

	return hamburger_cnt;
}

int main() {
	vector<int> ingredient = { 1, 2, 2, 3, 1 };

	cout << "ÇÜ¹ö°Å ¼ö: " << solution(ingredient);
}