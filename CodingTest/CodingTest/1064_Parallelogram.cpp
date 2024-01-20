#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef pair<double, double> pdd;
pdd p[3];
double a, b, c;
double ab, bc, ac;
double MaxRound, MinRound;

double GetDistance(const pdd& p1, const pdd& p2) {
	double xDiff = p2.first - p1.first;
	double yDiff = p2.second - p1.second;

	return sqrt(xDiff * xDiff + yDiff * yDiff);
}

bool IsOneLine() {
	double diff1 = abs((p[1].second - p[0].second) / (p[1].first - p[0].first));
	double diff2 = abs((p[2].second - p[0].second) / (p[2].first - p[0].first));
	
	return diff1 == diff2;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 3; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	if(IsOneLine()) {
		cout << "-1.0";
		return 0;
	}

	a = GetDistance(p[0], p[1]);
	b = GetDistance(p[1], p[2]);
	c = GetDistance(p[0], p[2]);

	ab = 2 * (a + b);
	bc = 2 * (b + c);
	ac = 2 * (a + c);
	
	MaxRound = max(ab, max(bc, ac));
	MinRound = min(ab, min(bc, ac));

	cout << fixed << setprecision(16) <<  MaxRound - MinRound;
}