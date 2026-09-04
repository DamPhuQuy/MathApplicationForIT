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



int main() {
    // Test
    // Point A{-4, 0}, B{-2, 0}, C{-5, 0};
    // Driver code
    cin.tie(0)->sync_with_stdio(0);

    vector<Point> Polygon;
    Polygon.push_back(Point(2, 4));
    Polygon.push_back(Point(3, 9));
    Polygon.push_back(Point(9, 11));
    Polygon.push_back(Point(15, 4));
    Polygon.push_back(Point(7, 2));


    vector<Point> points = {
        {7, 2}, {6, 3}, {3, 9}, {10, 7}, {2, 4},
        {15, 4}, {12, 5}, {8,6}, {10, 4}, {9, 11}
    };

    ll cnt = 0;

    cout << "Nhung diem nam trong la: " << nln;

    for (auto point : points) {
        ll X, Y;    X = point.x, X = point.y;
        Point P(X, Y);
        ll postion =  pointToPolygon(P, Polygon);
        cout << ((postion == 0) ? "BOUNDARY" : ((postion == 1) ? "INSIDE" : "OUTSIDE")) << nln;
        if (postion == 1) {
            cout << P << nln;
            cnt++;
        }
    }

    cout << "So luong diem nam trong la: " << cnt << nln;

    return 0;
}