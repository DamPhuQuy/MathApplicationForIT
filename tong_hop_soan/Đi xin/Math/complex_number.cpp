// Le Duc Phuc Long, 2024
// You don't think twice, you code twice.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;

#define nln '\n'
#define X real()
#define Y imag()


int main(int argc, char* argv[]) {
	P A = {2, 4};
	cout << A.X << ' ' << A.Y << '\n' << nln;

	P B = {3, 5};

	P C = A + B;
	cout << C.X << ' ' << C.Y << '\n' << nln;
	return 0;
}