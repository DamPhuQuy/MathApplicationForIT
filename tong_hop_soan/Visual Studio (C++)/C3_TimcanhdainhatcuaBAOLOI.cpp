//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <unordered_set>
//
//using namespace std;
//
//struct Point {
//    int x, y;
//
//    Point(int x = 0, int y = 0) : x(x), y(y) {}
//
//    bool operator==(const Point& other) const {
//        return x == other.x && y == other.y;
//    }
//};
//
//struct PointHash {
//    size_t operator()(const Point& p) const {
//        return hash<int>()(p.x) ^ hash<int>()(p.y);
//    }
//};
//
//// Hàm so sánh để sắp xếp điểm theo hoành độ tăng dần
//bool comparePoints(const Point& a, const Point& b) {
//    return a.x < b.x || (a.x == b.x && a.y < b.y);
//}
//
//// Kiểm tra nếu ba điểm tạo thành ngược chiều kim đồng hồ
//bool ccw(const Point& A, const Point& B, const Point& C) {
//    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y) > 0;
//}
//
//// Tìm bao lồi của tập điểm
//vector<Point> convexHull(vector<Point>& points) {
//    sort(points.begin(), points.end(), comparePoints);
//
//    // Xây dựng phần trên của bao lồi
//    vector<Point> upper;
//    for (const auto& p : points) {
//        while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper.back(), p)) {
//            upper.pop_back();
//        }
//        upper.push_back(p);
//    }
//
//    // Xây dựng phần dưới của bao lồi
//    vector<Point> lower;
//    for (auto it = points.rbegin(); it != points.rend(); ++it) {
//        while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower.back(), *it)) {
//            lower.pop_back();
//        }
//        lower.push_back(*it);
//    }
//
//    // Loại bỏ điểm cuối trùng lặp
//    upper.pop_back();
//    lower.pop_back();
//
//    // Kết hợp phần trên và phần dưới
//    upper.insert(upper.end(), lower.begin(), lower.end());
//    return upper;
//}
//
//// Tính diện tích đa giác sử dụng định lý Green
//double areaPolygon(const vector<Point>& points) {
//    double area = 0;
//    for (size_t i = 0; i < points.size(); ++i) {
//        size_t j = (i + 1) % points.size();
//        area += points[i].x * points[j].y;
//        area -= points[i].y * points[j].x;
//    }
//    return fabs(area) / 2.0;
//}
//
//// Kiểm tra điểm có nằm trong bao lồi không
//bool isPointOnHull(const Point& p, const unordered_set<Point, PointHash>& hullSet) {
//    return hullSet.find(p) != hullSet.end();
//}
//
//// Tính khoảng cách giữa hai điểm
//double distance(const Point& a, const Point& b) {
//    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
//}
//
//// Tìm cạnh ngắn nhất của bao lồi
//void findShortestEdges(const vector<Point>& hull) {
//    double minDistance = numeric_limits<double>::max();
//    vector<pair<Point, Point>> shortestEdges;
//
//    for (size_t i = 0; i < hull.size(); ++i) {
//        size_t j = (i + 1) % hull.size();
//        double dist = distance(hull[i], hull[j]);
//        if (dist < minDistance) {
//            minDistance = dist;
//            shortestEdges.clear();
//            shortestEdges.emplace_back(hull[i], hull[j]);
//        }
//        else if (dist == minDistance) {
//            shortestEdges.emplace_back(hull[i], hull[j]);
//        }
//    }
//
//    cout << "\nShortest edges (length = " << minDistance << "):\n";
//    for (const auto& edge : shortestEdges) {
//        cout << "(" << edge.first.x << ", " << edge.first.y << ") - (" << edge.second.x << ", " << edge.second.y << ")\n";
//    }
//}
//
//// Tìm cạnh dài nhất của bao lồi
//void findLongestEdges(const vector<Point>& hull) {
//    double maxDistance = numeric_limits<double>::lowest();
//    vector<pair<Point, Point>> longestEdges;
//
//    for (size_t i = 0; i < hull.size(); ++i) {
//        size_t j = (i + 1) % hull.size();
//        double dist = distance(hull[i], hull[j]);
//        if (dist > maxDistance) {
//            maxDistance = dist;
//            longestEdges.clear();
//            longestEdges.emplace_back(hull[i], hull[j]);
//        }
//        else if (dist == maxDistance) {
//            longestEdges.emplace_back(hull[i], hull[j]);
//        }
//    }
//
//    cout << "\nLongest edges (length = " << maxDistance << "):\n";
//    for (const auto& edge : longestEdges) {
//        cout << "(" << edge.first.x << ", " << edge.first.y << ") - (" << edge.second.x << ", " << edge.second.y << ")\n";
//    }
//}
//
//// In ra danh sách điểm
//void printPoints(const vector<Point>& points) {
//    for (const auto& p : points) {
//        cout << "(" << p.x << ", " << p.y << ")\n";
//    }
//}
//
//int main() {
//    // Tập các điểm: (-4, 2), (-3, -2), (-1, 4), (-1, -4), (0, 0), (1, -2), (1, -4), (2, -3), (3, -4), (5, -2)
//    vector<Point> points = {
//        Point(-4, 2), Point(-3, -2), Point(-1, 4), Point(-1, -4), Point(0, 0),
//        Point(1, -2), Point(1, -4), Point(2, -3), Point(3, -4), Point(5, -2)
//    };
//
//    // Sắp xếp và in ra điểm
//    sort(points.begin(), points.end(), comparePoints);
//    cout << "Sorted Points:\n";
//    printPoints(points);
//
//    // Tìm bao lồi
//    cout << "\nConvex Hull:\n";
//    vector<Point> hull = convexHull(points);
//    printPoints(hull);
//
//    // Chuyển các điểm trên bao lồi vào tập hợp để kiểm tra nhanh
//    unordered_set<Point, PointHash> hullSet(hull.begin(), hull.end());
//    int count = 0;
//    // Tìm các điểm nằm bên trong bao lồi
//    cout << "\nPoints inside the Convex Hull:\n";
//    for (const auto& p : points) {
//        if (!isPointOnHull(p, hullSet)) {
//            count = count + 1;
//            cout << "(" << p.x << ", " << p.y << ")\n";
//        }
//    }
//    cout << "Count:" << count << endl;
//
//    // Tìm cạnh ngắn nhất của bao lồi
//    findShortestEdges(hull);
//
//    // Tìm cạnh dài nhất của bao lồi
//    findLongestEdges(hull);
//
//    // Tính diện tích đa giác
//    double area = areaPolygon(hull);
//    cout << "\nArea of the polygon: " << area << endl;
//
//    return 0;
//}
