#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <valarray>

using namespace std;

struct Point
{
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    long long x, y;
};

Point basePoint;

long long cross_product(const Point& p1, const Point& p2, const Point& p3)
{
    long long dx1 = p2.x - p1.x;
    long long dy1 = p2.y - p1.y;

    long long dx2 = p3.x - p2.x;
    long long dy2 = p3.y - p2.y;

    return dx1 * dy2 - dy1 * dx2;
}

bool compare(const Point& p1, const Point& p2)
{
    long long dir = cross_product(basePoint, p1, p2);
    if (dir == 0)
    {
        long long dx1 = p1.x - basePoint.x;
        long long dy1 = p1.y - basePoint.y;

        long long dx2 = p2.x - basePoint.x;
        long long dy2 = p2.y - basePoint.y;

        long long dist1 = dx1 * dx1 + dy1 * dy1;
        long long dist2 = dx2 * dx2 + dy2 * dy2;

        return dist1 < dist2;        
    }

    return dir > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; ++i)
    {
        long long x, y; cin >> x >> y;
        points[i] = Point(x, y);
    }

    int base = 0;
    for (int i = 0; i < N; ++i)
    {
        if (points[i].y < points[base].y || (points[i].y == points[base].y && points[i].x < points[base].x))
        {
            base = i;
        }
    }

    swap(points[0], points[base]);
    basePoint = points[0];

    sort(points.begin() + 1, points.end(), compare);

    stack<Point> stk;
    stk.push(points[0]);
    stk.push(points[1]);

    for (int i = 2; i < N; ++i)
    {
        while (stk.size() >= 2)
        {
            Point& mid = stk.top();
            stk.pop();
            Point& start = stk.top();
            Point& end = points[i];

            long long dir = cross_product(start, mid, end);
            if (dir > 0)
            {
                stk.push(mid);
                break;
            }
        }

        stk.push(points[i]);
    }
    
    cout << stk.size();
    
    return 0;
}
