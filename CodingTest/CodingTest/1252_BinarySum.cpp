#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
string result = "";

int main() {
	cin >> a >> b;

	if (a.length() < b.length()) a.swap(b);

	string::size_type aLen = a.length() - 1;
	string::size_type bLen = b.length() - 1;

	bool carry = false;
	int i = 0;
	for (i; i < b.length(); ++i) {
		int c, d;
		
		c = a[aLen - i] - '0';
		d = b[bLen - i] - '0';

		int sum = c + d;
		if (carry) {
			sum++;
			carry = false;
		}

		if (sum > 1) {
			carry = true;
			sum -= 2;
		}
		
		result = (char)(sum + '0') + result;
	}

	for (i; i < a.length(); ++i) {
		int c = a[aLen - i] - '0';

		if (carry) {
			c++;
			carry = false;
		}

		if (c > 1) {
			carry = true;
			c -= 2;
		}

		result = (char)(c + '0') + result;
	}

	if (carry) result = '1' + result;

	string::iterator iter = find_if(result.begin(), result.end(), [](const char& c) { return c != '0'; });
	if (iter == result.end()) cout << 0;
	else {
		for (iter; iter != result.end(); ++iter) {
			cout << *iter;
		}
	}
}