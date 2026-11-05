#include <iostream>
#include <vector>
using namespace std;

// --- Hàm sàng Eratosthenes ---
// Trả về tất cả số nguyên tố trong đoạn [k, n]
vector<int> sieve(int k, int n) { // O(n log log n)
    if (n < 2 || k > n) return {};

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = max(k, 2); i <= n; ++i)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Cac so nguyen to tu 2 den " << n << " la:\n";
    vector<int> primes = sieve(2, n);
    for (int p : primes) cout << p << ' ';
    cout << "\n\n";

    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;

    cout << "Cac so nguyen to trong khoang [" << a << ", " << b << "] la:\n";
    for (int p : sieve(a, b))
        cout << p << ' ';

    cout << '\n';
    return 0;
}
