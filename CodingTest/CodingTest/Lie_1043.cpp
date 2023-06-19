#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int people = 0, parties = 0;
	cin >> people >> parties;

	int whistleBlowers = 0;
	cin >> whistleBlowers;
	vector<int> wbVec(whistleBlowers);
	for (vector<int>::size_type i = 0; i < wbVec.size(); ++i) {
		cin >> wbVec[i];
	}

	vector<vector<int>> partyInfo(parties);
	for (vector<vector<int>>::size_type i = 0; i < partyInfo.size(); ++i) {
		int participants = 0;
		cin >> participants;

		partyInfo[i] = vector<int>(participants);
		for (vector<int>::size_type j = 0; j < partyInfo[i].size(); ++j) {
			cin >> partyInfo[i][j];
		}
	}

	vector<bool> didLied(parties, true);



	int ans = count(didLied.begin(), didLied.end(), true);
	cout << ans;
}