#include <iostream>
#include <vector>

using namespace std;

vector<int> players;
bool cards[1000001];
int score[1000001];
int N;

int main() {
	cin >> N;
	
	fill_n(score, 1000001, 0);
	for(int i = 0; i < N; ++i) {
		int card; cin >> card;
		players.push_back(card);
		cards[card] = true;
	}
	
	for(const int& card : players) {
		for(int i = 2 * card; i < 1000001; i += card) {
			if(cards[i]) {
				score[i]--;
				score[card]++;
			}
		}
	}

	for(const int& card : players) {
		cout << score[card] << " ";
	}
}