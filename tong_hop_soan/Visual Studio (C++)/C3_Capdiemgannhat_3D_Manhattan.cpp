//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <climits>
//#include <tuple> // Sử dụng cho việc trả về nhiều giá trị
//
//using namespace std;
//
//// Định nghĩa một điểm trong không gian 3 chiều
//struct Point {
//    int x, y, z;
//};
//
//// Hàm tính khoảng cách Manhattan giữa hai điểm
//int distance(const Point& p1, const Point& p2) {
//    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
//}
//
//// Hàm tìm cặp điểm gần nhất bằng brute force
//tuple<int, Point, Point> bruteForce(const vector<Point>& points, int start, int end) {
//    int minDist = INT_MAX;
//    Point p1, p2;
//    for (int i = start; i < end; ++i) {
//        for (int j = i + 1; j < end; ++j) {
//            int dist = distance(points[i], points[j]);
//            if (dist < minDist) {
//                minDist = dist;
//                p1 = points[i];
//                p2 = points[j];
//            }
//        }
//    }
//    return { minDist, p1, p2 };
//}
//
//// Hàm tìm khoảng cách nhỏ nhất trong dải trung tâm (strip)
//tuple<int, Point, Point> stripClosest(const vector<Point>& strip, int d) {
//    int minDist = d;
//    Point p1, p2;
//
//    // Duyệt từng cặp điểm trong strip
//    for (size_t i = 0; i < strip.size(); ++i) {
//        for (size_t j = i + 1; j < strip.size() && j < i + 7; ++j) {
//            int dist = distance(strip[i], strip[j]);
//            if (dist < minDist) {
//                minDist = dist;
//                p1 = strip[i];
//                p2 = strip[j];
//            }
//        }
//    }
//    return { minDist, p1, p2 };
//}
//
//// Hàm đệ quy chính để tìm cặp điểm gần nhất
//tuple<int, Point, Point> closestPairRec(vector<Point>& pointsSortedX, vector<Point>& pointsSortedY) {
//    int n = pointsSortedX.size();
//    if (n <= 3) {
//        return bruteForce(pointsSortedX, 0, n);
//    }
//
//    int mid = n / 2;
//    Point midPoint = pointsSortedX[mid];
//
//    vector<Point> leftX(pointsSortedX.begin(), pointsSortedX.begin() + mid);
//    vector<Point> rightX(pointsSortedX.begin() + mid, pointsSortedX.end());
//
//    vector<Point> leftY, rightY;
//    for (const auto& p : pointsSortedY) {
//        if (p.x <= midPoint.x)
//            leftY.push_back(p);
//        else
//            rightY.push_back(p);
//    }
//
//    auto dLeft = closestPairRec(leftX, leftY);
//    auto dRight = closestPairRec(rightX, rightY);
//
//    auto dMin = get<0>(dLeft) < get<0>(dRight) ? dLeft : dRight;
//
//    vector<Point> strip;
//    for (const auto& p : pointsSortedY) {
//        if (abs(p.x - midPoint.x) < get<0>(dMin)) {
//            strip.push_back(p);
//        }
//    }
//
//    auto dStrip = stripClosest(strip, get<0>(dMin));
//    return get<0>(dStrip) < get<0>(dMin) ? dStrip : dMin;
//}
//
//// Hàm chính để tìm cặp điểm gần nhất
//tuple<int, Point, Point> closestPair(vector<Point>& points) {
//    vector<Point> pointsSortedX = points;
//    vector<Point> pointsSortedY = points;
//
//    sort(pointsSortedX.begin(), pointsSortedX.end(), [](const Point& a, const Point& b) {
//        return a.x < b.x;
//        });
//
//    sort(pointsSortedY.begin(), pointsSortedY.end(), [](const Point& a, const Point& b) {
//        return a.y < b.y;
//        });
//
//    return closestPairRec(pointsSortedX, pointsSortedY);
//}
//
//// Hàm main để chạy thử chương trình
//int main() {
//    vector<Point> points = { {-1, 2, 3}, {3, -1, 5}, {1, 1, 1}, {4, 5, 2}, {0, 0, 0}, {2, 3, 4}, {-1, -1, -1} };
//
//    auto result = closestPair(points);
//    int minDist = get<0>(result);
//    Point p1 = get<1>(result);
//    Point p2 = get<2>(result);
//
//    cout << "Khoảng cách nhỏ nhất là " << minDist << " giữa hai điểm ("
//        << p1.x << ", " << p1.y << ", " << p1.z << ") và ("
//        << p2.x << ", " << p2.y << ", " << p2.z << ")" << endl;
//
//    return 0;
//}

