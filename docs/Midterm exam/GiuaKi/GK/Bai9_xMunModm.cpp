#include <iostream>
using namespace std;

int modPow(int x, int n, int m) {
    if (n == 0) return 1 % m;
    long u = modPow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int x, n, m;
    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    cout << x << "^" << n << " % " << m << " = " << modPow(x, n, m) << endl;
}