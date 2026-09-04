// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;

ll sweep_line_x = 0;

struct Point {
	ll x, y, idx;
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
        return b + (y - b) * (sweep_line_x - a) / static_cast<double>(x - a);
    }

    bool operator<(const Segment& other) const {
        return idx != other.idx && Y_coordinate() <= other.Y_coordinate();
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
	int n;	cin >> n;
	set<Point> events;
	vector<Segment> segments;
	for (int i = 0; i < n; ++i) {
	    int a, b, x, y;
	    cin >> a >> b >> x >> y;
	    segments.push_back({a, b, x, y, i});
	    events.insert({a, b, i});
	    events.insert({x, y, i});
	}

	set<Segment> active_segments;

	int first_segment, second_segment;

	for (auto& event : events) {
		first_segment = event.idx;
		sweep_line_x = event.x;
		auto it = active_segments.find(segments[first_segment]);
		if (it != active_segments.end()) {
			auto after = next(it), before = it;
			if (before != active_segments.begin() &&
				after != active_segments.end()) {
				before--;
				if (intersect(segments[before->idx], segments[after->idx])) {
					first_segment = before->idx;
					second_segment = after->idx;
					break;
				}
			}
		active_segments.erase(it);
		} else {
			it = active_segments.lower_bound(segments[first_segment]);

			if (it != active_segments.end() &&
				intersect(segments[first_segment], *it)) {
				second_segment = it->idx;
				break;
			}
			if (it != active_segments.begin()) {
				it--;
				if (intersect(segments[it->idx], segments[first_segment])) {
					second_segment = it->idx;
					break;
				}
			}
			active_segments.insert(segments[first_segment]);
		}
	}

	if (first_segment > second_segment) {
		swap(first_segment, second_segment);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i != second_segment &&
			intersect(segments[i], segments[second_segment])) {
			ans++;
		}
	}

	cout << ((ans > 1) ? second_segment + 1 : first_segment+1);

	return 0;
}