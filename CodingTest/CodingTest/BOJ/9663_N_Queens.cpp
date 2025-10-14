#include <iostream>
#include <bitset>

#define MAX_LEN 15

std::bitset<MAX_LEN> isQueenPlayed[MAX_LEN];
int countOfQueens = 0, methodCount=0;

void PlayQueen(int playedQueens) {
	if (playedQueens == countOfQueens) {
		++methodCount;
		return;
	}


}

int main() {
	for (int i = 0; i < MAX_LEN; ++i) {
		isQueenPlayed[i].set(); // 퀸이 놓여지지 않은 체스 보드 상태
	}

	std::cin >> countOfQueens;

	PlayQueen(0)

	return 0;
}