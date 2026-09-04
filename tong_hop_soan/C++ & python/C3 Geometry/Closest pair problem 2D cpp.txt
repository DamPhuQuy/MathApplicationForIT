#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double dis(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    // return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double brute_force(const vector<pair<int, int>>& points) {
    double min_dis = numeric_limits<double>::infinity();
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            min_dis = min(min_dis, dis(points[i], points[j]));
        }
    }
    return min_dis;
}

double strip_closest(vector<pair<int, int>>& strip, double d) {
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
            min_d = min(min_d, dis(strip[i], strip[j]));
        }
    }
    return min_d;
}

double closest(const vector<pair<int, int>>& points, int left, int right) {
    if (right - left <= 3) {
        vector<pair<int, int>> subset(points.begin() + left, points.begin() + right + 1);
        return brute_force(subset);
    }
    int mid = (left + right) / 2;
    pair<int, int> mid_point = points[mid];

    double d_left = closest(points, left, mid);
    double d_right = closest(points, mid + 1, right);

    double d = min(d_left, d_right);
    vector<pair<int, int>> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].first - mid_point.first) < d) {
            strip.push_back(points[i]);
        }
    }
    return min(d, strip_closest(strip, d));
}

double closest_pair(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());
    return closest(points, 0, points.size() - 1);
}

int main() {
    vector<pair<int, int>> points = {{12, 41}, {31, 21}, {52, 17}, {24, 19}, {8, 19},
                                      {24, 29}, {14, 27}, {41, 52}, {16, 27}, {28, 40}};
    double min_dis = closest_pair(points);
    cout << "Khoảng cách nhỏ nhất giữa hai điểm trong tập hợp điểm trên là: " << min_dis << endl;
    return 0;
}
