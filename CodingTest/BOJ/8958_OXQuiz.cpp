#include <iostream>

using namespace std;

int main() {
	int TC = 0;
	cin >> TC;

	while (TC--) {
		string answers;
		cin >> answers;

		int stack = 0, score = 0;
		for (string::size_type i = 0; i < answers.length(); ++i) {
			if (answers[i] == 'O') stack++;
			else stack = 0;

			score += stack;
		}

		cout << score << '\n';
	}
}