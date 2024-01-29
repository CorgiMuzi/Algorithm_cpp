#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequence = 0;
int combCount = 0;	// 중복 조합의 경우의 수
vector<int> arr;

long maxResult = LONG_MIN;
long minResult = LONG_MAX;

long MaxCalculation(int idx, vector<int> ops, int opIdx) {
	if (ops[opIdx] == 0) return LONG_MIN;

	long result;

	switch (opIdx) {
	case 0:
		arr[idx + 1] = arr[idx] + arr[idx + 1];
		ops[0]--;
		break;
	case 1:
		arr[idx + 1] = arr[idx] - arr[idx + 1];
		ops[1]--;
		break;
	case 2:
		arr[idx + 1] = arr[idx] * arr[idx + 1];
		ops[2]--;
		break;
	case 3:
		arr[idx + 1] = arr[idx] / arr[idx + 1];
		ops[3]--;
		break;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] != 0)
			return MaxCalculation(idx + 1, ops, i);
		else {
			if (maxResult < arr[idx + 1]) {
				maxResult = arr[idx + 1];
			}
			break;
		}
	}

	return maxResult;
}

long MinCalculation(int idx, vector<int> ops, int opIdx) {
	if (ops[opIdx] == 0) return LONG_MAX;

	long result;

	switch (opIdx) {
	case 0:
		arr[idx + 1] = arr[idx] + arr[idx + 1];
		ops[0]--;
		break;
	case 1:
		arr[idx + 1] = arr[idx] - arr[idx + 1];
		ops[1]--;
		break;
	case 2:
		arr[idx + 1] = arr[idx] * arr[idx + 1];
		ops[2]--;
		break;
	case 3:
		arr[idx + 1] = arr[idx] / arr[idx + 1];
		ops[3]--;
		break;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] != 0)
			return MinCalculation(idx + 1, ops, i);
		else {
			if (minResult > arr[idx + 1]) {
				minResult = arr[idx + 1];
			}
			break;
		}
	}

	return minResult;
}


int main() {

	cin >> sequence;
	arr.resize(sequence);	// 수열 벡터

	for (int i = 0; i < sequence; i++) {
		cin >> arr[i];
	}

	vector<int> operators(4, 0);	// 연산자 갯수 벡터
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	for (int i = 0; i < 4; i++) {
		int a = operators[i];
		while (a != 0) {
			combCount *= (4 - i);
			a--;
		}
	}

	for (int i = 0; i < 4; i++) {
		MaxCalculation(0, operators, i);
	}

	cout << maxResult << '\n';

	for (int i = 0; i < 4; i++) {
		MinCalculation(0, operators, i);
	}
	cout << minResult;
}
