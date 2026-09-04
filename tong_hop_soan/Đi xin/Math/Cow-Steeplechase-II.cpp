// Le Duc Phuc Long, 2024

#include <bits/stdc++.h>

#define nln '\n'

using namespace std;

typedef long long ll;
typedef long double db;

// Global variable
ll curX = 0; // Sweep Line

struct Point {
	ll idx;
    ll x, y;

    // Comparison operator to compare points based on their x-coordinate
    bool operator<(const Point& other) const {
        return x != other.x ? x < other.x : y < other.y;
    }

    // Subtraction operator to subtract two points
  	friend Point operator-(const Point& p1, const Point& p2) {
  		// cout << p1 << " - " << p2 << nln;
  		Point p; p.x = p1.x - p2.x, p.y = p1.y - p2.y;
        return p;
    }

    ll operator*(const Point& other) const {
    	ll crossProduct = (x*other.y - y*other.x);
    	return (crossProduct > 0) - (crossProduct < 0);
    }

    bool operator==(const Point& other) const {
    	return x == other.x && y == other.y;
	}

 	bool onSegment(const Point& p, const Point& r) const {
        return (x <= max(p.x, r.x) && x >= min(p.x, r.x) &&
                y <= max(p.y, r.y) && y >= min(p.y, r.y));
    }

	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};


struct Segment {
	ll idx;
	Point firstPoint, secondPoint;

	bool operator<(const Segment& other) const {
		// slope = rise/run
		// slope = (secondPoint.y - firstPoint.y) / (secondPoint.x - firstPoint.x) 
		// slope = (curY - firstPoint.y) / (curX - firstPoint.x)
		// => (curY-firstPoint.y) = (secondPoint.y-firstPoint.y)*(curX-firstPoint.x)/(secondPoint.x-firstPoint.x)
		// => curY = firstPoint.y + (secondPoint.y-firstPoint.y)*(curX-firstPoint.x)/(secondPoint.x-firstPoint.x)
		if (idx == other.idx)
			return false;

		db thisCurY = firstPoint.y;
		if (secondPoint.x != firstPoint.x)
			thisCurY = firstPoint.y + (secondPoint.y-firstPoint.y)*(curX-firstPoint.x)/(db)(secondPoint.x-firstPoint.x);

		db otherCurY = other.firstPoint.y;
		if (other.secondPoint.x != other.firstPoint.x)
			otherCurY = other.firstPoint.y + (other.secondPoint.y-other.firstPoint.y)*(curX-other.firstPoint.x)/(db)(other.secondPoint.x-other.firstPoint.x);

		// cout << "Cur y: " << thisCurY << " ~ " << otherCurY << nln;

		return thisCurY < otherCurY;
	}


	// bool isIntersecting(const Segment& other) const {
	//     Point A = firstPoint, B = secondPoint;
	//     Point C = other.firstPoint, D = other.secondPoint;

	//     ll cp1 = (D - C) * (A - C);
	//     ll cp2 = (D - C) * (B - C);
	//     ll cp3 = (B - A) * (C - A);
	//     ll cp4 = (B - A) * (D - A);

	//     // if (cp1 == 0 && cp2 == 0 && cp3 == 0 && cp4 == 0) {
	//     //     return A.onSegment(C, D) || B.onSegment(C, D) || C.onSegment(A, B) || D.onSegment(A, B);
	//     // }

	//     cout << (D - C) << nln;
	//     cout << (A - C) << nln;

	//     cout << cp1 <<' ' << cp2 << ' ' << cp3 << ' ' << cp4 << nln;

	//     return (cp1 * cp2 <= 0) && (cp3 * cp4 <= 0);	
	// }

	bool isIntersecting(const Segment& other) const {
		Point p1 = firstPoint, q1 = secondPoint, p2 = other.firstPoint, q2 = other.secondPoint;
		// cout << p1 << ' ' << q1 << nln;
		// cout << p2 << ' ' << q2 << nln;
		// cout << (q2 - p1) << nln;
		// // return true;
		// cout << "see: " <<  (q2 - p1)  * (q1 - p1) << nln;
		// cout << "see: " << (q1 - p2) * (q2 - p2) << nln;
		// cout << "see: " << (q2 - p2) * (p1 - p2) << nln;
		return ((q2 - p1) * (q1 - p1)) * ((q1 - p1) * (p2 - p1)) >= 0 &&
           ((q1 - p2) * (q2 - p2)) * ((q2 - p2) * (p1 - p2)) >= 0;
	}

};


