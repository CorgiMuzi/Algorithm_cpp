#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int>, vector<int>);
int gcd(int a, int b);
int condCase(vector<int>, vector<int>);

int main() {
	vector<int> arrayA = { 2 };
	vector<int> arrayB = { 8 };

	cout << solution(arrayA, arrayB);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;
	int cDivisor = 0;

	cDivisor = condCase(arrayA, arrayB) > condCase(arrayB, arrayA) ? condCase(arrayA, arrayB) : condCase(arrayB, arrayA);
	answer = cDivisor;

	return answer;
}

// 최대 공약수 구하기
int gcd(int a, int b) {
	// 유클리드 호제법
	int dividend = a;
	int divisor = b;
	int r = dividend % divisor;
	while (r != 0) {
		dividend = divisor;
		divisor = r;
		r = dividend % divisor;
	}

	return divisor;
}

int condCase(vector<int> array1, vector<int> array2) {
	int cDivisor = array1[0];	
	if (array1.size() > 1) {	// array1의 크기가 2개 이상일 경우 최대공약수 구하기
		cDivisor = gcd(array1[0], array1[1]);

		for (int i = 2; i < array1.size(); i++) {
			cDivisor = gcd(cDivisor, array1[i]);
		}
	}
	

	// array2 의 모든 요소를 나눌수 없는지 평가
	for (int i : array2) {
		if (i % cDivisor == 0)
			return 0;
	}


	return cDivisor;
}

