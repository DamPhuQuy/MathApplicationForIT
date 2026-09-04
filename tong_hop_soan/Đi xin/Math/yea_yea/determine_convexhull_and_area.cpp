#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
 
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

// Using Shoelace formula
ll polygonArea(const vector<Point>& polygon) {
    ll s = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        Point P1 = polygon[i], P2 = polygon[(i + 1) % polygon.size()];
        s += (conj(P1) * P2).imag();
    }
    return abs(s);
}

 
// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     ll n;
//     // cout << "Enter the number of points: ";
//     cin >> n;
 
//     vector<Point> points(n);
//     // cout << "Enter the coordinates of each point (x y):" << nln;
//     for (auto &point : points) {
//         ll X, Y;
//         cin >> X >> Y;
//         point = {X, Y};
//     }
 
//     vector<Point> convexHull = computeConvexHull(points);
 
//     // cout << "Convex Hull:" << nln;
//     cout << convexHull.size() << nln;
//     for (const auto& point : convexHull)
//         cout << point.real() << ' ' << point.imag() << nln;
    
//     cout << "Area of the convex hull: " << polygonArea(convexHull) << '\n';

//     return 0;
// }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // Initialize points with the provided coordinates
    vector<Point> points = {
        {-4, 2}, {-3, -2}, {-1, 4}, {-1, -4}, {0, 0},
        {1, -2}, {1, -4}, {-2, 3}, {3, 4}, {5, 2}
    };

    vector<Point> convexHull = computeConvexHull(points);

    cout << "Convex Hull:" << nln;
    for (const auto& point : convexHull)
        cout << point.real() << ' ' << point.imag() << nln;

    cout << "Area of the convex hull: " << polygonArea(convexHull) << '\n';
    
    
    return 0;
}