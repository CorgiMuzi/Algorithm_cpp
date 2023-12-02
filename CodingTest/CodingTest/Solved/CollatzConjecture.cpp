#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int, vector<vector<int>> ranges);
vector<int> calcSequence(int k);
vector<double> integration(vector<int>, vector<vector<int>>);

int main() {
	int k = 5;
	vector<vector<int>> ranges = { {0, 0}, {0, -1}, {2, -3}, {3, -3} };

	vector<double> answer = solution(k, ranges);

	cout << "[";
	for (int i = 0; i < answer.size(); i++) {
		if (i != 0) cout << ",";
		cout << answer[i];
	}
	cout << "]";
}

vector<double> solution(int k, vector<vector<int>> ranges) {
	vector<double> answer;

	vector<int> sequence = calcSequence(k);

	answer = integration(sequence, ranges);

	return answer;
}

// 우박수열 계산
vector<int> calcSequence(int k) {
	vector<int> sequence;
	sequence.push_back(k);

	while (k > 1) {
		/*
			1 - 1. 입력된 수가 짝수라면 2로 나눕니다.
			1 - 2. 입력된 수가 홀수라면 3을 곱하고 1을 더합니다.
			2.결과로 나온 수가 1보다 크다면 1번 작업을 반복합니다.
		*/
		k = k % 2 == 0 ? k / 2 : k * 3 + 1;
		sequence.push_back(k);
	}

	return sequence;
}

// 정적분 계산
vector<double> integration(vector<int> sequence, vector<vector<int>> ranges) {
	vector<double> areas;
	for (vector<int> range : ranges) {
		// range = x_min ~ x_max
		int x_min = range[0];
		int x_max = (sequence.size()-1)+range[1];
		double area = 0;

		if (x_min >= sequence.size() || x_max < x_min) {
			area = -1;
		}
		else {
			for (int x_pos = x_min; x_pos < x_max; x_pos++) {
				int x_next_pos = x_pos + 1;
				double y_min, y_max;
				if (sequence[x_next_pos] > sequence[x_pos]) {
					y_min = sequence[x_pos];
					y_max = sequence[x_next_pos];
				}
				else {
					y_min = sequence[x_next_pos];
					y_max = sequence[x_pos];
				}

				// width = 1, tri-height = y_max - y_min, rect-height = y_min
				area += y_min + (y_max - y_min) / 2.0;
			}
		}
		areas.push_back(area);
	}
	return areas;
}