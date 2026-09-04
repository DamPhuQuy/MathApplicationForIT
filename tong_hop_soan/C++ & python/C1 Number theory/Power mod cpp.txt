#include <iostream>
using namespace std;

int modpow(int a, int m, int n) {
    if (m == 0) return 1 % n;
    int u = modpow(a, m / 2, n);
    u = (u * u) % n;
    if (m % 2 == 1) {
        u = (u * a) % n;
    }
    return u;
}

int main() {
    int a, m, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    int result = modpow(a, m, n);
    cout << "Gia tri cua " << a << "^" << m << " mod " << n << " = " << result << endl;

    return 0;
}
