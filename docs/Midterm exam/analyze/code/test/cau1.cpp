#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<pair<long long, int>> primeFactors(long long n) {
    vector<pair<long long, int>> factors;
    if (n % 2 == 0) {
        int count = 0;
        while (n % 2 == 0) {
            count++;
            n /= 2;
        }
        factors.push_back({2, count});
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

long long maxPrimeFactor(long long n) {
    vector<pair<long long, int>> factors = primeFactors(n);
    if (factors.empty()) return -1;
    return factors.back().first;
}

bool isPerfect(long long n) {
    if (n <= 1) return false;
    long long sum = 1;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

pair<vector<long long>, long long> primeNumbersLessThanAndSum(long long m) {
    vector<long long> primes;
    long long sum = 0;
    for (long long i = 2; i < m; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
            sum += i;
        }
    }
    return {primes, sum};
}

pair<vector<long long>, long long> perfectNumbersLessThanAndSum(long long m) {
    vector<long long> perfectNumbers;
    long long sum = 0;
    for (long long i = 2; i < m; i++) {
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
            sum += i;
        }
    }
    return {perfectNumbers, sum};
}

int main() {
    long long n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    vector<pair<long long, int>> factors = primeFactors(n);
    cout << "Cac thua so nguyen to cua " << n << " la: ";
    for (size_t i = 0; i < factors.size(); i++) {
        cout << factors[i].first << "^" << factors[i].second;
        if (i + 1 < factors.size()) {
            cout << " * ";
        }
    }
    cout << endl;

    long long m = maxPrimeFactor(n);
    cout << "Uoc so nguyen to lon nhat cua " << n << " la: " << m << endl;

    pair<vector<long long>, long long> primeResult = primeNumbersLessThanAndSum(m);
    cout << "Cac so nguyen to nho hon " << m << " la: ";
    for (long long prime : primeResult.first) {
        cout << prime << " ";
    }
    cout << endl;
    cout << "Tong cua cac so nguyen to nho hon " << m << " la: " << primeResult.second << endl;

    pair<vector<long long>, long long> perfectResult = perfectNumbersLessThanAndSum(m);
    cout << "Cac so hoan hao nho hon " << m << " la: ";
    for (long long perfect : perfectResult.first) {
        cout << perfect << " ";
    }
    cout << endl;
    cout << "Tong cua cac so hoan hao nho hon " << m << " la: " << perfectResult.second << endl;

    return 0;
}
