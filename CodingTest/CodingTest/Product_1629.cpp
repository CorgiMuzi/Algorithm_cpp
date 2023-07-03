#include <iostream>

using namespace std;

int dividend = 0, divisor = 0;

long long exponentModular(long long num) {
    if (num == 1) return dividend % divisor;

    long long expoMod = exponentModular(num / 2);

    long long ret = ((expoMod % divisor) * (expoMod % divisor)) % divisor;
    if (num % 2 == 0) {
        return ret;
    }
    else {
        return ret * dividend % divisor;
    }
}

int main() {
    int exponent = 0;
    cin >> dividend >> exponent >> divisor;

    cout << exponentModular(exponent);
}