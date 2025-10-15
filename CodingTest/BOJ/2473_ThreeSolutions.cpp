#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lld;
vector<lld> solutions;
int N = 0;
lld min_feature = 3e9 + 1;
lld min_fix, min_left, min_right;

int main() {
    cin >> N;

    solutions = vector<lld>(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    for (vector<lld>::iterator fix = solutions.begin(); fix != solutions.end() - 2; ++fix) {
        lld sum_feature;
        vector<lld>::iterator left = fix + 1, right = solutions.end() - 1;
        while (left < right) {
            sum_feature = *fix + *left + *right;
            if (abs(sum_feature) < min_feature) {
                min_fix = *fix;
                min_left = *left;
                min_right = *right;

                min_feature = abs(sum_feature);
            }

            if (sum_feature < 0) left++;
            else right--;
        }

        if (min_feature == 0) break;
    }

    cout << min_fix << " " << min_left << " " << min_right;
}