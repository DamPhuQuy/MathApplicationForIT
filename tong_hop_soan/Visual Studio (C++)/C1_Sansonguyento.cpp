//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//vector<int> eratosthenes(int n) {
//    vector<int> sieve(n + 1, 0);
//    for (int x = 2; x <= sqrt(n); ++x) {
//        if (!sieve[x]) {
//            for (int u = x * x; u <= n; u += x) {
//                sieve[u] = x;
//            }
//        }
//    }
//    return sieve;
//}
//
//void eratosthenes_range(int K, int N, vector<int>& sieve, long long& sum_primes, long long& product_primes) {
//    sieve.assign(N - K + 1, 0);
//    sum_primes = 0, product_primes = 1;
//    for (int x = 2; x <= sqrt(N); ++x) {
//        if (!sieve[x]) {
//            int start = max(x * x, ((K + x - 1) / x) * x);
//            for (int u = start; u <= N; u += x) {
//                sieve[u - K] = x;
//            }
//        }
//    }
//    if (K == 1) sieve[0] = 1;
//    for (int i = 0; i < sieve.size(); ++i) {
//        if (!sieve[i]) {
//            int prime_number = i + K;
//            sum_primes += prime_number;
//            product_primes *= prime_number;
//        }
//    }
//}
//
//int main() {
//    int n;
//    cout << "Nhap n: ";
//    cin >> n;
//    auto sieve = eratosthenes(n);
//    for (int i = 2; i <= n; ++i) {
//        cout << i << " " << sieve[i] << endl;
//    }
//    return 0;
//}
