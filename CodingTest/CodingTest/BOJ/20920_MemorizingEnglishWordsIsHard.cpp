#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> Occurance;
vector<string> words;
int N, M;

bool cmp(const string& left, const string& right) {
	if (Occurance[left] == Occurance[right]) {
		if (left.length() == right.length()) return left < right;
		return left.length() > right.length();
	}

	return Occurance[left] > Occurance[right];
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string word;
		cin >> word;

		if (word.length() < M) continue;

		Occurance[word]++;
	}

	for (const pair<string, int>& p : Occurance) {
		words.push_back(p.first);
	}

	sort(words.begin(), words.end(), cmp);

	for (const string& word : words) {
		cout << word << "\n";
	}
}