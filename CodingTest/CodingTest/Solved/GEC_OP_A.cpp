#include <iostream>
#include <string>

int main() {
	std::string abbr, schoolNm;
	std::cin >> abbr;
	if (abbr == "NLCS") schoolNm = "North London Collegiate School";
	else if (abbr == "BHA") schoolNm = "Branksome Hall Asia";
	else if (abbr == "KIS") schoolNm = "Korea International School";
	else if (abbr == "SJA") schoolNm = "St. Johnsbury Academy";

	std::cout << schoolNm;
}