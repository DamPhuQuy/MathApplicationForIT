// Le Duc Phuc Long, 2024
// You don't think twice, you code twice.

#include <iostream>
#include <complex>
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

ll segmentIntersection(P A, P B, P C, P D) {
    // Determine the intersection status of line segments AB and CD
    if (checkTheSide(C, A, B) == 0 && checkTheSide(B, C, D) == 0) {
        if (C.X < B.X || A.X < D.X) {
            return 1; // Segments overlap
        }
    }
    if (A == C || A == D || B == C || B == D)
        return 2; // Segments intersect at a vertex
    if (checkTheSide(A, C, D) != checkTheSide(B, C, D) 
        && checkTheSide(C, A, B) != checkTheSide(D, A, B))
        return 3; // Segments intersect at a non-vertex point
    return 0; // Segments do not intersect
}

int main() {
    // Example usage
    P A(0, 0), B(4, 4), C(2, 2), D(6, 6);
    ll intersectionStatus = segmentIntersection(A, B, C, D);
    cout << "Intersection Status: " << intersectionStatus << endl;
    return 0;
}