int main(int argc, char const *argv[])
{
	// Fast IO
	cin.tie(0)->sync_with_stdio(0);
	// Input
	ll n;	cin >> n;
	vector<Segment> segments(n);

	set<Point> events;

	for (int i = 0; i < n; ++i) {
		segments[i].idx = i;
		cin >> segments[i].firstPoint.x >> segments[i].firstPoint.y >> segments[i].secondPoint.x >> segments[i].secondPoint.y;

		segments[i].firstPoint.idx = segments[i].secondPoint.idx = i;
		if (segments[i].secondPoint < segments[i].firstPoint)
			segments[i].firstPoint.idx += n;
		else
			segments[i].secondPoint.idx += n; 

		events.insert(segments[i].firstPoint);
		events.insert(segments[i].secondPoint);
	}

	// cout << segments[0].isIntersecting(segments[2]) << nln;

	// return 0;

	set<Segment> activeSegments;
	Segment firstSegment, secondSegment;
	for (const auto& event : events) {
		if (event.idx < n) { // If it's a begin point
			// Insert to activeSegments
			activeSegments.insert(segments[event.idx]);
			// Find the position of its in activeSegment (sorted by y)
			auto itInsertedSegment = activeSegments.find(segments[event.idx]);

			// Check intersecting with below segment
			auto itBelowSegment = itInsertedSegment;
			if (itBelowSegment != activeSegments.begin()) {
				itBelowSegment--;
				if (segments[event.idx].isIntersecting(*itBelowSegment)) {
					firstSegment = segments[event.idx],
					secondSegment = *itBelowSegment;
					// cout << "Break here! \n";
					// cout << "idx: " << event.idx << nln;
					break;
				}
			}

			// Check intersecting with above segment
			auto itAboveSegment = itInsertedSegment;
			itAboveSegment++;
			if (itAboveSegment != activeSegments.end()) {
				if (segments[event.idx].isIntersecting(*itAboveSegment)) {
					firstSegment = segments[event.idx];
					secondSegment = *itAboveSegment;
					break;
				}
			}
		} else { // If it's a end point
			// That mean it's already in activeSegments
			// Find position of that segment in the activeSegments
			// We want to delete it and check intersection with its neighborhood
			auto itDeletedSegment = activeSegments.find(segments[event.idx-n]);


			if (itDeletedSegment != activeSegments.begin() && next(itDeletedSegment) != activeSegments.begin()) {
				auto itBelowSegment = itDeletedSegment;
				itBelowSegment--;
				auto itAboveSegment = next(itDeletedSegment);
				if ((*itAboveSegment).isIntersecting(*itBelowSegment)) {
					firstSegment = (*itAboveSegment);
					secondSegment = (*itBelowSegment);
					break;
				}
			}
			activeSegments.erase(itDeletedSegment);
		}
	}

	// cout << firstSegment.idx << ' ' << secondSegment.idx << nln;
	// cout << firstSegment.firstPoint.x << ' ' << firstSegment.firstPoint.y << nln;
	// cout << secondSegment.firstPoint.x << ' ' << secondSegment.firstPoint.y << nln;

	ll cntFirst = 0, cntSecond = 0;
	if (firstSegment.idx < secondSegment.idx) {
		auto tmp = firstSegment;
		firstSegment = secondSegment;
		secondSegment = tmp;

	}

	// cout << secondSegment.firstPoint << nln;	

	for (const auto& segment : segments) {
		if (segment.idx != secondSegment.idx && secondSegment.isIntersecting(segment)) {
			// cout << segment.firstPoint << nln;
			cntSecond++; 
		}
	}

	if (cntSecond > 1) {
		cout << secondSegment.idx+1 << nln;
	} else {
		cout << firstSegment.idx+1 << nln;
	}


	return 0;
}