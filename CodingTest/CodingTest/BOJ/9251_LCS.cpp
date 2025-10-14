#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string str1, str2;

	cin >> str1 >> str2;

	vector<vector<int>> LCS(str2.size() + 1, vector<int>(str1.size() + 1, 0));

	char c1 = str1[0], c2 = str2[0];
	for (vector<vector<int>>::size_type str2_sz = 1; str2_sz < LCS.size(); ++str2_sz) {
		c2 = str2[str2_sz - 1];
		for (vector<int>::size_type str1_sz = 1; str1_sz < LCS[str2_sz].size(); ++str1_sz) {
			c1 = str1[str1_sz - 1];
			if (c1 == c2) {
				LCS[str2_sz][str1_sz] = LCS[str2_sz - 1][str1_sz - 1] + 1;
			}
			else {
				LCS[str2_sz][str1_sz] = max(LCS[str2_sz - 1][str1_sz], LCS[str2_sz][str1_sz - 1]);
			}
		}
	}

	cout << LCS[str2.size()][str1.size()];
}