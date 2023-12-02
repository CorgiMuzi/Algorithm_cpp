#include <iostream>
#include <map>
#include <string>

using std::map, std::string, std::cin, std::cout;

int main() {
	int N, M;
	cin >> N >> M;

	map<string, string> vault;

	for (int i = 0; i < N; ++i) {
		string url;
		cin >> url;
		cin >> vault[url];
	}

	for (int i = 0; i < M; ++i) {
		string url;	
		cin >> url;
		cout << vault[url] << "\n";
	}
}