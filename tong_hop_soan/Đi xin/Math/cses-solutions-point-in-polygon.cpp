// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
#define x first
#define y second

using ll = long long;

typedef pair<ll, ll> Point;
typedef pair<ll, ll> Vector;

const ll Inf = ll(1e9);

ll crossProduct(Vector A, Vector B) {
	return A.x*B.y - A.y*B.x;
}

ll dotProduct(Vector A, Vector B) {
	return A.x*B.x + A.y*B.y;
}

Vector calculateVector(Point A, Point B) {
	return {B.x - A.x, B.y - A.y};
}

bool isOnTheSegmentLine(Point A, Point B, Point C) {
	Vector BC = calculateVector(B, C);
	Vector BA = calculateVector(B, A);
	Vector AB = calculateVector(A, B);
	Vector AC = calculateVector(A, C);
	return (crossProduct(BC, BA) == 0 && dotProduct(AB, AC) <= 0);
}

bool comp(const Point &A, const Point &B) {
	return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}

// bool isIntersecting(Point A, Point B, Point C) {
//     // Check if the ray intersects the line segment BC
//     if ((A.y <= B.y && A.y >= C.y) || (A.y >= B.y && A.y <= C.y)) {
//         return (A.y-B.y)*(C.x-B.x) >= (A.x-B.x)*(C.y-B.y);
//     }
//     return false; // No intersection
// }

// bool isIntersecting(Point A, Point B, Point C) {
//     if (A.y == B.y || A.y == C.y) {
//         // Skip the collinear case for now
//         return false;
//     }
//     if ((A.y > B.y) == (A.y > C.y)) {
//         return false; // A is outside the segment
//     }
//     ll t = (C.x - B.x) * (A.y - B.y) - (C.y - B.y) * (A.x - B.x);
//     ll s = (A.y - B.y) * (A.x - C.x) + (B.x - A.x) * (A.y - C.y);
//     if (t == 0 && s == 0) {
//         // A is on the segment BC
//         return true;
//     }
//     if (t == 0) {
//         // Parallel and non-intersecting
//         return false;
//     }
//     // Check if the point A is to the left of the segment BC
//     return (t > 0) == (s > 0);
// }

ll checkTheSide(Point C, Point A, Point B) {
    // Check which side point C lies on with respect to the line defined by points A and B
    Vector AC = calculateVector(A, C); // Vector AC
    Vector CB = calculateVector(C, B); // Vector CB
    ll crossProductResult = crossProduct(AC, CB); // Calculate the cross product of AC and CB
    if (crossProductResult > 0) {
        return 1; // C is on the right side of the line AB
    } else if (crossProductResult < 0) {
        return -1; // C is on the left side of the line AB
    } else {
        return 0; // C is on the line AB
    }
}

bool segmentIntersection(Point A, Point B, Point C, Point D) {
	// cout << "hello" << nln;
    // Determine the intersection status of line segments AB and CD
    if (checkTheSide(C, A, B) == 0 && checkTheSide(B, C, D) == 0) {
        if (C.x < B.x || A.x < D.x) {
            return 1; // Segments overlap
        }
    }
    if (A == C || A == D || B == C || B == D)
        return 2; // Segments intersect at a vertex
    if (checkTheSide(A, C, D) != checkTheSide(B, C, D) 
        && checkTheSide(C, A, B) != checkTheSide(D, A, B))
        return 3; // Segments intersect at a non-vertex point
    // cout << "hi" << nln;
    return 0; // Segments do not intersect
}



int main(int argc, char* argv[]) {
	// Point A{3, 4}, B{3, 4}, C{3, 0};
	// cout << isOnTheSegmentLine(A, B, C) << nln;
	// return 0;

	cin.tie(0)->sync_with_stdio(0);
	ll n, m;	cin >> n >> m;
	vector<Point> Polygon(n);
	for (auto &p : Polygon)
		cin >> p.x >> p.y;
		
	while (m--) {
		Point A;	cin >> A.x >> A.y;
		Point B = Polygon[0];
		bool flag = false; // is on the boundary
		ll cnt = 0; // number of intersections with edges
		for (int i = 1; i <= n; ++i) {
			Point C = Polygon[i%n];
			if (C.y == A.y) {
				Point InfPoint{Inf, A.y};
				Point prev = Polygon[i-1];
				Point next = Polygon[(i+1)%n];
				if (checkTheSide(prev, A, InfPoint) != checkTheSide(next, A, InfPoint))
					cnt += 1;
				B = Polygon[++i];
				continue;
			} else if (isOnTheSegmentLine(A, B, C)) {
				flag = true;
				break;
			} else {
				Point InfPoint{Inf, A.y};
				cnt += segmentIntersection(A, InfPoint, B, C);
				if (segmentIntersection(A, InfPoint, B, C)) {
					// cout << B.x << ' ' << B.y << nln;
					// cout << C.x << ' ' << C.y << nln;
					// cout << nln;
					// cout << "hello" << nln;
				}
			}
			B = C;
		}
		if (flag) {
			cout << "BOUNDARY" << nln;
		} else {
			cout << ((cnt % 2 == 1) ? "INSIDE" : "OUTSIDE") << nln;
		}
	}

	// cerr << "Everything is ok, Long!" << nln;
	return 0;
}