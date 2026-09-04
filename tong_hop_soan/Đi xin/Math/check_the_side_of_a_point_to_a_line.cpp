// Le Duc Phuc Long, 2024
// You don't think twice, you code twice.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
typedef complex<ll> V;

#define nln '\n'
#define X real()
#define Y imag()

complex<ll> calculateVector(P A, P B) {
	return {B.X - A.X, B.Y - A.Y};
}

ll crossProduct(P A, P B) {
	// Explain this function
	// Assume: A = {x1, y1}  |  B = {x2, y2}
	// (conj(a)*b).Y
	// is the imagine part of conj(a)*b
	// We have: conj(a)*b
	// = conj(x1 + y1.i)*(x2 + y2.i)
	// = (x1 - y1.i)*(x2 + y2.i)
	// = x1.x2 + x1.y2.i - x2.y1.i - y1.y2.i^2 (i^2 = 1)
	// = (x1.x2 - y1.y2) + (x1.y2 - x2.y1).i
	// So imagine part is (x1.y2 - x2.y1)
	// And it is also the cross product of A and B
	return (conj(A)*B).Y;
}

// function to check the side of a point to a straight line
// defined by other two points.
ll checkTheSide(P C, P A, P B) {
	// We will check if if we stand at point A and see forward to
	// B, then C is on the left or on the right (or on straight).

	// First we calculate the Vector AC and Vector CB
	V AC = calculateVector(A, C);
	V CB = calculateVector(C, B);
	ll crossProductResult = crossProduct(AC, CB);
	if (crossProductResult > 0) {
		return 1;
	} else if (crossProductResult < 0) {
		return 0;
	} else {
		cout << "C is on the line go through A and B.";
	}
	// if C in on the right of the straight line AB. 
	// --> function return 1
	// if C in on the left of straight line AB.
	// --> function return -1
	// if C in on the straight line AB
	// --> function return 0
	return 0;
}

int main(int argc, char* argv[]) {
	// Give a straight line defined by 2 points A and B
	// And a point C
	P A = {3, 1}, B = {5, 2}, C = {4, 0};

	// After that, we will determine the side depend on
	// cross product
	ll side = checkTheSide(C, A, B);
	if (side > 0) {
		cout << "C is on the right.";
	} else if (side < 0) {
		cout << "C is on the left.";
	} else {
		cout << "C is on the line go through A and B.";
	}

	return 0;
}