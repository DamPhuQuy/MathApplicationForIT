#include <iostream>

using namespace std;

// Độ phức tạp: O(log exp)
long long powerMod(long long base, long long exp, long long m) {
    long long res = 1;
    base %= m;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % m;
        base = (base * base) % m;
        exp /= 2;
    }
    return res;
}

long long modInversePrime(long long n, long long m) {
    return powerMod(n, m - 2, m);
}

int main() {
    long long a, m;
    cout << "Nhap so a: "; cin >> a;
    cout << "Nhap module m (phai la so nguyen to): "; cin >> m;
    cout << "Nghich dao cua " << a << " mod " << m << " la: " 
         << modInversePrime(a, m) << endl;

    return 0;
}