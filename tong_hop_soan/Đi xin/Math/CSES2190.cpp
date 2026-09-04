#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double db;
typedef complex<db> P;
typedef complex<db> V;

#define nln '\n'
#define X real()
#define Y imag()

ll crossProduct(P A, P B) {
    // Calculate the cross product of vectors A and B
    db crossProductResult = (conj(A) * B).imag(); // Imaginary part of conj(A) * B
    return (crossProductResult > 0) ? 1 : ((crossProductResult < 0) ? -1 : 0);
}

V calculateVector(P A, P B) {
    // Calculate the vector from point A to point B
    return B - A;
}

bool cmp(const P& A, const P& B) {
    return (A.X == B.X) ? (A.Y < B.Y) : (A.X < B.X);
}

bool isMidPoint(P A, P B, P C) {
    vector<P> s = {A, B, C};
    sort(s.begin(), s.end(), cmp);
    return s[1] == A;
}

ll checkTheSide(P C, P A, P B) {
    // Check which side point C lies on with respect to the line defined by points A and B
    V AC = calculateVector(A, C); // Vector AC
    V CB = calculateVector(C, B); // Vector CB
    ll crossProductResult = crossProduct(AC, CB); // Calculate the cross product of AC and CB
    if (crossProductResult > 0) {
        return 1; // C is on the right side of the line AB
    } else if (crossProductResult < 0) {
        return -1; // C is on the left side of the line AB
    } else {
        return 0; // C is on the line AB
    }
}

bool segmentIntersection(P A, P B, P C, P D) {
    // Determine if there is any intersection between line segments AB and CD

    // Check if the segments are collinear
    if (crossProduct(B - A, C - A) == 0 && crossProduct(B - A, D - A) == 0) {
        // Check if any of the endpoints of one segment lies on the other segment
        if (isMidPoint(A, C, D) || isMidPoint(B, C, D) ||
            isMidPoint(C, A, B) || isMidPoint(D, A, B)) {
            return true; // Segments overlap or intersect at a vertex
        }
    }
    // Check if the segments intersect at a non-vertex point
    return checkTheSide(C, A, B) != checkTheSide(D, A, B) &&
           checkTheSide(A, C, D) != checkTheSide(B, C, D);
}

int main() {
    // Example usage
    P A(0, 0), B(4, 4), C(2, 2), D(6, 6);
    ll n;   cin >> n;
    while (n--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        A = P(x1, y1), B = P(x2, y2), C = P(x3, y3), D = P(x4, y4);
        if (segmentIntersection(A, B, C, D)) {
            cout << "YES" << nln;
        } else {
            cout << "NO" << nln;
        }
    }
    return 0;
}
