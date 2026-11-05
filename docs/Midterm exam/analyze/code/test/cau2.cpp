#include <iostream>
using namespace std;

// extended Euclidean algorithm
long long extendedGCD(long long a, long long b,
                      long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// modulo inverse
long long modInverse(long long a, long long m) {
    long long x, y;
    extendedGCD(a, m, x, y);
    return (x % m + m) % m;
}

// Chinese Remainder Theorem
long long CRT(long long a[], long long m[], int n) {
    long long M = 1;

    for (int i = 0; i < n; i++)
        M *= m[i];

    long long x = 0;

    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long yi = modInverse(Mi, m[i]);

        x += a[i] * Mi * yi;
    }

    return (x % M + M) % M;
}

int main() {
    int n;
    cout << "Nhap so luong phuong trinh dong du: ";
    cin >> n;

    long long a[n], m[n];

    cout << "Nhap cac he so va moduli: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        cin >> a[i] >> m[i];
    }

    long long x = CRT(a, m, n);

    long long M = 1;
    for (int i = 0; i < n; i++)
        M *= m[i];

    cout << x << " (mod " << M << ")" << endl;

    cout << "Dang tong quat: x = " << x << " + k * " << M << ", voi k la mot so nguyen" << endl;

    return 0;
}
