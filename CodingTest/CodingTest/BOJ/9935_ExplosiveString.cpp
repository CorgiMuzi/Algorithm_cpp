// TODO: 메모리 소모가 크고, 수행 시간이 오래걸림. Stack을 활용한 다른 방안을 찾아 볼 것.

#include <iostream>
#include <vector>

using namespace std;

string str = "", keyword = "";

int main() {
	cin >> str >> keyword;

	vector<pair<char, int>> ans;

	ans.push_back(str[0] == keyword[0] ? make_pair(str[0], 0) : make_pair(str[0], -1));
	if (keyword.length() == 1 && ans.back().second == 0) ans.pop_back();
	for (string::size_type i = 1; i < str.length(); ++i) {
		if (!ans.empty() && str[i] == keyword[ans.back().second + 1]) {
			ans.push_back(make_pair(str[i], ans.back().second + 1));
		}
		else {
			if (str[i] == keyword[0]) ans.push_back(make_pair(str[i], 0));
			else ans.push_back(make_pair(str[i], -1));
		}

		if (ans.back().second == keyword.length() - 1) {
			for (int j = 0; j < keyword.length(); ++j) {
				ans.pop_back();
			}
		}
	}

	str = string();
	if (ans.empty()) cout << "FRULA\n";
	else {
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i].first;
		}
	}
}