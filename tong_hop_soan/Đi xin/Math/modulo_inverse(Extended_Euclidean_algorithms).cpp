#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

ll modulo_inverse(ll a, ll b, ll& x, ll& y) {
	if (a % b == 0) {
		x = 0; y = 1;
		return b;
	}
	ll t_x, t_y;
	ll tmp = modulo_inverse(b, a%b, t_x, t_y);
	x = t_y;
	y = t_x - a/b*t_y;
	
	return tmp;
}

ll gcd(ll a, ll b) {
	ll x, y;
	return modulo_inverse(a, b, x, y);
}

ll inverse_modular(ll n, ll m) {
	ll x = 10, y = 20;
	ll tmp = modulo_inverse(n, m, x, y);
	x = (x + m) % m;
	return x;
}

int main() {
	cout << "You enter 2 intergers x and m";
	cout << ", the monitor will display modulo inverse ";
	cout << "of x (mod m), please: ";
	ll x, m;	cin >> x >> m;
	cout << "Inverse Modular: " << inverse_modular(x, m) << nln;
	return 0;
}