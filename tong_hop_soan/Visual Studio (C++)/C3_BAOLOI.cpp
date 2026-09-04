//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//struct Point {
//    int x, y;
//
//    Point(int x = 0, int y = 0) : x(x), y(y) {}
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
//    // Tính diện tích đa giác
//    double area = areaPolygon(hull);
//    cout << "\nArea of the polygon: " << area << endl;
//
//    return 0;
//}
//
//
//
//
//
