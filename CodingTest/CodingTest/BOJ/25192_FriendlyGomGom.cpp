#include <iostream>
#include <map>

using namespace std;

int N;
int GomGom = 0;
map<string, bool> History;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		string Sender; cin >> Sender;
		if (Sender == "ENTER") {
			History.clear();
		}
		else if(History.find(Sender) == History.end() || !History[Sender]) {
			History[Sender] = true;
			GomGom++;
		}
	}

	cout << GomGom;
}