#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

long long crossProduct(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point>& A) {
    int n = A.size(), k = 0;
    if (n <= 2) return A; 

    vector<Point> ans(2 * n);
    sort(A.begin(), A.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && crossProduct(ans[k - 2], ans[k - 1], A[i]) >= 0) k--;
        ans[k++] = A[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && crossProduct(ans[k - 2], ans[k - 1], A[i]) >= 0) k--;
        ans[k++] = A[i];
    }

    ans.resize(k - 1);
    return ans;
}
int main() {
    int n;
    cout << "Nhap so diem n = ";
    if (!(cin >> n)) return 0;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap x" << i + 1 << " = ";
        cin >> points[i].x;
        cout << "Nhap y" << i + 1 << " = ";
        cin >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    cout << "Cac dinh cua Bao loi (Cung chieu kim dong ho):\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}
