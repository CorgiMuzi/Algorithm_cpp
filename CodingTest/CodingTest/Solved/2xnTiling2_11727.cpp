#include <cstdio>

int rect[1001];

int main() {
    int N;
    scanf("%d", &N);

    rect[0] = 0;
    rect[1] = 1;
    rect[2] = 3;

    for (int i = 3; i <= N; ++i) {
        rect[i] = (2 * rect[i - 2] + rect[i - 1]) % 10007;
    }

    printf("%d", rect[N]);
}