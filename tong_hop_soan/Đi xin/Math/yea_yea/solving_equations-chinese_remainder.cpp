#include <iostream>

using namespace std;

typedef long long ll;

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
    return (fastpow(x, m - 2) % m + m) % m;
}

pair<int, int> solveChineseRemainder(int n, ll a[], ll m[]) {
    ll M = 1;
    for (int i = 0; i < n; ++i)
        M *= m[i];

    ll x = 0;
    for (int i = 0; i < n; ++i)
        x += M / m[i] * modulo_inverse(M / m[i], m[i]) * a[i],
        x %= M;

    return {x, M};
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    ll a[n], m[n];
    cout << "Enter the values of a and m for each equation:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }

    auto solution = solveChineseRemainder(n, a, m);
    
    cout << "The solution is formed: " << solution.first << " + " << "k*" << solution.second  << endl;

    return 0;
}

// int main() {
//     int n = 4; // number of equations
//     ll a[] = {1, 4, 1, 1}; // a values
//     ll m[] = {3, 5, 7, 8}; // m values

//     auto solution = solveChineseRemainder(n, a, m);
    
//     cout << "The solution is formed: " << solution.first << " + " << "k*" << solution.second  << endl;

//     return 0;
// }
