#include <iostream>

using namespace std;

int connections_size = 0;
bool** isConnected;

int main() {
    cin >> connections_size;
    isConnected = new bool* [connections_size];
    for (int r = 0; r < connections_size; ++r) {
        isConnected[r] = new bool[connections_size] {false};
        for (int c = 0; c < connections_size; ++c) {
            cin >> isConnected[r][c];
        }
    }

    for (int mid = 0; mid < connections_size; ++mid) {
        for (int beg = 0; beg < connections_size; ++beg) {
            for (int end = 0; end < connections_size; ++end) {
                if (isConnected[beg][end]) continue;
                if (isConnected[beg][mid] && isConnected[mid][end]) isConnected[beg][end] = true;
            }
        }
    }

    for (int r = 0; r < connections_size; ++r) {
        for (int c = 0; c < connections_size; ++c) {
            cout << isConnected[r][c] << " ";
        }
        cout << "\n";
    }
}