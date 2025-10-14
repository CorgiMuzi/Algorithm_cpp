#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int entryPoint[32001] = { 0, };
vector<int> condition[32001];
vector<int> answer;
int N = 0, M = 0;

void lineUp() {
    queue<int> line;
    for (int i = 1; i <= N; ++i) {
        if (entryPoint[i] == 0) line.push(i);
    }

    for (int i = 0; i < N; ++i) {
        if (line.empty()) return;
        int cur = line.front();
        line.pop();

        for (int i = 0; i < condition[cur].size(); ++i) {
            if (--entryPoint[condition[cur][i]] == 0) {
                line.push(condition[cur][i]);
            }
        }

        answer.push_back(cur);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        entryPoint[i] = 0;
    }

    int A, B;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        condition[B].push_back(A);
        entryPoint[A]++;
    }

    lineUp();

    for (vector<int>::reverse_iterator i = answer.rbegin(); i != answer.rend(); ++i) {
        cout << *i << " ";
    }
}