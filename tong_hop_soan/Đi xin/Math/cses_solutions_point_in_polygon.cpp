// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;
typedef long long db;

typedef complex<db> Point;
typedef complex<db> Vector;

#define x real()
#define y imag()

db crossProduct(Point A, Point B) {
	return (conj(A)*B).imag();
}

db dotProduct(Point A, Point B) {
	return A.x*B.x + A.y*B.y;
}

Vector calculateVector(Point A, Point B) {
	return B-A;
}

ll sqr(ll x) {
	return x*x;
}

ll lenSquareOfVector(Vector A) {
	return sqr(A.x) + sqr(A.y);
}

bool isOnSegmentLine(Point A, Point B, Point C) {
	Vector BA = calculateVector(B, A);
	Vector BC = calculateVector(B, C);
	ll lenSquareOfVectorBA = lenSquareOfVector(BA);
	ll lenSquareOfVectorBC = lenSquareOfVector(BC)
	return (dotProduct(BA, BC) == lenSquareOfVectorBA*lenSquareOfVectorBC);
		
}

bool checkThePosition(Point A, Point B, Point C) {
	// return ((A.y > B.y) != A.y > C.y && 
	// 	A.x < (B.x + (A.y-B.y)*(C.x-B.x)/(C.y-B.y)));
	return ((A.y > B.y) != (A.y > C.y) && 
		(A.x-B.x)*(C.y-B.y) < (A.y-B.y)*(C.x-B.x));
}

bool comp(const Point &A, const Point &B) {
	return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;	cin >> n >> m;
	// Point A{-4, 0}, B{-2, 0}, C{-5, 0};
	vector<Point> Polygon(n);
	for (auto &P : Polygon) {
		db X, Y;	cin >> X >> Y;
		P = Point(X, Y);
	}
	sort(Polygon.begin(), Polygon.end(), comp);
	// for (auto P : Polygon)
	// 	cout << P << nln;

	while (m--) {
		db X, Y;	cin >> X >> Y;
		Point A = {X, Y};
		Point B = Polygon[0];
		bool flag = false; // is on the boundary
		ll cnt = 0; // number of intersections with edges
		for (int i = 1; i <= n; ++i) {
			Point C = Polygon[i%n];
			if (isOnSegmentLine(A, B, C)) {
				flag = true;
				break;
			} else {
				cnt += checkThePosition(A, B, C);
			}
			B = C;
		}
		if (flag) {
			cout << "BOUNDARY" << nln;
		} else {
			cout << (cnt % 2 ? "INSIDE" : "OUTSIDE") << nln;
		}
	}

	return 0;
}