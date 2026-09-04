#include <iostream>

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

ll modulo_inverse(ll x, ll m) {
	return (fastpow(x, m-2) % m + m) % m;
}

int main() {
	cout << "please enter number of equations: ";
	ll n;	cin >> n;
	cout << "A group of equations have form like this: \n";
	cout << "x = a1 mod m1" << nln;
	cout << "x = a2 mod m2" << nln;
	cout << "..." << nln;
	cout << "x = an mod mn" << nln;
	cout << "Now you enter ai and mi" << nln;
	ll a[n], m[n], M = 1;
	for (int i = 1; i <= n; ++i) {
		cout << "enter the a " << i << " and m " << i << " : ";
		cin >> a[i-1] >> m[i-1];
		M *= m[i-1];
	}

	ll x = 0;
	for (int i = 0; i < n; ++i)
		x += M/m[i]*modulo_inverse(M/m[i], m[i])*a[i],
		x %= M;
	
	cout << "The solution is formed: " << x << " + " << "k*" << M << nln;

	return 0;
}