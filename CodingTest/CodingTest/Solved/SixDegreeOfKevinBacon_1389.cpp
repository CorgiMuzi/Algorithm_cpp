#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> kevinBacons(N, vector<int>(N, N - 1));

    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        v1 -= 1;
        v2 -= 1;
        kevinBacons[v1][v2] = kevinBacons[v2][v1] = 1;
    }

    for (int wp = 0; wp < N; ++wp) {
        for (int s = 0; s < N; ++s) {
            for (int e = 0; e < N; ++e) {
                if (s == e) kevinBacons[s][e] = 0;
                else kevinBacons[s][e] = min(kevinBacons[s][e], kevinBacons[s][wp] + kevinBacons[wp][e]);
            }
        }
    }

    int minV, minP;

    for (vector<vector<int>>::size_type i = 0; i < kevinBacons.size(); ++i) {
        if (i == 0) {
            minV = accumulate(kevinBacons[i].begin(), kevinBacons[i].end(), 0);
            minP = i;
        }
        else {
            int minV2 = accumulate(kevinBacons[i].begin(), kevinBacons[i].end(), 0);
            if (minV > minV2) {
                minV = minV2;
                minP = i;
            }
        }
    }

    cout << minP + 1;
}