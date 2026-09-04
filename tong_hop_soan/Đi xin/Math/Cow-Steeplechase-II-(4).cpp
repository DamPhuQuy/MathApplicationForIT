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
        return x == other.x ? y < other.y : x < other.x;
    }

    ll operator*(const Point& other) const {
        ll crossProduct = x*other.y - y*other.x;
        return (crossProduct > 0) - (crossProduct < 0);
    }

    Point operator-(const Point& other) const {
        Point tmp = {x - other.x, y - other.y};
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
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
        Point p1 = {a, b, i}, p2 = {x, y, i};
        if (p1 < p2)
            p2.idxSegment += n;
        else
            p1.idxSegment += n;
        events.insert(p1);
        events.insert(p2);
    }

    ll firstSegment, secondSegment;
    set<Segment> activeSegments;

    for (const auto& event : events) {
        if (event.idxSegment >= n) {
            // cout << "Close!" << nln;
            // Check the intersecting of the above and below segment
            auto deletedSegment = activeSegments.find(segments[event.idxSegment - n]);
            auto belowSegment = deletedSegment;
            auto aboveSegment = next(deletedSegment);
            if (belowSegment != activeSegments.begin() &&
            aboveSegment != activeSegments.end()) {
                belowSegment--;
                if (intersect(*belowSegment, *aboveSegment)) {
                    firstSegment = belowSegment->idx;
                    secondSegment = aboveSegment->idx;
                    break;
                }
            }    
            activeSegments.erase(deletedSegment);        
        } else {
            // cout << "Open!" << nln;
            // Insert that segments into the activeSegments
            activeSegments.insert(segments[event.idxSegment]);
            // Check intersecting with above segment
            auto itInsertedSegment = activeSegments.find(segments[event.idxSegment]);
            auto aboveSegment = next(itInsertedSegment);
            if (aboveSegment != activeSegments.end()) {
                if (intersect(*aboveSegment, *itInsertedSegment)) {
                    firstSegment = aboveSegment->idx;
                    secondSegment = itInsertedSegment->idx;
                    break;
                }
            }
            // Check intersecting with below segment
            auto belowSegment = itInsertedSegment;
            if (belowSegment != activeSegments.begin()) {
                belowSegment--;
                if (intersect(*belowSegment, *itInsertedSegment)) {
                    firstSegment = belowSegment->idx;
                    secondSegment = itInsertedSegment->idx;
                    break;
                }
            }
        }
    }

    if (firstSegment > secondSegment) {
        swap(firstSegment, secondSegment);
    }

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (secondSegment != i && intersect(segments[secondSegment], segments[i])) {
            cnt++;
        }
    }

    cout << ((cnt > 1) ? secondSegment : firstSegment) + 1 << nln;
    
    return 0;
}