// Le Duc Phuc Long, 2024
// You don't think twice, you code twice.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> P;

#define nln '\n'
#define X real()
#define Y imag()

// This code calculate the cross product that tell us whether
// a vector b turns left, turn right or does not turn if it is
// placed directly after a

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

int main(int argc, char* argv[]) {
	P A = {4, 2};
	P B = {1, 2};

	if (crossProduct(A, B) > 0)
		cout << "Vector B turn left, after the Vector A";
	else if (crossProduct(A, B) < 0)
		cout << "Vector B turn right, after the Vector A)";
	else
		cout << "Vector B go straight, does not turn after Vector A";
	
	return 0;
}