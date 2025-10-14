#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string formula;
	cin >> formula;

	typedef string::iterator sIter;
	sIter fm_beg = formula.begin(), fm_end = formula.begin();
	vector<int> args;

	int arg = 0;
	while (fm_end != formula.end()) {
		if (*fm_end == '+') {
			arg += stoi(formula.substr(fm_beg - formula.begin(), fm_end - fm_beg));
			fm_end++;
			fm_beg = fm_end;
		}else if (*fm_end == '-') {
			arg += stoi(formula.substr(fm_beg - formula.begin(), fm_end - fm_beg));
			args.push_back(arg);

			arg = 0;
			fm_end++;
			fm_beg = fm_end;
		}
		else {
			fm_end++;
		}
		
		if (fm_end >= formula.end()) {
			arg += stoi(formula.substr(fm_beg - formula.begin(), fm_end - fm_beg));
			args.push_back(arg);
			break;
		}
	}

	int ans = 0;
	for (vector<int>::size_type i = 0; i < args.size(); ++i) {
		if (i == 0) ans = args[i];
		else {
			ans -= args[i];
		}
	}

	cout << ans;
}