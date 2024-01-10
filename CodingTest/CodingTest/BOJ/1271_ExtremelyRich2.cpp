#include <iostream>
#include <algorithm>

bool subtraction(std::string& minuend, std::string& subtrahend) {
	// 뺄셈이 가능한가?
	bool isValid = true;

	if (minuend.length() < subtrahend.length()) return false;

	// 뺄셈이 불가능할 경우 MEMORY 값 반환
	std::string memory = minuend;
	std::string subtrahend_extend = subtrahend;
	for (int i = 0; i < minuend.length() - subtrahend.length(); ++i) {
		subtrahend_extend = "0" + subtrahend_extend;
	}

	// 내림 여부
	bool borrow = false;
	// 뺄셈 수행
	for (int pos = subtrahend_extend.length() - 1; pos >= 0; --pos) {
		int sub = subtrahend_extend[pos] - '0';
		int num = minuend[pos] - '0';

		if (borrow) {
			num--;
			borrow = false;
		}

		num -= sub;
		if (num < 0) {
			borrow = true;
			num += 10;
		}

		minuend[pos] = num + '0';
	}

	// 뺄셈 완료후에도 내림이 필요한 경우 뺄셈 불가
	// ex) 9 - 10 = -1 ---> -1 < 0 이므로 내림 필요
	if (borrow) {
		isValid = false;
		// MEMORY로 minuend 초기화
		minuend = memory;
	}
	else {
		// 뺄셈이 가능할 경우 앞의 잔여 0 처리
		// ex) 120 - 119 = 001 ---> 1이 되도록 앞의 00 제거
		auto numStart = find_if(minuend.begin(), minuend.end(), [](const char& num) { return num != '0'; });
		// 만약 뺄셈의 결과가 0일 경우
		if (numStart == minuend.end()) minuend = "0";
		else {
		// 뺄셈의 결과가 0이 아닐 경우
			int pos = numStart - minuend.begin();
			minuend = minuend.substr(pos, minuend.length() - pos);
		}
	}

	return isValid;
}

void increase(std::string& str) {
	bool carry = false;

	// 덧셈 수행
	str[str.length() - 1]++;

	for (int pos = str.length() - 1; pos >= 0; --pos) {
		int digit = str[pos] - '0';

		// 올림 처리
		if (carry) {
			digit++;
			carry = false;
		}

		// 덧셈
		if (digit >= 10) {
			carry = true;
			digit -= 10;
		}

		// 문자열에 적용
		str[pos] = (digit + '0');
	}

	// 최종 올림 처리
	if (carry) {
		str = "1" + str;
	}
}

std::pair<std::string, std::string> division(std::string& dividend, std::string& divisor) {
	std::pair<std::string, std::string> result = { "0", "0" };

	// 나눗셈을 수행할 나눠지는 수를 결정할 범위
	// ex) 12345 / 10 을 수행할 때, end = 1 일경우 나눠지는 수는 1, end = 2 일 경우 나눠지는 수는 12
	int end = 1;
	// end가 나눠지는 수보다 범위가 작을 경우에만 나눗셈 가능
	while (end <= dividend.length()) {
		std::string minuend = dividend.substr(0, end);

		if (subtraction(minuend, divisor)) {
			dividend = minuend + dividend.substr(end, dividend.length() - end);
			// 나눠지는 수가 0만 남을 경우
			// ex) 10350 / 10 을 처음 수행하면
			// 1. end = 1, 나눠지는 수 : 1, 1 / 10 은 나눗셈 불가, end++ 수행
			// 2. end = 2, 나눠지는 수 : 10, 10 / 10 은 몫이 1, 나머지가 0, 나머지가 0이므로 minuend = "" 이고, end = 1로 초기화
			end = minuend.empty() ? 1 : minuend.length();

			// 문자열 + 1을 수행하는 함수
			increase(result.first);
		}
		else {
			// 뺄셈이 불가능할 경우 end 증가
			end++;
			// end를 증가시켰더니 나눠지는 수보다 범위가 커질경우 나눗셈 종료
			// 나눠지는 수 => 나머지가 됨
			if (end > dividend.length()) break;
			// 나눠지는 수보다 범위가 크지 않을 경우 몫의 마지막에 0을 추가
			// ex) 1203 / 12 를 처음 수행하면
			// 1. end = 2, 나눠지는 수 : 11, 12 / 11 = 1 ... 1
			// 2. 나머지가 1 이고 end = 2 이므로 나눠지는 수는 10
			// 3. 10은 11보다 범위가 크지 않지만 그 수가 크지 않으므로 몫은 0이기에 몫의 마지막에 0을 추가
			//    1 -> 10
			else result.first = result.first + "0";
		}

	}

	result.second = dividend;

	// 몫과 나머지 앞의 잔여 0 제거
	auto numStart = find_if(result.first.begin(), result.first.end(), [](const char& num) { return num != '0'; });
	if (numStart == result.first.end()) result.first = "0";
	else {
		int pos = numStart - result.first.begin();
		result.first = result.first.substr(pos, result.first.length() - pos);
	}

	numStart = find_if(result.second.begin(), result.second.end(), [](const char& num) { return num != '0'; });
	if (numStart == result.second.end()) result.second = "0";
	else {
		int pos = numStart - result.second.begin();
		result.second = result.second.substr(pos, result.second.length() - pos);
	}

	return result;
}

int main() {
	std::string dividend, divisor;
	std::cin >> dividend >> divisor;

	std::pair<std::string, std::string> result;
	result = division(dividend, divisor);
	std::cout << result.first << "\n" << result.second;
}
