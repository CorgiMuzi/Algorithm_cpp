#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int numberOfGrade;
    cin >> numberOfGrade;

    if (numberOfGrade == 0) {
        cout << "0";
        return 0;
    }

    vector<int> grades(numberOfGrade, 0);
    for (int i = 0; i < numberOfGrade; ++i) {
        cin >> grades[i];
    }

    sort(grades.begin(), grades.end(), less<int>());

    double avgNum = std::round(numberOfGrade * 0.15);
    double sum = 0;
    for (vector<int>::size_type i = avgNum; i < grades.size() - avgNum; ++i) {
        sum += grades[i];
    }

    double avg = std::round(sum / (numberOfGrade - 2 * avgNum));

    cout << avg;
}