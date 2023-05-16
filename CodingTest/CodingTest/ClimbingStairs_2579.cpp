#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector, std::max;

int main() {
    int countOfStairs;
    cin >> countOfStairs;

    vector<int> stairs(countOfStairs);
    vector<int> scores(countOfStairs);

    for (vector<int>::size_type i = 0; i < stairs.size(); ++i) {
        cin >> stairs[i];
    }

    if (countOfStairs < 3) {
        if (countOfStairs == 1) cout << stairs[0];
        else if (countOfStairs == 2) cout << stairs[0] + stairs[1];
    }
    else {
        scores[0] = stairs[0];
        scores[1] = stairs[0] + stairs[1];
        scores[2] = std::max(scores[0] + stairs[2], stairs[1] + stairs[2]);
        for (vector<int>::size_type i = 3; i < stairs.size(); ++i) {
            scores[i] = max(scores[i - 2] + stairs[i], scores[i - 3] + stairs[i - 1] + stairs[i]);
        }
        cout << scores[countOfStairs - 1];
    }
}