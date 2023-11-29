#include <iostream>

using namespace std;

typedef pair<int, int> pii;
pii matrix[500];
int mult[500][500];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> matrix[i].first >> matrix[i].second;
		fill_n(mult[i], N, 1e9);
		mult[i][i] = 0;
	}

	for (int span = 1; span < N; ++span) {
		for (int left = 0; left + span < N; ++left) {
			for (int mid = left; mid < left + span; ++mid) {
				mult[left][left + span] = min(mult[left][left + span], 
					mult[left][mid] + mult[mid + 1][left + span] + matrix[left].first * matrix[mid].second * matrix[left + span].second);
			}
		}
	}

	cout << mult[0][N - 1];
}