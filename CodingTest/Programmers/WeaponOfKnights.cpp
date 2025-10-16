#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
	int answer = 0;
	// 약수 구하기
	vector<vector<int>::size_type> damage = {};
	vector<int> divisors;
	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				divisors.push_back(j);
				if (j != i / j) {
					divisors.push_back(i / j);
				}
			}
		}
		// 무기의 공격력 계산
		damage.push_back(divisors.size());
		divisors.clear();
	}
	

	// 이웃나라와의 협약 체크
	for (vector<int>::size_type i = 0; i < damage.size(); i++) {
		if (damage[i] > limit) {
			damage[i] = power;
		}
	}

	// 비용 계산
	int charge = 0;
	for (vector<int>::size_type i = 0; i < damage.size(); i++) {
		charge += damage[i];
	}

	answer = charge;
	
	return answer;
}

int main() {
	int number = 10;
	int limit = 3;
	int power = 2;

	cout << solution(number, limit, power);
}