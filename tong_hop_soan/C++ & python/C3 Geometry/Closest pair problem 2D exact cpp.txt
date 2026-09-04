#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double dis(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    // return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double brute_force(const vector<pair<int, int>>& points, pair<int, int>& p1, pair<int, int>& p2) {
    double min_dis = numeric_limits<double>::infinity();
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = dis(points[i], points[j]);
            if (distance < min_dis) {
                min_dis = distance;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    return min_dis;
}

double strip_closest(vector<pair<int, int>>& strip, double d, pair<int, int>& p1, pair<int, int>& p2) {
    double min_d = d;
    sort(strip.begin(), strip.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });
    int size = strip.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(strip[i].second - strip[j].second) >= min_d) {
                break;
            }
            double distance = dis(strip[i], strip[j]);
            if (distance < min_d) {
                min_d = distance;
                p1 = strip[i];
                p2 = strip[j];
            }
        }
    }
    return min_d;
}

double closest(const vector<pair<int, int>>& points, int left, int right, pair<int, int>& p1, pair<int, int>& p2) {
    if (right - left <= 3) {
        vector<pair<int, int>> subset(points.begin() + left, points.begin() + right + 1);
        return brute_force(subset, p1, p2);
    }
    int mid = (left + right) / 2;
    pair<int, int> mid_point = points[mid];

    pair<int, int> p1_left, p2_left, p1_right, p2_right;
    double d_left = closest(points, left, mid, p1_left, p2_left);
    double d_right = closest(points, mid + 1, right, p1_right, p2_right);

    double d = min(d_left, d_right);
    if (d == d_left) {
        p1 = p1_left;
        p2 = p2_left;
    } else {
        p1 = p1_right;
        p2 = p2_right;
    }

    vector<pair<int, int>> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].first - mid_point.first) < d) {
            strip.push_back(points[i]);
        }
    }
    return min(d, strip_closest(strip, d, p1, p2));
}

double closest_pair(vector<pair<int, int>>& points, pair<int, int>& p1, pair<int, int>& p2) {
    sort(points.begin(), points.end());
    return closest(points, 0, points.size() - 1, p1, p2);
}

int main() {
    vector<pair<int, int>> points = {{12, 41}, {31, 21}, {52, 17}, {24, 19}, {8, 19},
                                      {24, 29}, {14, 27}, {41, 52}, {16, 27}, {28, 40}};
    pair<int, int> p1, p2;
    double min_dis = closest_pair(points, p1, p2);
    cout << "Khoảng cách nhỏ nhất giữa hai điểm trong tập hợp điểm trên là: " << min_dis << endl;
    cout << "Cặp điểm có khoảng cách nhỏ nhất: (" << p1.first << ", " << p1.second << ") và ("
         << p2.first << ", " << p2.second << ")" << endl;
    return 0;
}
