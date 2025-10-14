#include <iostream>

using namespace std;

string L, R;
int Eight = 0;

int main() {
    cin >> L >> R;

    if (L.length() == R.length()) {
        for (int i = 0; i < L.length(); ++i) {
            if (L[i] == R[i] && R[i] == '8') Eight++;
            else if (L[i] != R[i]) break;
        }
    }

    cout << Eight;
}