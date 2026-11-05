#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};

long long crossProduct(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> getConvexHull(vector<Point> A) {
    int n = A.size();
    int k = 0;

    if (n <= 2) return A;

    sort(A.begin(), A.end());

    vector<Point> hull(2 * n);

    // Xây nửa dưới của bao lồi
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && crossProduct(hull[k - 2], hull[k - 1], A[i]) <= 0) {
            k--;
        }
        hull[k++] = A[i];
    }

    // Xây nửa trên của bao lồi
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && crossProduct(hull[k - 2], hull[k - 1], A[i]) <= 0) {
            k--;
        }
        hull[k++] = A[i];
    }

    hull.resize(k - 1);
    return hull;
}

int main() {
    vector<Point> points = {
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {9, 1},
        {5, 2},
        {6, 3},
        {7, 4},
        {3, 11},
        {1, 9},
        {2, 11},
        {3, 8},
        {5, 12},
        {10, 3},
        {9, 6},
    };

    vector<Point> hull = getConvexHull(points);

    vector<Point> insidePoints;

    for (const auto& p : points) {
        bool isHullPoint = false;

        for (const auto& h : hull) {
            if (p == h) {
                isHullPoint = true;
                break;
            }
        }

        if (!isHullPoint) {
            insidePoints.push_back(p);
        }
    }

    cout << "Cac diem thuoc bao loi la:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    cout << "\nSo luong diem KHONG thuoc bao loi la: " << insidePoints.size() << "\n";
    cout << "Cac diem khong thuoc bao loi nam ben trong:\n";

    for (const auto& p : insidePoints) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}