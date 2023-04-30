#include <iostream>
#include <string>

void Divide(std::string& str) {
	bool borrow = false;
	int val = 0;
	for (auto& elem : str) {
		val = elem - '0';
		if (borrow) {
			val += 10;
			std::cout << "val: " << val << "\n";
			if (val % 2 == 0) {
				borrow = false;
			}
		}

		val /= 2;
		elem = val + '0';
	}
}

void Double(std::string& str) {
	bool carry = false;
	int carryVal = 0;
	int val = 0;
	for (std::string::iterator iter = str.end() - 1; iter > str.begin() ; --iter) {
		val = *iter - '0';
		val = carry ? (val * 2) + carryVal : val * 2;
		if (val >= 10) {
			carry = true;
			carryVal = val / 10;
			val %= 10;
		}

		std::cout << "val: " << val << "\n";

		*iter = val + '0';
	}
}

void XOR_6(std::string& str) {
	 
}

int main() {
	std::string x;
	long long N;

	std::cin >> x >> N;

	while (N--) {
		if (*(x.end() - 1) % 2 == 0) {
			Divide(x);
		}
		else {
			Double(x);
		}
		std::cout << "N: " << N << ", x: " <<  x << "\n";
	}

	std::cout << x;
	

}
