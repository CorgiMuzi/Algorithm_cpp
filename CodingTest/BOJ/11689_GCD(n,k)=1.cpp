#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("input.txt", "r", stdin);

	lld N; cin >> N;
	lld cnt = N;
	for (lld i = 2; i * i <= N; ++i)
	{
		if (N % i != 0) continue;
		cnt = cnt / i * (i - 1);

		while (N % i == 0) N /= i;
	}

	if (N > 1) cnt = cnt / N * (N - 1);

	cout << cnt;

	return 0;
}
