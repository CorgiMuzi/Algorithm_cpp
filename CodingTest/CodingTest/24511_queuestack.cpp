#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
vector<int> QueueIdx;
deque<int> Sequence;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int Val; cin >> Val;
		QueueIdx.push_back(Val);
	}

	for (int i = 0; i < N; ++i) {
		int Val; cin >> Val;
		if(!QueueIdx[i]) Sequence.push_back(Val);
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int Val; cin >> Val;
		Sequence.push_front(Val);
		cout << Sequence.back() << " ";
		Sequence.pop_back();
	}
}