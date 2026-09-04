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

vector<vector<ll>> genSegment(ll n) {
	vector<vector<ll>> res;
	vector<ll> segment;
	ll s0 = 290797;
	for (int i = 0; i < 4*n; ++i) {
		ll s1 = s0*s0 % 50515093;
		segment.push_back(s1 % 500);
		s0 = s1;
		if (i % 4 == 3) {	
			res.push_back(segment);
			segment.clear();
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{

    int n;  cin >> n;
    vector<vector<ll>> test = genSegment(n);
    for (auto segment : test) {
    	for (auto num : segment)
    		cout << num << ' ';
    	cout << nln;
    }
 

    set<Point> events;
    vector<Segment> segments;
    for (int i = 0; i < n; ++i) {
        ll a, b, x, y;
        a = test[i][0], b = test[i][1], x = test[i][2], y = test[i][3];
        segments.push_back({a, b, x, y, i});
        events.insert({a, b, i});
        events.insert({x, y, i});
    }


    
    return 0;
}	