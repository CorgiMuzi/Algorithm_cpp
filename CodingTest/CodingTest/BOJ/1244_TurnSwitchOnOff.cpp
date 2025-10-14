#include <iostream>

using namespace std;

int N, M;
bool Switch[101];

void Boy(int n) {
	for (int i = n; i <= N; i += n) {
		Switch[i] = !Switch[i];
	}
}

void Girl(int n) {
	int left, right;
	left = n - 1;
	right = n + 1;
	while (left > 0 && right <= N) {
		if (Switch[left] != Switch[right]) {
			break;
		}

		left--;
		right++;
	}
	
	left++;
	right--;
	for (left; left <= right; ++left) {
		Switch[left] = !Switch[left];
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> Switch[i];
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int sex; cin >> sex;
		int num; cin >> num;
		if (sex == 1) {
			Boy(num);
		}
		else if (sex == 2) {
			Girl(num);
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << Switch[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}