#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dist(int a, int b) {
    return abs(a - b);
}

void closestEvenOdd(const vector<int>& P) {
    int n = P.size();
    sort(P.begin(), P.end());

    int min_dist_even = INT_MAX;
    int min_dist_odd = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        int d = dist(P[i], P[i + 1]);
        if (d % 2 == 0) {
            min_dist_even = min(min_dist_even, d);
        } else {
            min_dist_odd = min(min_dist_odd, d);
        }
    }

    if (min_dist_even == INT_MAX) {
        cout << "Minimum distance for even pairs: -1" << endl;
    } else {
        cout << "Minimum distance for even pairs: " << min_dist_even << endl;
    }

    if (min_dist_odd == INT_MAX) {
        cout << "Minimum distance for odd pairs: -1" << endl;
    } else {
        cout << "Minimum distance for odd pairs: " << min_dist_odd << endl;
    }
}

int main() {
    vector<int> P = {1, 3, 2, 5, 4};
    closestEvenOdd(P);
    return 0;
}
