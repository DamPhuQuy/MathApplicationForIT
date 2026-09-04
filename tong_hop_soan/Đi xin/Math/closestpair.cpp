// Le Duc Phuc Long, 2024
// If you don't think twice, you have to code twice

#include <bits/stdc++.h>
// #include <conio.h>

using namespace std;
	

#define nln '\n'
#define x first
#define y second

// typedef __int128_t ll;
typedef long long ll;
typedef pair<ll, ll> point;

const ll Inf = static_cast<__int128_t>(8*1e18);

// Functionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

// __int128_t sqrt(__int128_t x) {
//     if (x == 0 || x == 1) {

//         return x;
//     }

//     __int128_t start = 1, end = x, ans = 0;
//     while (start <= end) {
//         __int128_t mid = (start + end) / 2;

//         if (mid * mid == x)
//             return mid;

//         if (mid * mid < x) {
//             start = mid + 1;
//             ans = mid;
//         } else {
//             end = mid - 1;
//         }
//     }

//     return ans;
// }

// __int128_t ceil(__int128_t x) {
//     return x+1;
// }

// string largeIntToString(__int128_t n) {
//     if (n == 0) return "0";

//     string result;
//     while (n > 0) {
//         result = char('0' + (n % 10)) + result;
//         n /= 10;
//     }

//     return result;
// }

// std::ostream& operator<<(std::ostream& os, const __int128_t n) {
//     os << largeIntToString(n);
//     return os;

// }

ll sqr(ll x) {
	return x*x;
}

ll distance(const point& A, const point& B) {
	return sqr(A.x - B.x) + sqr(A.y - B.y);
}

bool cmpBy_x(const point& A, const point& B) {
	return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}

bool cmpBy_y(const point& A, const point& B) {
	return (A.y != B.y) ? (A.y < B.y) : (A.x < B.x);
}

ll closestBruteforces(const vector<point>& points) {
	// cout << "went into closestBruteforces: " << nln;
	ll closestDis = Inf;
	for (int i = 0; i < (ll)(points.size()-1); ++i)
		for (int j = i+1; j < (ll)(points.size()); ++j) {
			// cout << largeIntToString(distance(points[i], points[j])) << nln;
			closestDis = min(distance(points[i], points[j]), closestDis);
		}
	return closestDis;
}

pair<vector<point>, vector<point>> devideByMidPoint(const vector<point>& points, const point& midPoint) {
	vector<point> left, right;
	for (const auto& p : points) 
		if (p.x < midPoint.x)
			left.push_back(p);
		else
			right.push_back(p);
	return make_pair(left, right);
}

ll recurs(const vector<point>& pointsSortedBy_x, const vector<point>& pointsSortedBy_y) {
	// if (pointsSortedBy_x.size() <= 3) {
	// 	// cout << largeIntToString(closestBruteforces(pointsSortedBy_x)) << nln;
	// 	return closestBruteforces(pointsSortedBy_x);
	// }
	if (pointsSortedBy_x.size() <= 1)
		return LLONG_MAX;

	// compute vector points sorted by x on the left and right mid point
	// compute vector points sorted by y on the left and right mid point

	point midPoint = pointsSortedBy_x[pointsSortedBy_x.size()/2];
	// cout <<  "midPoint: " < largeIntToString(midPoint.x) << nln;
	// getch();

	vector<point> pointsSortedBy_xLeft, pointsSortedBy_xRight;
	vector<point> pointsSortedBy_yLeft, pointsSortedBy_yRight;

	auto devidePointsSortedBy_x = devideByMidPoint(pointsSortedBy_x, midPoint);
	pointsSortedBy_xLeft = devidePointsSortedBy_x.first;
	pointsSortedBy_xRight = devidePointsSortedBy_x.second;

	auto devidePointsSortedBy_y = devideByMidPoint(pointsSortedBy_y, midPoint);
	pointsSortedBy_yLeft = devidePointsSortedBy_y.first;
	pointsSortedBy_yRight = devidePointsSortedBy_y.second;
	
	// call recurs(poinsSortedBy_xLeft, pointsSortedBy_xRight) to find lambda
	ll deltaLeft = recurs(pointsSortedBy_xLeft, pointsSortedBy_yLeft);
	ll deltaRight = recurs(pointsSortedBy_xRight, pointsSortedBy_yRight);

	ll closestDis = min(deltaLeft, deltaRight);

	// Iterate pointsSortedBy_y to get all pointsSortedBy_y in range [midpoint.x - lambda, midpointx + lambda]
	vector<point> band;
	for (const auto& p : pointsSortedBy_y)
		if (midPoint.x - ceil(sqrt(closestDis)) < p.x && p.x < midPoint.x + ceil(sqrt(closestDis)))
			band.push_back(p);

	// Iterate next sever points each point with next 7 points in pointsSortedBy_y in Band
	for (ll i = 0; i < (ll)(band.size()); ++i)
		for (ll j = i+1; j < (ll)band.size() && ceil(sqrt(band[j].y - band[i].y)) < closestDis; ++j)
			closestDis = min(closestDis, distance(band[i], band[j]));

	// return 
	return closestDis;
}

ll closest(const vector<point>& points) {
    vector<point> pointsSortedBy_x = points;
    sort(pointsSortedBy_x.begin(), pointsSortedBy_x.end(), cmpBy_x);
    vector<point> pointsSortedBy_y = points;
    sort(pointsSortedBy_y.begin(), pointsSortedBy_y.end(), cmpBy_y);
    return recurs(pointsSortedBy_x, pointsSortedBy_y);
}

int main(int argc, char* argv[]) {
	// freopen("in", "r", stdin);
	// cin.tie(0)->sync_with_stdio(0);
	// cout.tie(0)->sync_with_stdio(0);
	int n;	cin >> n;
	vector<point> points(n);
	for (auto& p : points) {
		long long x, y;	cin >> x >> y;
		p.x = x, p.y = y;
		// cout << x << ' ' << y << nln;
	}

	cout << closestBruteforces(points) << nln;
	// cout << largeIntToString(closest(points));

	return 0;
}