//IN RA TẤT CẢ CÁC CẶP ĐIỂM
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <climits>
//#include <tuple>
//#include <set>
//
//using namespace std;
//
//struct Point {
//    int x, y, z;
//
//    // Định nghĩa toán tử < cho Point
//    bool operator<(const Point& other) const {
//        if (x != other.x) return x < other.x;
//        if (y != other.y) return y < other.y;
//        return z < other.z;
//    }
//};
//
//int distance(const Point& p1, const Point& p2) {
//    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
//}
//
//vector<tuple<int, Point, Point>> bruteForce(const vector<Point>& points, int start, int end) {
//    vector<tuple<int, Point, Point>> closestPairs;
//    int minDist = INT_MAX;
//    for (int i = start; i < end; ++i) {
//        for (int j = i + 1; j < end; ++j) {
//            int dist = distance(points[i], points[j]);
//            if (dist < minDist) {
//                minDist = dist;
//                closestPairs.clear();
//                closestPairs.push_back({ dist, points[i], points[j] });
//            }
//            else if (dist == minDist) {
//                closestPairs.push_back({ dist, points[i], points[j] });
//            }
//        }
//    }
//    return closestPairs;
//}
//
//vector<tuple<int, Point, Point>> stripClosest(const vector<Point>& strip, int d) {
//    vector<tuple<int, Point, Point>> closestPairs;
//    int minDist = d;
//    for (size_t i = 0; i < strip.size(); ++i) {
//        for (size_t j = i + 1; j < strip.size() && j < i + 7; ++j) {
//            int dist = distance(strip[i], strip[j]);
//            if (dist < minDist) {
//                minDist = dist;
//                closestPairs.clear();
//                closestPairs.push_back({ dist, strip[i], strip[j] });
//            }
//            else if (dist == minDist) {
//                closestPairs.push_back({ dist, strip[i], strip[j] });
//            }
//        }
//    }
//    return closestPairs;
//}
//
//vector<tuple<int, Point, Point>> closestPairRec(vector<Point>& pointsSortedX, vector<Point>& pointsSortedY) {
//    int n = pointsSortedX.size();
//    if (n <= 3) {
//        return bruteForce(pointsSortedX, 0, n);
//    }
//
//    int mid = n / 2;
//    Point midPoint = pointsSortedX[mid];
//
//    vector<Point> leftX(pointsSortedX.begin(), pointsSortedX.begin() + mid);
//    vector<Point> rightX(pointsSortedX.begin() + mid, pointsSortedX.end());
//
//    vector<Point> leftY, rightY;
//    for (const auto& p : pointsSortedY) {
//        if (p.x <= midPoint.x)
//            leftY.push_back(p);
//        else
//            rightY.push_back(p);
//    }
//
//    auto dLeft = closestPairRec(leftX, leftY);
//    auto dRight = closestPairRec(rightX, rightY);
//
//    vector<tuple<int, Point, Point>> closestPairs;
//    int minDist = INT_MAX;
//    for (const auto& pair : dLeft) {
//        if (get<0>(pair) < minDist) {
//            minDist = get<0>(pair);
//            closestPairs.clear();
//            closestPairs.push_back(pair);
//        }
//        else if (get<0>(pair) == minDist) {
//            closestPairs.push_back(pair);
//        }
//    }
//    for (const auto& pair : dRight) {
//        if (get<0>(pair) < minDist) {
//            minDist = get<0>(pair);
//            closestPairs.clear();
//            closestPairs.push_back(pair);
//        }
//        else if (get<0>(pair) == minDist) {
//            closestPairs.push_back(pair);
//        }
//    }
//
//    vector<Point> strip;
//    for (const auto& p : pointsSortedY) {
//        if (abs(p.x - midPoint.x) < minDist) {
//            strip.push_back(p);
//        }
//    }
//
//    auto dStrip = stripClosest(strip, minDist);
//    for (const auto& pair : dStrip) {
//        if (get<0>(pair) < minDist) {
//            minDist = get<0>(pair);
//            closestPairs.clear();
//            closestPairs.push_back(pair);
//        }
//        else if (get<0>(pair) == minDist) {
//            closestPairs.push_back(pair);
//        }
//    }
//
//    return closestPairs;
//}
//
//vector<tuple<int, Point, Point>> closestPair(vector<Point>& points) {
//    vector<Point> pointsSortedX = points;
//    vector<Point> pointsSortedY = points;
//
//    sort(pointsSortedX.begin(), pointsSortedX.end(), [](const Point& a, const Point& b) {
//        return a.x < b.x;
//        });
//
//    sort(pointsSortedY.begin(), pointsSortedY.end(), [](const Point& a, const Point& b) {
//        return a.y < b.y;
//        });
//
//    return closestPairRec(pointsSortedX, pointsSortedY);
//}
//
//vector<tuple<int, Point, Point>> removeDuplicates(const vector<tuple<int, Point, Point>>& pairs) {
//    set<pair<Point, Point>> uniquePairs;
//    vector<tuple<int, Point, Point>> result;
//
//    for (const auto& pair : pairs) {
//        Point p1 = get<1>(pair);
//        Point p2 = get<2>(pair);
//
//        if (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y) || (p1.x == p2.x && p1.y == p2.y && p1.z > p2.z)) {
//            swap(p1, p2);
//        }
//
//        if (uniquePairs.insert({ p1, p2 }).second) {
//            result.push_back(pair);
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    vector<Point> points = { {-1, 2, 3}, {3, -1, 5}, {1, 1, 1}, {4, 5, 2}, {0, 0, 0}, {2, 3, 4}, {-1, -1, -1} };
//
//    auto result = closestPair(points);
//    result = removeDuplicates(result);
//
//    int minDist = get<0>(result[0]);
//
//    cout << "Khoảng cách nhỏ nhất là " << minDist << " giữa các cặp điểm:" << endl;
//    for (const auto& pair : result) {
//        Point p1 = get<1>(pair);
//        Point p2 = get<2>(pair);
//        cout << "(" << p1.x << ", " << p1.y << ", " << p1.z << ") và ("
//            << p2.x << ", " << p2.y << ", " << p2.z << ")" << endl;
//    }
//
//    return 0;
//}



