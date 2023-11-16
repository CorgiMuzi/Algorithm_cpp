#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0, M = 0;
int before[1001];
vector<int> after[1001];
vector<int> performance;

void planSequence() {
    queue<int> waiting;
    for (int i = 1; i <= N; ++i) {
        if (before[i] == 0) waiting.push(i);
    }

    while (!waiting.empty()) {
        int curSinger = waiting.front();
        performance.push_back(curSinger);
        waiting.pop();

        for (vector<int>::iterator singer = after[curSinger].begin(); singer != after[curSinger].end(); ++singer) {
            before[*singer]--;
            if (before[*singer] == 0) waiting.push(*singer);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int pd = 0; cin >> pd;
        vector<int> pdLine;
        for (int j = 0; j < pd; ++j) {
            int singer = 0; cin >> singer;

            for (vector<int>::iterator s = pdLine.begin(); s != pdLine.end(); ++s) {
                after[*s].push_back(singer);
                before[singer]++;
            }

            pdLine.push_back(singer);
        }
    }

    planSequence();

    if (performance.size() != N) cout << 0;
    else {
        for (int sing : performance) {
            cout << sing << "\n";
        }
    }
}