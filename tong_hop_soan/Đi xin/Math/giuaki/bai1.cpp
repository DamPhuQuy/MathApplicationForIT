// Le Duc Phuc Long, 2024e

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

ll sum_dvs(ll n) {
	ll s = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0) {
			if (i*i == n)
				s += i;
			else
				s += (i + n/i);
		}
	return s-n;
}

int main() {
	ll n = 8501;
    vector<ll> perfects;
	for (ll i = 1; i < n; ++i)
		if (sum_dvs(i) == i) {
			perfects.push_back(i);
		}
	cout << "Numbers of perfect numbers: " << perfects.size() << nln;
	cout << "They are: " << nln;
	ll m = -1;
	for (auto v : perfects) {
		cout << v << ' ';
		m = v;
	}
	cout << nln;

	cout << "Sum: " << accumulate(perfects.begin(), perfects.end(), 0) << nln;

	cout << "The largest perfect number found is: " << m << nln;
	cout << "The k nearest m and divided by 5 is: ";
	ll k = m;
	ll i = 1;
	while ((k+i) % 5 != 0 and (k-i) % 5 != 0)
		i++;
	if ((k+i) % 5 == 0)
		cout << k+i << nln;
	else
		cout << k-i << nln;

	return 0;
}