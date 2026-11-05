#include <iostream>
#include <cmath>    
#include <iomanip>  

using namespace std;

const int MAX_N = 1000005; 
int lp[MAX_N] = {0}; 

int primes[MAX_N]; 

int primeCount = 0;

void linearSieve(int n) {

    for (int i = 2; i <= n; ++i) {

        if (lp[i] == 0) {
            lp[i] = i;              // Ước nhỏ nhất của số nguyên tố là chính nó
            primes[primeCount] = i; // Lưu vào danh sách
            primeCount++;           // Tăng biến đếm
        }

        for (int j = 0; j < primeCount; ++j) {
            int p = primes[j];

            if (p > lp[i] || (long long)i * p > n) {
                break;
            }

            lp[i * p] = p;
        }
    }
}

int main() {
    int n;
    cin>>n;
    linearSieve(n);

    int actualCount = primeCount; 

    double approxCount = n / log(n);

    cout << "N = " << n << endl;
    cout << "1. Dem chinh xac (Sieve): " << actualCount << endl;
    cout << fixed << setprecision(2);
    cout << "2. Tinh xap xi (n/ln n):  " << approxCount << endl;
    cout << "3. Sai so: " << abs(actualCount - approxCount) << endl;
    return 0;
}