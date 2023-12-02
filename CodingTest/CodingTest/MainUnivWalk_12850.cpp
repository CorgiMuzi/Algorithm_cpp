#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> vvl;
vvl campus;
int D;
const int MOD = 1'000'000'007;

vvl operator*(const vvl& left, const vvl& right) {
	vvl res(left.size(), vector<long long>(right[0].size(), 0));

	for (int i = 0; i < left.size(); ++i) {
		for (int j = 0; j < right[i].size(); ++j) {
			for (int k = 0; k < left[i].size(); ++k) {
				res[i][j] += ((left[i][k] * right[k][j]) % MOD);
			}
			res[i][j] %= MOD;
		}
	}

	return res;
}

vvl Walk(int t, vvl mat) {
	if (t == 1) return mat;

	vvl mat2 = Walk(t / 2, mat);
	if (t % 2 == 0) {
		return mat2 * mat2;
	}
	else {
		return mat2 * mat2 * mat;
	}
}

int main() {
	campus = {
		{0, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 1, 0, 1, 1, 0},
		{0, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 1, 0}
	};

	cin >> D;
	vvl path = Walk(D, campus);

	cout << path[0][0] % MOD;
}