// Le Duc Phuc Long, 2024
// If you dont' think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

#define nln '\n'
#define x first
#define y second

const ll Inf = LLONG_MAX;

// functions

ll sqr(ll x) {
	return x*x;
}

ll squareDistance(const Point& A, const Point& B) {
	return sqr(A.x - B.x) + sqr(A.y - B.y);
}

ll squareClosestDistance(const vector<Point>& pointsSortedByX, const vector<Point>& pointsSortedByY) {
	ll n = pointsSortedByX.size();
	if (n <= 1) {
		return Inf;
	}

	auto midPoint = pointsSortedByX[n/2];

	vector<Point> pointsSortedByXLeft = vector<Point>(pointsSortedByX.begin(), pointsSortedByX.begin() + n/2);
	vector<Point> pointsSortedByXRight = vector<Point>(pointsSortedByX.begin() + n/2, pointsSortedByX.end());


	vector<Point> pointsSortedByYLeft, pointsSortedByYRight;

	for (const auto& point : pointsSortedByY)
		if (point.x <= midPoint.x)
			pointsSortedByYLeft.push_back(point);
		else
			pointsSortedByYRight.push_back(point);

	// cout << pointsSortedByXLeft.size() << ' ' << pointsSortedByXRight.size() << nln;
	// cout << pointsSortedByYLeft.size() << ' ' << pointsSortedByYRight.size() << nln;

	ll delta = min(squareClosestDistance(pointsSortedByXLeft, pointsSortedByYLeft),
				squareClosestDistance(pointsSortedByXRight, pointsSortedByXRight));

	vector<Point> pointsInBand;
	for (const auto& point : pointsSortedByY)
		if (sqr(point.x - midPoint.x) < delta)
			pointsInBand.push_back(point);

	ll m = pointsInBand.size();
	for (ll i = 0; i < m; ++i)
		for (ll j = i+1; j < m && sqr(pointsInBand[i].y - pointsInBand[j].y) < delta; j++)
			delta = min(delta, squareDistance(pointsInBand[i], pointsInBand[j]));

	return delta;
}

int main(int argc, char const *argv[])
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);

	int n;	scanf("%i", &n);
	vector<Point> points(n);
	for (auto& point : points)
		scanf("%lli%lli", &point.x, &point.y);

	vector<Point> pointsSortedByX = points, pointsSortedByY = points;
	sort(pointsSortedByX.begin(), pointsSortedByX.end(), [](const Point& A, const Point& B) {
		return A.x < B.x;
	});
	sort(pointsSortedByY.begin(), pointsSortedByY.end(), [](const Point& A, const Point& B) {
		return A.y < B.y;
	});

	cout << squareClosestDistance(pointsSortedByX, pointsSortedByY);

	return 0;
}