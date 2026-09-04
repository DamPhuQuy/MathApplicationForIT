// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;

ll sweepLine_x = 0;

struct Point {
    ll x, y, idxSegment;
    bool operator<(const Point &other) const {
        return x == other.x ? y > other.y : x < other.x;
    }

    ll operator*(const Point& other) const {
        ll crossProduct = x*other.y - y*other.x;
        return (crossProduct > 0) - (crossProduct < 0);
    }

    Point operator-(const Point& other) const {
        Point tmp = {x - other.x, y - other.y};
        return tmp;
    }
};

struct Segment {
    ll a, b, x, y, idx;

    double Y_coordinate() const {
        if (a == x) { return y; }
        return b + (y - b) * (sweepLine_x - a) / static_cast<double>(x - a);
    }

    bool operator<(const Segment& other) const {
        if (idx == other.idx)
            return false;
        long double y = Y_coordinate(), other_y = other.Y_coordinate();
        return (y != other_y) ? (y < other_y) : (idx < other.idx);
    }

    friend bool intersect(const Segment& a, const Segment& b) {
        Point p1 = {a.a, a.b}, q1 = {a.x, a.y};
        Point p2 = {b.a, b.b}, q2 = {b.x, b.y};

        return ((q2 - p1) * (q1 - p1)) * ((q1 - p1) * (p2 - p1)) >= 0
               && ((q1 - p2) * (q2 - p2)) * ((q2 - p2) * (p1 - p2)) >= 0;
    }
};

int main(int argc, char const *argv[])
{

    int n;  cin >> n;
    set<Point> events;
    vector<Segment> segments;
    for (int i = 0; i < n; ++i) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        segments.push_back({a, b, x, y, i});
        events.insert({a, b, i});
        events.insert({x, y, i});
    }

    set<Segment> activeSegments;

    ll firstSegment, secondSegment;

    for (const auto& event : events) {
        ll currentSegment = event.idxSegment;
        sweepLine_x = event.x;

        auto itCurrentSegment = activeSegments.find(segments[currentSegment]);

        if (itCurrentSegment != activeSegments.end()) {
            auto after = next(itCurrentSegment), before = itCurrentSegment;
            if (before != activeSegments.begin() && after != activeSegments.end()) {
                before--;
                if (intersect(*before, *after)) {
                    firstSegment = before->idx;
                    secondSegment = after->idx;
                    break;
                }
            }
            activeSegments.erase(itCurrentSegment);
        } else {
            activeSegments.insert(segments[currentSegment]);
            auto itInsertedSegment = activeSegments.find(segments[currentSegment]);

            auto itAbove = next(itInsertedSegment);
            if (itAbove != activeSegments.end() && intersect(*itAbove, *itInsertedSegment)) {
                firstSegment = itAbove->idx;
                secondSegment = itInsertedSegment->idx;
                break;
            }

            if (itInsertedSegment != activeSegments.begin()) {
                auto itBelow = prev(itInsertedSegment);
                if (intersect(*itBelow, *itInsertedSegment)) {
                    firstSegment = itBelow->idx;
                    secondSegment = itInsertedSegment->idx;
                    break;
                }
            }
        }
    }

    if (firstSegment > secondSegment) {
        swap(firstSegment, secondSegment);
    }


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i != secondSegment &&
            intersect(segments[i], segments[secondSegment])) {
            ans++;
        }
    }

    cout << ((ans > 1) ? secondSegment + 1 : firstSegment+1);

    return 0;
}