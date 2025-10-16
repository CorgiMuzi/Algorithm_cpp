#include<iostream>
#include<algorithm>
using namespace std;

struct point {
	int x, y;
	bool operator<=(const point& other) {
		if (x == other.x) {
			return y <= other.y;
		}
		return x <= other.x;
	}
};

struct line {
	point p1, p2;
};

int N = 0, parent[3000], parentCount[3000];
line lines[3000];

int CCW(const point& p1, const point& p2, const point& p3)
{
	int dir = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

	if (dir > 0) return 1;
	else if (dir == 0) return 0;
	else if (dir < 0) return -1;
}

bool isCrossed(line l1, line l2) {
	int dir1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
	int dir2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);

	if (dir1 <= 0 && dir2 <= 0) {
		if (dir1 == 0 && dir2 == 0)
		{
			if (l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
			if (l2.p2 <= l2.p1) swap(l2.p1, l2.p2);

			return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
		}
		return true;
	}
	return false;
}

int getParent(int c)
{
	if (parent[c] < 0) return c;
	else return parent[c] = getParent(parent[c]);
}

void unionGroup(int p1, int p2) // 노드 연결
{
	p1 = getParent(p1);
	p2 = getParent(p2);

	if (p1 != p2) {
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
}

int main()
{
	cin >> N;

	point p1, p2;
	for (int i = 0; i < N; i++)
	{
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		lines[i].p1 = p1;
		lines[i].p2 = p2;
		parent[i] = -1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (isCrossed(lines[i], lines[j])) {
				unionGroup(i, j);
			}
		}
	}

	int totalParents = 0, maxLines = 1;
	for (int i = 0; i < N; ++i) {
		if (parent[i] < 0) totalParents++;
		maxLines = min(maxLines, parent[i]);
	}
	cout << totalParents << "\n" << -maxLines;
}