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
    int n = A.size();
    int k = 0;

    if (n <= 2) return A;

    vector<Point> ans(2 * n);

    sort(A.begin(), A.end());

    // Xay nua duoi
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && crossProduct(ans[k - 2], ans[k - 1], A[i]) >= 0) {
            k--;
        }
        ans[k++] = A[i];
    }

    // Xay nua tren
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && crossProduct(ans[k - 2], ans[k - 1], A[i]) >= 0) {
            k--;
        }
        ans[k++] = A[i];
    }

    ans.resize(k - 1);
    return ans;
}

// Tinh khoang cach giua 2 diem
double distancePoint(Point A, Point B) {
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

// Tinh chu vi da giac bao loi
double perimeter(const vector<Point>& hull) {
    int n = hull.size();

    if (n < 2) return 0.0;

    double p = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        p += distancePoint(hull[i], hull[j]);
    }

    return p;
}

// Tinh dien tich da giac bao loi bang cong thuc Shoelace
double area(const vector<Point>& hull) {
    int n = hull.size();

    if (n < 3) return 0.0;

    long double s = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += (long double)hull[i].x * hull[j].y - (long double)hull[j].x * hull[i].y;
    }

    return fabs(s) / 2.0;
}

int main() {
    int n;

    cout << "Nhap so diem n = ";
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap x" << i + 1 << " = ";
        cin >> points[i].x;

        cout << "Nhap y" << i + 1 << " = ";
        cin >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << "\nCac dinh cua bao loi la:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    cout << fixed << setprecision(4);

    cout << "\nChu vi cua da giac bao loi la: " << perimeter(hull) << endl;
    cout << "Dien tich cua da giac bao loi la: " << area(hull) << endl;

    return 0;
}