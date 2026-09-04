// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

// This code is checked on CSES

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
#define x real()
#define y imag()

typedef long long ll;
typedef complex<ll> Point;
typedef complex<ll> Vector;

ll crossProduct(const Vector& A, const Vector& B) {
    // Explain this function
    // Assume: A = {x1, y1}  |  B = {x2, y2}
    // (conj(a)*b).Y
    // is the imagine part of conj(a)*b
    // We have: conj(a)*b
    // = conj(x1 + y1.i)*(x2 + y2.i)
    // = (x1 - y1.i)*(x2 + y2.i)
    // = x1.x2 + x1.y2.i - x2.y1.i - y1.y2.i^2 (i^2 = 1)
    // = (x1.x2 - y1.y2) + (x1.y2 - x2.y1).i
    // So imagine part is (x1.y2 - x2.y1)
    // And it is also the cross product of A and B
    return (conj(A)*B).y;
}

ll checkTheSide(const Point& A, const Point& B, const Point& C) {
    Point BA = A - B;
    Point BC = C - B;
    ll cp = (conj(BA)*BC).y;
    return (cp > 0) - (cp < 0);
}

vector<Point> halfHull(const vector<Point>& points) {
    vector<Point> ans = {points[0]};
    for (ll i = 1; i < points.size(); ++i) {
        auto nextPoint = points[i];
        while (ans.size() > 1) {
            auto lastPoint = ans.back();
            ans.pop_back();
            auto beforeLastPoint = ans.back();
            if (checkTheSide(beforeLastPoint, lastPoint, nextPoint) != 1) {
                ans.push_back(lastPoint);
                break;
            }
        }
        ans.push_back(nextPoint);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // Input
    cin.tie(0)->sync_with_stdio(0);
    ll n;   cin >> n;
    vector<Point> points(n);
    for (auto& point : points) {
        ll X, Y;    cin >> X >> Y;
        point = {X, Y};
    }

    // Find the upper part of convex hull
    sort(points.begin(), points.end(), [] (const Point& A, const Point& B) {
        return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
    });

    vector<Point> upperPart = halfHull(points);

    // Find the lower part of convex hull
    sort(points.begin(), points.end(), [] (const Point& A, const Point& B) {
        return (A.x != B.x) ? (A.x > B.x) : (A.y > B.y);
    });

    vector<Point> lowerPart = halfHull(points);

    // Combine two part
    for (ll i = 1; i < lowerPart.size(); ++i) {
        if (lowerPart[i] == upperPart[0]) break;
        upperPart.push_back(lowerPart[i]);
    }

    cout << upperPart.size() << nln;
    for (auto point : upperPart)
        cout << point.x << ' ' << point.y << nln;

    return 0;
}