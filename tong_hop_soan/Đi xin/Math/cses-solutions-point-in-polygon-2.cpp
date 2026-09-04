// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;
typedef long double db;

typedef complex<ll> Point;
typedef complex<ll> Vector;

#define x real()
#define y imag()

const ll INF = int(1e9) + 7;

ll crossProduct(Vector A, Vector B) {
	ll cp = (conj(A)*B).imag();
	return (cp > 0) - (cp < 0);
}


Vector calculateVector(Point A, Point B) {
	return B-A;
}

bool comp(const Point &A, const Point &B) {
	return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}


bool isMidPoint(Point P, Point A, Point B) {
	vector<Point> L = {A, B, P};
	sort(L.begin(), L.end(), comp);
	return L[1] == P;
}

bool isOnSegmentLine(Point P, Point A, Point B) {
	Vector PA = calculateVector(P, A);
	Vector PB = calculateVector(P, B);
	return (crossProduct(PA, PB) == 0 && isMidPoint(P, A, B));
}


Vector inverseVector(Vector V) {
	return {-V.x, -V.y};
}

bool isIntersecting(Point A, Point B, Point C, Point D) {
	// A and B will be 2 vericles of an edge in polygon
	// C is the point we are dealing
	// D is the point {INF, INF}

	Vector AC = calculateVector(A, C);
	Vector AD = calculateVector(A, D);
	Vector BC = calculateVector(B, C);
	Vector BD = calculateVector(B, D);

	Vector CA = inverseVector(AC);
	Vector CB = inverseVector(BC);
	Vector DA = inverseVector(AD);
	Vector DB = inverseVector(BD);

	ll cpACxAD = crossProduct(AC, AD);
	ll cpBCxBD = crossProduct(BC, BD);

	ll cpCAxCB = crossProduct(CA, CB);
	ll cpDAxDB = crossProduct(DA, DB);

	if (cpACxAD*cpBCxBD < 0 && cpCAxCB*cpDAxDB < 0)
		return 1;
	if (cpACxAD == 0 && isMidPoint(A, C, D) && cpBCxBD > 0)
		return 1;
	if (cpBCxBD == 0 && isMidPoint(B, C, D) && cpACxAD > 0)
		return 1;
	return 0;
}

ll pointToPolygon(const Point &P, const vector<Point> &Polygon) {
	ll n = Polygon.size();

	Point InfPoint(INF, INF);

	bool isBoundary = false;

	ll noIntersection = 0;

	for (ll i = 0; i < n; ++i) {
		Point A = Polygon[i], B = Polygon[(i+1)%n];
		if (isOnSegmentLine(P, A, B)) {
			isBoundary = true;
			break;
		}
		noIntersection += isIntersecting(A, B, P, InfPoint);
	}

	switch (isBoundary) {
	case 1:
		return 0;
	case 0:
		return (noIntersection % 2) ? 1 : -1;
	}

}

int main() {
	// Test
	// Point A{-4, 0}, B{-2, 0}, C{-5, 0};
	// Driver code
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;	cin >> n >> m;
	vector<Point> Polygon(n);
	for (auto &P : Polygon) {
		ll X, Y;	cin >> X >> Y;
		P = Point(X, Y);
	}

	while (m--) {
		ll X, Y;	cin >> X >> Y;
		Point P(X, Y);	
		ll postion =  pointToPolygon(P, Polygon);
		cout << ((postion == 0) ? "BOUNDARY" : ((postion == 1) ? "INSIDE" : "OUTSIDE")) << nln;
	}

	return 0;
}