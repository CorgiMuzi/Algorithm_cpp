#include <iostream>

using std::cin, std::cout;

int GCD(int arg1, int arg2) {
	int big = 0, small = 0;
	if (arg1 >= arg2) {
		big = arg1;
		small = arg2;
	}
	else {
		big = arg2;
		small = arg1;
	}

	while (small != 0) {
		int temp = small;
		small = big % small;
		big = temp; 
	}

	return big;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int M, N;
		cin >> M >> N;

		int x, y;
		cin >> x >> y;

		int gcd = GCD(M, N);

		cout << ((M * N) / gcd) << "\n";
	}
	
}