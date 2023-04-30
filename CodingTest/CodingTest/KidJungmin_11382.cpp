#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
	string ret;
	string first, second;
	if (a.size() >= b.size()) {
		first = a;
		second = b;
	}
	else {
		first = b;
		second = a;
	}

	string::size_type digit = 0;
	bool carry = false;
	while (digit < second.size()) {
		int op1 = *(first.end() - (1 + digit)) - '0';
		int op2 = *(second.end() - (1 + digit)) - '0';

		int sum = op1 + op2 + carry;

		if (sum >= 10) {
			carry = true;
			sum -= 10;
		}
		else {
			carry = false;
		}

		char c = sum + '0';

		ret.push_back(c);
		++digit;
	}

	if (digit < first.size()) {
		while (digit < first.size()) {
			char c = first[first.size() - digit - 1];

			int i = c - '0';
			i += carry;
			if (i >= 10) {
				carry = true;
				i -= 10;
			}
			else {
				carry = false;
			}

			c = i + '0';

			ret.push_back(c);
			++digit;
		}
	}

	if (carry) {
		ret.push_back('1');
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	string d = add(a, b);

	d = add(d, c);

	cout << d;
}