#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	std::unordered_map<std::string, std::string> m_ScNm;
	m_ScNm["northlondo"] = "NLCS";
	m_ScNm["branksomeh"] = "BHA";
	m_ScNm["koreainter"] = "KIS";
	m_ScNm["stjohnsbur"] = "SJA";

	std::string scNm;
	std::cin >> scNm;
	
	while (m_ScNm[scNm] == "") {
		for (int i = 0; i < 10; ++i) {
			scNm[i] -= 1;
			if (scNm[i] < 97) scNm[i] = 122;
		}
	}

	std::cout << m_ScNm[scNm];
}