#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Bai1 {
    static const int MAX = 100000;

public:
    void run() {
        int n;
        if (!(cin >> n) || n <= 1) return;

        vector<int> sieve = buildSieve();
        map<int, int> factors = prime_factorization(sieve, n);

        bool first = true;
        for (const auto& entry : factors) {
            if (!first) cout << " * ";
            cout << entry.first << "^" << entry.second;
            first = false;
        }
        cout << "\n";
    }

private:
    static vector<int> buildSieve() {
        vector<int> sieve(MAX + 1, 0);

        for (int i = 2; i <= MAX; i++) {
            if (sieve[i] == 0) {
                for (int u = i; u <= MAX; u += i) {
                    if (sieve[u] == 0) {
                        sieve[u] = i; // smallest prime factor
                    }
                }
            }
        }

        return sieve;
    }

    static map<int, int> prime_factorization(const vector<int>& sieve, int n) {
        map<int, int> factors;

        while (n > 1) {
            int p = sieve[n];
            int count = 0;

            while (n % p == 0) {
                count++;
                n /= p;
            }

            factors[p] = count;
        }

        return factors;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Bai1 bai1;
    bai1.run();

    return 0;
}
