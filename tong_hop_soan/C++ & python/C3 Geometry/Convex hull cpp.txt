#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int cross(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int ccw(const Point& A, const Point& B, const Point& C) {
    int S = cross(A, B, C);
    if (S < 0) return -1;
    if (S == 0) return 0;
    return 1;
}

vector<Point> convex_hull(vector<Point>& points) {
    sort(points.begin(), points.end(), [](const Point& A, const Point& B) {
        return (A.x == B.x) ? A.y < B.y : A.x < B.x;
    });

    vector<Point> lower;
    for (const auto& p : points) {
        while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    vector<Point> upper;
    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        const auto& p = *it;
        while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], p) <= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

double calc_area(const vector<Point>& hull) {
    double area = 0;
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += (hull[i].x * hull[j].y) - (hull[j].x * hull[i].y);
    }
    return abs(area) / 2.0;
}

double find_min_edge(const vector<Point>& hull) {
    double min_edge = numeric_limits<double>::max();
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        double dist = sqrt(pow(hull[j].x - hull[i].x, 2) + pow(hull[j].y - hull[i].y, 2));
        min_edge = min(min_edge, dist);
    }
    return min_edge;
}

int main() {
    vector<Point> points = {
        Point(1, 2), Point(2, 5), Point(3, 4), Point(4, 3),
        Point(5, 4), Point(6, 1), Point(7, 5)
    };

    vector<Point> hull = convex_hull(points);

    cout << "Convex Hull points: " << endl;
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    double area = calc_area(hull);
    cout << "Area of the convex hull: " << area << endl;

    double min_edge = find_min_edge(hull);
    cout << "Smallest edge length in the convex hull: " << min_edge << endl;

    return 0;
}
