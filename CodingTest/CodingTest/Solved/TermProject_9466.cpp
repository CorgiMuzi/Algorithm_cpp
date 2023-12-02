#include <iostream>
#include <algorithm>

using namespace std;

int numOfStudents = 0;
int groupMembers = 0;
int students[100001];
bool group[100001];
bool isVisited[100001];

void checkGrouping(int curStudent) {
	isVisited[curStudent] = true;
	int nxtStudent = students[curStudent];

	if (!isVisited[nxtStudent]) {
		checkGrouping(nxtStudent);
	}	
	else if (!group[nxtStudent]) {
		for (int self = nxtStudent; self != curStudent; self = students[self]) {
			groupMembers++;
		}
		groupMembers++;
	}

	group[curStudent] = true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0;
	cin >> T;
	while (T--) {
		cin >> numOfStudents;

		groupMembers = 0;
		fill_n(group + 1, numOfStudents, false);
		fill_n(isVisited + 1, numOfStudents, false);
		
		for (int i = 1; i <= numOfStudents; ++i) {
			cin >> students[i];
		}

		for (int i = 1; i <= numOfStudents; ++i) {
			if (isVisited[i]) continue;
			checkGrouping(i);
		}
		
		cout << numOfStudents - groupMembers << "\n";
	}
}