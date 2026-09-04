#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Định nghĩa một điểm
struct Point {
   int x, y;
};

// Hàm tính khoảng cách Manhattan giữa hai điểm
int distance(const Point& p1, const Point& p2) {
   return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Hàm tìm cặp điểm gần nhất bằng brute force
pair<int, pair<Point, Point>> bruteForce(const vector<Point>& points, int start, int end) {
   int minDist = INT_MAX;
   pair<Point, Point> closestPair;
   for (int i = start; i < end; ++i) {
       for (int j = i + 1; j < end; ++j) {
           int dist = distance(points[i], points[j]);
           if (dist < minDist) {
               minDist = dist;
               closestPair = { points[i], points[j] };
           }
       }
   }
   return { minDist, closestPair };
}

// Hàm tìm khoảng cách nhỏ nhất trong dải trung tâm (strip)
pair<int, pair<Point, Point>> stripClosest(const vector<Point>& strip, int d) {
   int minDist = d;
   pair<Point, Point> closestPair;

   // Duyệt từng cặp điểm trong strip
   for (size_t i = 0; i < strip.size(); ++i) {
       for (size_t j = i + 1; j < strip.size(); ++j) {
           if (strip[j].y - strip[i].y >= minDist) break; // Nếu quá d, bỏ qua
           int dist = distance(strip[i], strip[j]);
           if (dist < minDist) {
               minDist = dist;
               closestPair = { strip[i], strip[j] };
           }
       }
   }
   return { minDist, closestPair };
}

// Hàm đệ quy chính để tìm cặp điểm gần nhất
pair<int, pair<Point, Point>> closestPairRec(vector<Point>& pointsSortedX, vector<Point>& pointsSortedY) {
   int n = pointsSortedX.size();
   if (n <= 3) {
       return bruteForce(pointsSortedX, 0, n);
   }

   int mid = n / 2;
   Point midPoint = pointsSortedX[mid];

   vector<Point> leftX(pointsSortedX.begin(), pointsSortedX.begin() + mid);
   vector<Point> rightX(pointsSortedX.begin() + mid, pointsSortedX.end());

   vector<Point> leftY, rightY;
   for (const auto& p : pointsSortedY) {
       if (p.x <= midPoint.x) leftY.push_back(p);
       else rightY.push_back(p);
   }

   auto dLeft = closestPairRec(leftX, leftY);
   auto dRight = closestPairRec(rightX, rightY);

   auto dMin = (dLeft.first < dRight.first) ? dLeft : dRight;

   vector<Point> strip;
   for (const auto& p : pointsSortedY) {
       if (abs(p.x - midPoint.x) < dMin.first) {
           strip.push_back(p);
       }
   }

   auto dStrip = stripClosest(strip, dMin.first);
   return (dStrip.first < dMin.first) ? dStrip : dMin;
}

// Hàm chính để tìm cặp điểm gần nhất
pair<int, pair<Point, Point>> closestPair(vector<Point>& points) {
   vector<Point> pointsSortedX = points;
   vector<Point> pointsSortedY = points;

   sort(pointsSortedX.begin(), pointsSortedX.end(), [](const Point& a, const Point& b) {
       return a.x < b.x;
       });

   sort(pointsSortedY.begin(), pointsSortedY.end(), [](const Point& a, const Point& b) {
       return a.y < b.y;
       });

   return closestPairRec(pointsSortedX, pointsSortedY);
}

// Hàm main để chạy thử chương trình
int main() {
   vector<Point> points = { {-1, 2}, {3, -1}, {1, 1}, {4, 5}, {0, 0}, {2, 3}, {-1, -1} };

   auto result = closestPair(points);
   cout << "Khoảng cách nhỏ nhất là " << result.first << " giữa hai điểm ("
       << result.second.first.x << ", " << result.second.first.y << ") và ("
       << result.second.second.x << ", " << result.second.second.y << ")" << endl;

   return 0;
}


IN ra tất cả các điểm

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Định nghĩa một điểm
struct Point {
   int x, y;
};

// Hàm tính khoảng cách Manhattan giữa hai điểm
int distance(const Point& p1, const Point& p2) {
   return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Hàm tìm cặp điểm gần nhất bằng brute force
vector<pair<int, pair<Point, Point>>> bruteForce(const vector<Point>& points, int start, int end) {
   vector<pair<int, pair<Point, Point>>> closestPairs;
   int minDist = INT_MAX;
   for (int i = start; i < end; ++i) {
       for (int j = i + 1; j < end; ++j) {
           int dist = distance(points[i], points[j]);
           if (dist < minDist) {
               minDist = dist;
               closestPairs.clear();
               closestPairs.push_back({ dist, {points[i], points[j]} });
           }
           else if (dist == minDist) {
               closestPairs.push_back({ dist, {points[i], points[j]} });
           }
       }
   }
   return closestPairs;
}

// Hàm tìm khoảng cách nhỏ nhất trong dải trung tâm (strip)
vector<pair<int, pair<Point, Point>>> stripClosest(const vector<Point>& strip, int d) {
   vector<pair<int, pair<Point, Point>>> closestPairs;
   int minDist = d;
   for (size_t i = 0; i < strip.size(); ++i) {
       for (size_t j = i + 1; j < strip.size(); ++j) {
           if (strip[j].y - strip[i].y >= minDist) break; // Nếu quá d, bỏ qua
           int dist = distance(strip[i], strip[j]);
           if (dist < minDist) {
               minDist = dist;
               closestPairs.clear();
               closestPairs.push_back({ dist, {strip[i], strip[j]} });
           }
           else if (dist == minDist) {
               closestPairs.push_back({ dist, {strip[i], strip[j]} });
           }
       }
   }
   return closestPairs;
}

// Hàm đệ quy chính để tìm cặp điểm gần nhất
vector<pair<int, pair<Point, Point>>> closestPairRec(vector<Point>& pointsSortedX, vector<Point>& pointsSortedY) {
   int n = pointsSortedX.size();
   if (n <= 3) {
       return bruteForce(pointsSortedX, 0, n);
   }

   int mid = n / 2;
   Point midPoint = pointsSortedX[mid];

   vector<Point> leftX(pointsSortedX.begin(), pointsSortedX.begin() + mid);
   vector<Point> rightX(pointsSortedX.begin() + mid, pointsSortedX.end());

   vector<Point> leftY, rightY;
   for (const auto& p : pointsSortedY) {
       if (p.x <= midPoint.x) leftY.push_back(p);
       else rightY.push_back(p);
   }

   auto dLeft = closestPairRec(leftX, leftY);
   auto dRight = closestPairRec(rightX, rightY);

   vector<pair<int, pair<Point, Point>>> closestPairs;
   int minDist = INT_MAX;
   for (const auto& pair : dLeft) {
       if (pair.first < minDist) {
           minDist = pair.first;
           closestPairs.clear();
           closestPairs.push_back(pair);
       }
       else if (pair.first == minDist) {
           closestPairs.push_back(pair);
       }
   }
   for (const auto& pair : dRight) {
       if (pair.first < minDist) {
           minDist = pair.first;
           closestPairs.clear();
           closestPairs.push_back(pair);
       }
       else if (pair.first == minDist) {
           closestPairs.push_back(pair);
       }
   }

   vector<Point> strip;
   for (const auto& p : pointsSortedY) {
       if (abs(p.x - midPoint.x) < minDist) {
           strip.push_back(p);
       }
   }

   auto dStrip = stripClosest(strip, minDist);
   for (const auto& pair : dStrip) {
       if (pair.first < minDist) {
           minDist = pair.first;
           closestPairs.clear();
           closestPairs.push_back(pair);
       }
       else if (pair.first == minDist) {
           closestPairs.push_back(pair);
       }
   }

   return closestPairs;
}

// Hàm chính để tìm cặp điểm gần nhất
vector<pair<int, pair<Point, Point>>> closestPair(vector<Point>& points) {
   vector<Point> pointsSortedX = points;
   vector<Point> pointsSortedY = points;

   sort(pointsSortedX.begin(), pointsSortedX.end(), [](const Point& a, const Point& b) {
       return a.x < b.x;
       });

   sort(pointsSortedY.begin(), pointsSortedY.end(), [](const Point& a, const Point& b) {
       return a.y < b.y;
       });

   return closestPairRec(pointsSortedX, pointsSortedY);
}

// Hàm main để chạy thử chương trình
int main() {
   vector<Point> points = { {-1, 2}, {3, -1}, {1, 1}, {4, 5}, {0, 0}, {2, 3}, {-1, -1} };

   auto result = closestPair(points);
   int minDist = result[0].first;

   cout << "Khoảng cách nhỏ nhất là " << minDist << " giữa các cặp điểm:" << endl;
   for (const auto& pair : result) {
       Point p1 = pair.second.first;
       Point p2 = pair.second.second;
       cout << "(" << p1.x << ", " << p1.y << ") và ("
           << p2.x << ", " << p2.y << ")" << endl;
   }

   return 0;
}
