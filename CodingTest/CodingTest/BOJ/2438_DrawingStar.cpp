#include <iostream>

using namespace std;

int main() {
    int max_num = 0;
    cin >> max_num;

    for (int line = 1; line <= max_num; ++line) {
        for (int star = 0; star < line; ++star) {
            cout << "*";
        }
        cout << "\n";
    }
}