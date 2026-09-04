#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <climits>
#include <iomanip>
 
using namespace std;
 
#define nln '\n'
 
typedef long long ll;
typedef complex<ll> Point;
typedef complex<ll> Vector;
 
ll crossProduct(const Point& A, const Point& B, const Point& C) {
    Vector AB = B - A, BC = C - B;
    ll cp = AB.real() * BC.imag() - AB.imag() * BC.real();
    return (cp > 0) - (cp < 0);
}
 
vector<Point> halfHull(const vector<Point>& points, bool ascending) {
    vector<Point> hull;
    for (const auto& nextPoint : points) {
        while (hull.size() >= 2) {
            auto lastPoint = hull.back();
            auto beforeLastPoint = hull[hull.size()-2];
            if (crossProduct(beforeLastPoint, lastPoint, nextPoint) != (ascending ? 1 : -1)) {
                break;
            }
            hull.pop_back();
        }
        hull.push_back(nextPoint);
    }
    return hull;
}

// Using Graham's scan algorithm
vector<Point> computeConvexHull(const vector<Point>& points) {
    vector<Point> sortedPoints = points;
    sort(sortedPoints.begin(), sortedPoints.end(), [](const Point& A, const Point& B) {
        return (A.real() != B.real()) ? (A.real() < B.real()) : (A.imag() < B.imag());
    });
 
    vector<Point> upper = halfHull(sortedPoints, true);
    vector<Point> lower = halfHull(sortedPoints, false);
 
    vector<Point> convexHull = upper;
    for (int i = lower.size() - 2; i > 0; --i) {
        convexHull.push_back(lower[i]);
    }
 
    return convexHull;
}

int sqr(int x) {
    return x*x;
}

int euclidDistance(const Point& A, const Point& B) {
    return sqr(A.real() - B.real()) + sqr(A.imag() - B.imag());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // Initialize points with the provided coordinates
    // Cho mười điểm trong không gian Oxy như sau: 
    // (7, 2); (6, 3); (3, 9); (10, 7); (2, 4); (15,4); (12,5); (8,6); (10,4); (9,11)
    vector<Point> points = {
        {7, 2}, {6, 3}, {3, 9}, {10, 7}, {2, 4},
        {15, 4}, {12, 5}, {8,6}, {10, 4}, {9, 11}
    };

    vector<Point> convexHull = computeConvexHull(points);

    cout << "Convex Hull include " << convexHull.size() << " points :" << nln;

    Point S, F, prev; int d = INT_MAX;
    bool first = true;

    for (const auto& point : convexHull) {
        cout << point.real() << ' ' << point.imag() << nln;
        if (!first) {
            if (euclidDistance(prev, point) < d) {
                d = euclidDistance(prev, point);
                S = prev, F = point;
            }
        }
        prev = point;
        first = false;
    }

    cout << "Canh nho nhat gom 2 diem: " << S << " va " << F << '\n';
    cout << "Do dai canh nho nhat: " << setprecision(5) << fixed << sqrt(d) << endl;

    
    return 0;
}