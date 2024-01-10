#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food);

int main() {
	vector<int> food = { 1, 3, 4, 6 };

	cout << solution(food);
}

string solution(vector<int> food) {
	string answer = "";

	vector<int> foodArr;

	foodArr.push_back(0);
	
	for (int i = food.size()-1; i > 0 ; i--) {
		for (int j = 0; j < food[i] / 2; j++) {
			foodArr.insert(foodArr.begin(), i);
			foodArr.push_back(i);
		}
	}

	for (int i : foodArr) {
		answer.append(to_string(i));
	}

	return answer;
}