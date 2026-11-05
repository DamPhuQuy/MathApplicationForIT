#include <iostream>
#include <vector>
using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
long long eulerPhi(long long n) {
    long long phi = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            phi -= phi / i;
        }
    }
    if (n > 1)
        phi -= phi / n;
    return phi;
}
vector<long long> modInverse(const vector<long long>& x, const vector<long long>& m) {
    vector<long long> inv;
    for (size_t i = 0; i < x.size(); ++i) {
        long long inverse = modPow(x[i], eulerPhi(m[i]) - 1, m[i]);
        inv.push_back(inverse);
    }
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap so phuong trinh: ";
    cin >> n;

    vector<long long> a(n), m(n);
    cout << "Nhap lan luot cac cap (a_i, m_i):\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> m[i];
    }
    long long M = 1;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    vector<long long> M_i(n);
    for (int i = 0; i < n; ++i)
        M_i[i] = M / m[i];
    vector<long long> inv_M_i = modInverse(M_i, m);
    long long x = 0;
    for (int i = 0; i < n; ++i) {
        x = (x + a[i] * M_i[i] % M * inv_M_i[i] % M) % M;
    }

    cout << "\nNghiem cua he dong du la:\n";
    cout << "x = " << x << " + k*" << M << "\n";

    return 0;
}
