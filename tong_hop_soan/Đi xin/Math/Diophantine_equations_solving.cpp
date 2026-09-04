#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;
#define nln '\n'

ll fastpow(ll n, ll m) {
	ll res = 1;
	while (m > 0) {
		if (m % 2)
			res *= n;
		n *= n, m /= 2;
	}
	return res;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
	if (a % b == 0) {
		x = 0, y = 1;
		return b;
	}
	ll prev_x, prev_y, _gcd = gcd(b, a%b, prev_x, prev_y);
	x = prev_y, y = prev_x - a/b*prev_y;
	return _gcd;
}

bool solving(ll a, ll b, ll c) {
	ll x, y, _gcd = gcd(a, b, x, y);
	if (c % _gcd) {
		cout << "With given a, b, c. The equation cannot be solved!" << nln;
		return false;
	}
	cout << "Answer: " << "{" << c/_gcd*x << "+k*" << b/_gcd;
	cout << "; " << c/_gcd*y << "-k*" << a/_gcd << "}" << nln;
	return true;
}

int main() {
	cout << "Now we will solve an equation of the form: " << nln;
	cout << "ax + by = c" << nln;
	cout << "Now, you enter a, b and c,\nthe program will ";
	cout << "compute a form of solutions of pair (x, y)" << nln;
	ll a, b, c;	cin >> a >> b >> c;
	cout << "Solving: " << a << "x" << " + " << b << "y" << " = " << c << nln;
	solving(a, b, c);

	return 0;
}