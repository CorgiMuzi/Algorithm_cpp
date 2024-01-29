#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> triangle[501];
vector<int> accum[501];

void descentTriangle() {
	accum[1][0] = triangle[1][0];

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < 2; ++k) {
				accum[i + 1][j + k] = max(accum[i + 1][j + k], accum[i][j] + triangle[i + 1][j + k]);
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			int val = -1;
			cin >> val;
			triangle[i].push_back(val);
			accum[i].push_back(0);
		}
	}

	descentTriangle();

	cout << *max_element(accum[N].begin(), accum[N].end());
}