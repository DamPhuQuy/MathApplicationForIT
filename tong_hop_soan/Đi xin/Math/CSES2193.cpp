#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

typedef long long ll;
typedef long double db;

typedef complex<ll> Point;
typedef complex<ll> Vector;

#define x real()
#define y imag()

ll crossProduct(Point A, Point B) {
	ll cp = (conj(A)*B).imag();
	return cp;
}

ll doubleAreaPolygon(const vector<Point> &Polygon) {
	ll A = 0;
	for (int i = 0; i < Polygon.size(); ++i) {
		Point E1 = Polygon[i], E2 = Polygon[(i+1)%(Polygon.size())];
		A += crossProduct(E1, E2);
	}
	return abs(A);
}

ll noBoundaryPoint(const vector<Point> &Polygon) {
	ll cnt = 0;
	for (int i = 0; i < Polygon.size(); ++i) {
		Point E1 = Polygon[i], E2 = Polygon[(i+1)%(Polygon.size())];
		cnt += abs(__gcd(E1.x - E2.x, E1.y - E2.y));
	}
	return cnt;
}

int main(int argc, char* argv[]) {
	cin.tie(0)->sync_with_stdio(0);
	vector<Point> Polygon;
	ll n;	cin >> n;
	while (n--) {	
		ll X, Y;	cin >> X >> Y;
		Polygon.push_back(Point(X, Y));
	}

	ll doubleA = doubleAreaPolygon(Polygon),
	B =  noBoundaryPoint(Polygon);

	// Pick's Theorem
	// A = B/2 + I - 1 
	// => 2A = B + 2I - 2
	// => 2I = 2A - B + 2
	// => I = A - B/2 + 1 (We are not gonna do this)
	ll I = (doubleA - B + 2)/2;

	cout <<  I << ' ' << B << nln;

	return 0;
}