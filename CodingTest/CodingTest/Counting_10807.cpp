#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int v;
	cin >> v;

	int counting = 0; 
	for (int i = 0; i < N; ++i) {
		if (arr[i] == v) {
			counting++;
		}
	}

	cout << counting;

	delete[] arr;
}