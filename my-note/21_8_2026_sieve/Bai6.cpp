// Bài 6: Chinese Remainder Theorem

#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

long long phi(long long n) {
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
    int n;
    cout << "So phuong trinh: ";
    cin >> n;

    vector<long long> a(n), m(n);
    long long M = 1;
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "] va m[" << i << "]: ";
        cin >> a[i] >> m[i];
        M *= m[i];
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long yi = power(Mi, phi(m[i]) - 1, m[i]);
        result = (result + (__int128)a[i] * Mi % M * yi) % M;
    }

    cout << "Nghiem x (theo Chinese Remainder Theorem)= " << result << " + k*" << M << endl;
    return 0;
}
