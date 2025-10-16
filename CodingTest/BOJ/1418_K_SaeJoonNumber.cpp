#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> is_prime(N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int count = 1;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {  
            if (i <= K) {  
                count++;
            }
        }
        else {  
            int max_factor = 0;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0 && is_prime[j]) {
                    max_factor = max(max_factor, j);
                }
                if (i % j == 0 && is_prime[i / j]) {
                    max_factor = max(max_factor, i / j);
                }
            }
            if (max_factor <= K) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
