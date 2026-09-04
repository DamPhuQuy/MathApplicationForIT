// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

// This code still not be accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nln '\n'

//functionnnnnnnnnnnnnnnnnnnnnn

ll sqr(ll x) {
    return x*x;
}

struct Point {
	ll x, y;

    bool operator<(const Point& other) const {
        return (x != other.x) ? x < other.x : y > other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return x != other.x || y != other.y;
    }

    friend ostream& operator<<(ostream& os, const Point& point) {
        os << point.x << ' ' << point.y;
        return os;
    }

    friend istream& operator>>(istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    ll distance(const Point& other) const {
        return sqr(x-other.x) + sqr(y-other.y);
    }
};

ll orientation(Point A, Point B, Point C) {
	// We define the orientation of three given points by 
	// calculating the slope
	// slope of segment AB : (yB - yA) / (xB - xA)
	// slope of segment BC : (yC - yB) / (xC - xB)
	// We compare (yB - yA) / (xB - xA) and (yC - yB) / (xC - xB)
	// We compare (yB - yA) * (xC - xB) and (yC - yB) * (xB - xA)
	ll res = (B.y - A.y) * (C.x - B.x) - (C.y - B.y) * (B.x - A.x);
	return (res == 0) ? 0 : (res > 0 ? 1 : -1);
	// if the function return 0 --> collinear
	// if the function return 1 --> clockwise
	// if the function return -1 --> anti-clockwise
}

bool threeDistinctPoints(const Point& A, const Point& B, const Point& C) {
    return (A != B) && (A != C) && (B != C);
}

vector<Point> convexHull(vector<Point>& points) {
    set<Point> remainPoints (points.begin(), points.end());
    // for (auto point : remainPoints)
    //     cout << point << nln;

    vector<Point> hull = {*remainPoints.begin()};
    Point lastOnHull = hull.back();

    while (true) {
        // We pick a arbitrary point as a next point
        // But it need to be distint with our lastOnHull point
        // cout << "lastOnHull: " << lastOnHull << nln;
        Point guestNext = *remainPoints.begin();
        for (const auto& potentialPoint : remainPoints)
            if (potentialPoint != lastOnHull && potentialPoint != hull[0]) {
                guestNext = potentialPoint;
                break;
            }
        // cout << "guestNext: " << guestNext << nln;
        for (const auto& potentialPoint : remainPoints) {
            if (threeDistinctPoints(lastOnHull, guestNext, potentialPoint)) {
                ll ori = orientation(lastOnHull, guestNext, potentialPoint);
                if (ori == -1 || (ori == 0 && potentialPoint != hull[0])) {
                    if (ori == 0)
                        break;
                    guestNext = potentialPoint;
                }
                // cout << "potentialPoint: " << potentialPoint << nln;
            }
        }
        // cout << "guestNext: " << guestNext << nln << nln;
        // guestNext Point now is the surely nextPoint
        if (guestNext == hull[0]) 
            break;

        lastOnHull = guestNext;
        hull.push_back(guestNext);
        remainPoints.erase(guestNext);
    }
    return hull;
}

int main(int argc, char const *argv[])
{   
    cin.tie(0)->sync_with_stdio(0);
    ll n;   cin >> n;
    vector<Point> points(n);
    for (auto& point : points)
        cin >> point;

    vector<Point> hull = convexHull(points);
    cout << hull.size() << nln;
    for (const auto& point : hull) {
        cout << point << nln;
    }

	return 0;
}