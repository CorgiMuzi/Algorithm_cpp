#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> parent;
vector<int> deck;

int GetParent(int self) {
	if(self == parent[self]) return self;
	return parent[self] = GetParent(parent[self]);
}

void Union(int p1, int p2) {
	p1 = GetParent(p1);
	p2 = GetParent(p2);

	if(p1 != p2) {
		if(p1 < p2) parent[p1] = p2;
		else parent[p2] = p1;
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	parent = vector<int>(N + 1);
	deck = vector<int>(M);
	
	for(int i = 0; i < M; ++i) {
		int card; cin >> card;
		parent[card] = card;
		deck[i] = card;
	}

	sort(deck.begin(), deck.end());
	
	for(int i = 0; i < K; ++i) {
		int blue; cin >> blue;
		auto card = upper_bound(deck.begin(), deck.end(), blue);
		int red = GetParent(*card);
		cout << red << "\n";
		auto pCard = upper_bound(deck.begin(), deck.end(), red);
		if(pCard == deck.end()) continue;
		Union(red, GetParent(*pCard));
	}
}