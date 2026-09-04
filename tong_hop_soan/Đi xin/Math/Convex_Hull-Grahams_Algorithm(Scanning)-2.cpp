// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
#define x real()
#define y imag()

typedef long long ll;
typedef complex<ll> Point;
typedef complex<ll> Vector;

// functionnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

ll crossProduct(const Point& A, const Point& B, const Point& C) {
	// We check the oritation of these three points
	Vector AB = B - A, BC = C - B;
	ll cp = AB.x*BC.y -AB.y*BC.x;
	return (cp > 0) - (cp < 0);
	// if return -1, clockwise way
	// if return 1, anti-clockwise way
	// if return 0, collinear
}

vector<Point> halfHull(const vector<Point>& points) {
	vector<Point> hull;
	for (const auto& nextPoint : points) {
		while (hull.size() >= 2) {
			auto lastPoint = hull.back();
			auto beforeLastPoint = hull[hull.size()-2];
			if (crossProduct(beforeLastPoint, lastPoint, nextPoint) != 1) {
				break;
			}
			hull.pop_back();
		}
		hull.push_back(nextPoint);
	}
	return hull;
}

int main()
{
  	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	vector<Point> points(n);
	for (auto &point : points) {
		ll X, Y; 	cin >> X >> Y;
		point = {X, Y};
	}
	
	sort(points.begin(), points.end(), [](const Point& A, const Point& B) {
		return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
	});
	vector<Point> upper = halfHull(points);

	sort(points.begin(), points.end(), [](const Point& A, const Point& B) {
		return (A.x != B.x) ? (A.x > B.x) : (A.y > B.y);
	});
	vector<Point> lower = halfHull(points);

	vector<Point> convexHull = upper;
	for (const auto& point : lower) {
		if (point == convexHull.back())
			continue;
		if (point == convexHull[0])
			break;
		convexHull.push_back(point);
	}

	cout << convexHull.size() << nln;
	for (const auto& point : convexHull)
		cout << point.x << ' ' << point.y << nln;

	return 0;
}