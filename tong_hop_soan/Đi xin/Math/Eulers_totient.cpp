#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

ll phi(ll n) {
	ll res = n, tmp = n;
	for (int i = 2; i*i <= tmp; ++i)
		if (n % i == 0) {
			res -= res / i;
			while (n % i == 0)
				n /= i;
		}
	if (n > 1) {
		res -= res  / n;
	}
	return res;
}

int main() {
	cout << "Please enter a arbitrary number: ";
	ll n;	cin >> n;
	cout << "Its Euler's totient is: " << phi(n) << nln;
	return 0;
}