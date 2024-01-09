#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, bool> pib;

int N;
int A[51];
pib B[51];

bool cmp(const pib& left, const pib& right);

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// input
	cin >> N;

	// initialize
	fill_n(A, N, 0);
	fill_n(B, N, make_pair(0, false));

	// input 2
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
		B[i].first = A[i];
	}

	sort(B, B + N, cmp);
	for(int i = 0; i < N; ++i) {
		auto iter = find_if(B, B + N, [i](const pib& elem) {
			return elem.first == A[i] && !elem.second;
		});

		iter->second = true;
		cout << static_cast<int>(distance(B, iter)) << " ";
	}
}

bool cmp(const pib& left, const pib& right) {
	return left.first < right.first;
}
