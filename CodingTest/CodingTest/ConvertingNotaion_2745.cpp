#include <iostream>
#include <string>

using namespace std;

int main(){
	int B;
	string number;

	cin >> number >> B;

	int decimal = 0;
	for (string::size_type i = number.length() - 1; i > 0; --i) {
		cout << "i: " << i << ", digit: " << number[i] << "\n";
		int digit = 0;
		if (number[i] > 'A') digit = number[i] - 'A' + 10;
		else digit = number[i] - '0';

		decimal += std::pow(B, number.length() - 1 - i) * (number[i] - '0');
	}

	cout << decimal;
}