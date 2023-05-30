#include <iostream>

using std::cin, std::cout;

int GCD(int arg1, int arg2) {
    if (arg1 > arg2) {
        std::swap(arg1, arg2);
    }

    while (arg2 != 0) {
        int temp = arg2;
        arg2 = arg1 % arg2;
        arg1 = temp;
    }

    return arg1;
}

int LCM(int arg1, int arg2) {
    return (arg1 * arg2) / GCD(arg1, arg2);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int possible = false;
        for (int i = x; i <= LCM(M, N); i += M) {
            if ((i - 1) % N + 1 == y) {
                possible = true;
                cout << i << "\n";
                break;
            }
        }

        if (!possible) cout << "-1\n";
    }
}