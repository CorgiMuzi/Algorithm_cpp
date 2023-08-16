#include <iostream>
#include <vector>

#define DIV 1000

using namespace std;

typedef vector<vector<int>> vvi;
int matrixSize = 0;
long long expo = 0;
vvi matrix;

vvi matrixMult(const vvi& left, const vvi& right) {
	vvi m = vvi(matrixSize, vector<int>(matrixSize, 0));

	for (int r = 0; r < matrixSize; ++r) {
		for (int c = 0; c < matrixSize; ++c) {
			for (int k = 0; k < matrixSize; ++k) {
				m[r][c] += left[r][k] * right[k][c] % DIV;
			}
			m[r][c] %= DIV;
		}
	}

	return m;
}

vvi squareMatrix(long long expo) {
	if (expo == 1) return matrix;
	
	vvi matrix_ = squareMatrix(expo / 2);


	if (expo % 2 == 0) {
		return matrixMult(matrix_, matrix_);
	}
	else {
		return matrixMult(matrixMult(matrix_, matrix_), matrix);
	}
}

int main() {
	cin >> matrixSize >> expo;

	matrix = vvi(matrixSize, vector<int>(matrixSize, 0));

	for (int r = 0; r < matrixSize; ++r) {
		for (int c = 0; c < matrixSize; ++c) {
			cin >> matrix[r][c];
		}
	}

	matrix = squareMatrix(expo);

	for (int r = 0; r < matrixSize; ++r) {
		for (int c = 0; c < matrixSize; ++c) {
			cout << (matrix[r][c] % DIV) << " ";
		}
		cout << "\n";
	}
}