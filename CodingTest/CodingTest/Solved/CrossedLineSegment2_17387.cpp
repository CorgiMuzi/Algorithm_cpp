#include <iostream>

using namespace std;

typedef long long lld;

struct Vec2d {
	lld x, y;

	Vec2d operator-(const Vec2d& other) {
		Vec2d out;
		out.x = x - other.x;
		out.y = y - other.y;
		return out;
	}

	bool operator<=(const Vec2d& other) {
		if(x == other.x) {
			return y <= other.y;
		}
		return x <= other.x;
	}
};

Vec2d p1, p2, p3, p4;

int CCW(Vec2d p1, Vec2d p2, Vec2d p3) {
	Vec2d v1 = p2 - p1;
	Vec2d v2 = p3 - p1;

	lld dir = v1.x * v2.y - v1.y * v2.x;
	if(dir > 0) return 1;
	else if(dir < 0) return -1;
	else return 0;
}

int main() {
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;
	
	int l1 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int l2 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if(l1 <= 0 && l2 <= 0) {
		if(l1 == 0 && l2 == 0) {
			if(p2 <= p1) swap(p1, p2);
			if(p4 <= p3) swap(p3, p4);
	
			if(p1 <= p4 && p3 <= p2) cout << "1";
			else cout << "0";
		}
		else cout << "1";
	}else cout << "0";
}