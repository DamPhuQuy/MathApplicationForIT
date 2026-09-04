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
	return cp;
}

int main() {
	// Test
	// Point A{-4, 0}, B{-2, 0}, C{-5, 0};
	// Driver code
	cin.tie(0)->sync_with_stdio(0);
	ll n;	cin >> n;
	vector<Point> Polygon(n);
	for (auto &P : Polygon) {
		ll X, Y;	cin >> X >> Y;
		P = Point(X, Y);
	}

	// Using Shoelace formula
	ll s = 0;
	for (int i = 0; i < n; ++i) {
		Point P1 = Polygon[i], P2 = Polygon[(i+1)%n];
		s += crossProduct(P1, P2);
	}

	cout << setprecision(1) << fixed << abs(s/2.0) << nln;

	return 0;
}