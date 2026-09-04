/* About Fermat's little theorem
  Acording to Euler's theorem:
  x^phi(m) mod m = 1
  When m is a prime
  x^m-1 mod m = 1
  => x^m-2 = x^-1 (mod m)
*/

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
	return fastpow(x, m-2) % m;
}	

int main() {
	cout << "You enter 2 intergers x and m";
	cout << ", the monitor will display modulo inverse ";
	cout << "of x (mod m), please: ";
	ll x, m;	cin >> x >> m;
	cout << "Inverse Modular: " << modulo_inverse(x, m) << nln;
	return 0;
}