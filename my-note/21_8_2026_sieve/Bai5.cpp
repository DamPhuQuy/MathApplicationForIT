// Bài 5: Fermat

#include <iostream>

using namespace std;

long long luyThua(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

long long tinhPhi(long long n) {
    long long res = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

int main() {
    long long x, m, k;
    if (!(cin >> x >> m >> k)) return 0;

    cout << "Fermat (x^(m-1) mod m): " << luyThua(x, m - 1, m) << endl;
    cout << "He qua: " << luyThua(x, k, m) << " == " << luyThua(x, k % (m - 1), m) << endl;

    long long p = tinhPhi(m);
    cout << "Euler (x^phi(" << m << ") mod " << m << "): " << luyThua(x, p, m) << endl;

    return 0;
}
