#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int len[1000001];
int lisLen = 0;
int arrLen;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> arrLen;

	arr[0] = len[0] = 0;

	for (int i = 1; i <= arrLen; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= arrLen; ++i) {
		auto lb = lower_bound(len, len + lisLen + 1, arr[i]);
		if (lb == len + lisLen + 1) {
			len[++lisLen] = arr[i];
		}
		else {
			len[lb - len] = min(len[lb - len], arr[i]);
		}
	}

	cout << lisLen << "\n";
}