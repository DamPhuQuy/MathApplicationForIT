#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

bool comparePoints(const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

long long cross_product(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> get_convex_hull(vector<Point>& points) {
    int n = points.size(), k = 0;
    if (n <= 2) return points;
    vector<Point> hull(2 * n);

    sort(points.begin(), points.end(), comparePoints);

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    hull.resize(k - 1);
    return hull;
}

double get_polygon_area(const vector<Point>& hull) {
    double area = 0;
    int n = hull.size();
    for (int i = 0; i < n; i++) {
        area += (double)hull[i].x * hull[(i + 1) % n].y;
        area -= (double)hull[i].y * hull[(i + 1) % n].x;
    }
    return abs(area) / 2.0;
}

void print_output(const vector<Point>& pts) {
    for (const auto& p : pts) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
}

int main() {
    vector<Point> points = {
        {-4, 2}, {-3, -2}, {-1, 4}, {-1, -4}, {0, 0},
        {1, -2}, {1, -4}, {2, -3}, {3, -4}, {5, -2}
    };

    sort(points.begin(), points.end(), comparePoints);
    cout << "Sorted Points:" << endl;
    print_output(points);

    vector<Point> hull = get_convex_hull(points);
    cout << "\nConvex Hull:" << endl;
    print_output(hull);

    cout << "\nArea of the polygon: " << get_polygon_area(hull) << endl;

    return 0;
}