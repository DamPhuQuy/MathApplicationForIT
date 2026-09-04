// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;		cin >> n >> k;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	auto binarySearch = [&](ll val) {
		ll l = 0, r = n-1, ans = 0;
		while (l <= r) {
			ll m = (l+r)/2;
			if (arr[m] <= val) {
				ans = m+1;
				l = m+1;
			} else {
				r = m-1;
			}
		}
		return ans;
	};

	while (k--) {
		ll x;	cin >> x;
		cout << binarySearch(x) << nln;
	}

	return 0;
}