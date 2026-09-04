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

db crossProduct(P A, P B) {
    // Calculate the cross product of vectors A and B
    return (conj(A) * B).imag();
}

V calculateVector(P A, P B) {
    // Calculate the vector from point A to point B
    return B - A;
}

db areaOfTriangle(P A, P B, P C) {
    V AB = calculateVector(A, B);
    V AC = calculateVector(A, C);
    return abs(crossProduct(AB, AC)/2);
}

db sqr(db x) {
    return x*x;
}

db magnitudeOfVector(V A) {
    return sqrt(sqr(A.X) + sqr(A.Y));
}

db areaOfTriangle_Heron(P A, P B, P C) {
    V AC = calculateVector(A, C);
    V BC = calculateVector(B, C);
    V AB = calculateVector(A, B);
    db lenAC = magnitudeOfVector(AC);
    db lenBC = magnitudeOfVector(BC);
    db lenAB = magnitudeOfVector(AB);
    db P = (lenAC + lenAB + lenBC)/2;
    return sqrt(P*(P-lenAC)*(P-lenBC)*(P-lenAB));
}

db ShortestDistanceOfPointAndLine(P A, P B, P C) {
    // Assuming we have three A, B, C
    // Points B and C determine a line
    // Now will will calculate the shortest distance
    // of point A to that line

    // Theory:
    // We can calculate the area of triangle ABC in 2 ways
    // First way: S(ABC) = d*|BC|/2
    // (d is the those shortest distance)
    // Second way: S(ABC) = ABxAC/2
    // (We use cross product of two vectors AB and AC)
    // From these two ways we can calculate the d by:
    // --> d = ABxAC/|BC|

    V AB = calculateVector(A, B);
    V AC = calculateVector(A, C);
    V BC = calculateVector(B, C);

    return abs(crossProduct(AB, AC))/abs(BC);
}

int main() {
    // Example usage
    P A(-2, 0), B(-2, 2), C(1, 0);
    cout << "Area of Triangle ABC: " << areaOfTriangle(A, B, C) << nln;
   
    return 0;
}
