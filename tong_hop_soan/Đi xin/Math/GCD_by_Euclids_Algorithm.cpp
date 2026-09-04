#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

ll gcd(ll a, ll b) {
	if (a % b == 0)
		return b;
	return gcd(b, a%b);
}

int main() {
	cout << "Please enter two arbitrary numbers a and b: ";
	ll a, b;	cin >> a >> b;
	cout << "Their gcd by Euclid algorithm is: " << gcd(a, b) << nln;
	return 0;
}