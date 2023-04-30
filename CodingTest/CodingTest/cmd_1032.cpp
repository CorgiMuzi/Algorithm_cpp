#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<string> results(N);
	for (vector<string>::size_type i = 0; i < N; ++i) {
		cin >> results[i];
	}

	string command = results[0];
	for (vector<string>::size_type i = 1; i < results.size(); ++i) {
		for (string::size_type j = 0; j < results[i].size(); ++j) {
			if (command[j] != results[i][j]) command[j] = '?';
		}
	}

	cout << command;
}