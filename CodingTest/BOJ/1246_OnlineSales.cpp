#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Customers;
int Earn = 0, Cost = 0;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int fund; cin >> fund;
		Customers.push_back(fund);
	}

	sort(Customers.begin(), Customers.end(), std::greater<int>());
	
	int Egg = 1;
	for (const int& Sales : Customers) {
		int Expect = Egg * Sales;
		if (Expect > Earn) {
			Earn = Expect;
			Cost = Sales;
		}

		if (Egg + 1 <= N) Egg++;
	}

	cout << Cost << " " << Earn;
}