#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

bool isCoprime (int a, int b) {
    int ucln;
    if (a < b) ucln = UCLN(b, a);
    else ucln = UCLN(a, b);
    if (ucln == 1) return true;
    else return false;
}

bool isPrime(int n) {
    int num = 1;
    for (int i = 2; i < n; i++) {
        if (isCoprime(n, i)) num++; 
    }

    if (num == n - 1) return true;
    return false;
}

int FmodPow(int x, int n, int m) {
    n %= (m - 1);
    if (n == 0) return 1 % m;
    long u = FmodPow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int x, n, m;
    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    if(isPrime(m) && isCoprime(x, m)) {
        cout << x << "^" << n << " % " << m << " = " << FmodPow(x, n, m) << endl;
    }
    else cout << "Khong the su dung Fermat's Theorem!" << endl;
}