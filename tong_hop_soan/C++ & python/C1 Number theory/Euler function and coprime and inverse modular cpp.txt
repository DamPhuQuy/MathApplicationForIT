#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int euler_phi(int n) {
    int result = n;
    for (int p = 2; p <= sqrt(n); ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int power_mod(int a, int b, int m) {
    int result = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }
    return result;
}

int mod_inverse(int a, int m) {
    int phi_m = euler_phi(m);
    return power_mod(a, phi_m - 1, m);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, m;
    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap mod m: ";
    cin >> m;

    if (gcd(a, m) != 1) {
        cout << "Khong ton tai nghich dao modular cua " << a << " theo mod " << m << endl;
    } else {
        int inverse = mod_inverse(a, m);
        cout << "Nghich dao modular cua " << a << " theo mod " << m << " la: " << inverse << endl;
    }

    return 0;
}
