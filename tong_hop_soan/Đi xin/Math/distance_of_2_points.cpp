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

ll sqr(ll X) {
	return X*X;
}

db EuclideanDistance(Point A, Point B) {
	return sqrt(sqr(A.x-B.x) + sqr(A.y-B.y));
}

db ManhattanDistance(Point A, Point B) {
	return abs(A.x-B.x) + abs(A.y-B.y);
}

int main() {
	// Test
	Point A{-4, 0}, B{-2, 0}, C{-5, 0};
	// Driver code
	cin.tie(0)->sync_with_stdio(0);

	cout << "Euclidean distance: " << EuclideanDistance(A, B) << nln;
	cout << "Manhattan distance: " << ManhattanDistance(A, B) << nln;

	return 0;
}