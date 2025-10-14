#include <iostream>
#include <algorithm>

bool subtraction(std::string& minuend, std::string& subtrahend) {
	// ������ �����Ѱ�?
	bool isValid = true;

	if (minuend.length() < subtrahend.length()) return false;

	// ������ �Ұ����� ��� MEMORY �� ��ȯ
	std::string memory = minuend;
	std::string subtrahend_extend = subtrahend;
	for (int i = 0; i < minuend.length() - subtrahend.length(); ++i) {
		subtrahend_extend = "0" + subtrahend_extend;
	}

	// ���� ����
	bool borrow = false;
	// ���� ����
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

	// ���� �Ϸ��Ŀ��� ������ �ʿ��� ��� ���� �Ұ�
	// ex) 9 - 10 = -1 ---> -1 < 0 �̹Ƿ� ���� �ʿ�
	if (borrow) {
		isValid = false;
		// MEMORY�� minuend �ʱ�ȭ
		minuend = memory;
	}
	else {
		// ������ ������ ��� ���� �ܿ� 0 ó��
		// ex) 120 - 119 = 001 ---> 1�� �ǵ��� ���� 00 ����
		auto numStart = find_if(minuend.begin(), minuend.end(), [](const char& num) { return num != '0'; });
		// ���� ������ ����� 0�� ���
		if (numStart == minuend.end()) minuend = "0";
		else {
		// ������ ����� 0�� �ƴ� ���
			int pos = numStart - minuend.begin();
			minuend = minuend.substr(pos, minuend.length() - pos);
		}
	}

	return isValid;
}

void increase(std::string& str) {
	bool carry = false;

	// ���� ����
	str[str.length() - 1]++;

	for (int pos = str.length() - 1; pos >= 0; --pos) {
		int digit = str[pos] - '0';

		// �ø� ó��
		if (carry) {
			digit++;
			carry = false;
		}

		// ����
		if (digit >= 10) {
			carry = true;
			digit -= 10;
		}

		// ���ڿ��� ����
		str[pos] = (digit + '0');
	}

	// ���� �ø� ó��
	if (carry) {
		str = "1" + str;
	}
}

std::pair<std::string, std::string> division(std::string& dividend, std::string& divisor) {
	std::pair<std::string, std::string> result = { "0", "0" };

	// �������� ������ �������� ���� ������ ����
	// ex) 12345 / 10 �� ������ ��, end = 1 �ϰ�� �������� ���� 1, end = 2 �� ��� �������� ���� 12
	int end = 1;
	// end�� �������� ������ ������ ���� ��쿡�� ������ ����
	while (end <= dividend.length()) {
		std::string minuend = dividend.substr(0, end);

		if (subtraction(minuend, divisor)) {
			dividend = minuend + dividend.substr(end, dividend.length() - end);
			// �������� ���� 0�� ���� ���
			// ex) 10350 / 10 �� ó�� �����ϸ�
			// 1. end = 1, �������� �� : 1, 1 / 10 �� ������ �Ұ�, end++ ����
			// 2. end = 2, �������� �� : 10, 10 / 10 �� ���� 1, �������� 0, �������� 0�̹Ƿ� minuend = "" �̰�, end = 1�� �ʱ�ȭ
			end = minuend.empty() ? 1 : minuend.length();

			// ���ڿ� + 1�� �����ϴ� �Լ�
			increase(result.first);
		}
		else {
			// ������ �Ұ����� ��� end ����
			end++;
			// end�� �������״��� �������� ������ ������ Ŀ����� ������ ����
			// �������� �� => �������� ��
			if (end > dividend.length()) break;
			// �������� ������ ������ ũ�� ���� ��� ���� �������� 0�� �߰�
			// ex) 1203 / 12 �� ó�� �����ϸ�
			// 1. end = 2, �������� �� : 11, 12 / 11 = 1 ... 1
			// 2. �������� 1 �̰� end = 2 �̹Ƿ� �������� ���� 10
			// 3. 10�� 11���� ������ ũ�� ������ �� ���� ũ�� �����Ƿ� ���� 0�̱⿡ ���� �������� 0�� �߰�
			//    1 -> 10
			else result.first = result.first + "0";
		}

	}

	result.second = dividend;

	// ��� ������ ���� �ܿ� 0 ����
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
