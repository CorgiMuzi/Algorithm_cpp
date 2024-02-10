#include <iostream>
#include <map>

using namespace std;

map<string, int> books;
int N;
string BestSeller;
int Sales = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string book; cin >> book;
		books[book]++;
	}

	for (pair<string, int> Sale : books) {		
		if (Sale.second > Sales) {
			BestSeller = Sale.first;
			Sales = Sale.second;
		}
	}

	cout << BestSeller;
}