#include <bits/stdc++.h>
#include <queue>
#include <vector>

using std::priority_queue, std::vector;

struct cmp {
    bool operator()(int& left, int& right) {
        if (std::abs(left) == std::abs(right)) {
            return left > right;
        }

        return std::abs(left) > std::abs(right);
    }
};

int main() {
    int N, x;
    scanf("%d", &N);
    priority_queue<int, vector<int>, cmp> absHeap;

    int* cmd = new int[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);

        if (x == 0) {
            if (absHeap.empty()) {
                printf("0\n");
            }
            else {
                printf("%d\n", absHeap.top());
                absHeap.pop();
            }
        }
        else {
            absHeap.push(x);
        }
    }

    delete[] cmd;
}