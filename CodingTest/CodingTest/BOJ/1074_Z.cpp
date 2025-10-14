#include <cstdio>
#include <cmath>

using namespace std;

int selectQuadrant(int r, int c, int start, int unit) {
	int quadrant;
	if (r >= unit && c >= unit) {
		quadrant = 3;
	}
	else if (r >= unit && c < unit) {
		quadrant = 2;
	}
	else if (r < unit && c >= unit) {
		quadrant = 1;
	}
	else if (r < unit && c < unit) {
		quadrant = 0;
	}

	start = start + unit * unit * quadrant;
	if (unit == 1) { return start; }

	if(r >= unit) r -= unit;
	if(c >= unit) c -= unit;
	
	unit /= 2;

	return selectQuadrant(r, c, start, unit);
}

int main() {
	int N, r, c;
	scanf("%d%d%d", &N, &r, &c);

	int unit = pow(2, N) / 2;
	int ans = selectQuadrant(r, c, 0, unit);
	printf("%d", ans);
}