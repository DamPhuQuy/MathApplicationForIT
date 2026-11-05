#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime_factorize(int n, int primes[], int exponents[], int &size) {
    size = 0; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime(i)) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                primes[size] = i;
                exponents[size] = count;
                size++;
            }
        }
    }
    if (n > 1) { 
        primes[size] = n;
        exponents[size] = 1;
        size++;
    }
}

struct DivisorInfo {
    int count;
    int sum;
};

void printDivisors(int n) {
    vector<int> small_divisors, large_divisors;
    
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            small_divisors.push_back(i);
            if (i != n / i) {
                large_divisors.push_back(n / i);
            }
        }
    }

    cout << endl << "Cac uoc cua " << n << " la: ";
    for (int d : small_divisors) {
        cout << d << " ";
    }
    for (int i = large_divisors.size() - 1; i >= 0; --i) {
        cout << large_divisors[i] << " ";
    }
    cout << endl;
}

DivisorInfo countSumDivisors(int n) {
    int count = 1; 
    int sum = 1;
    
    for (int i = 2; i <= sqrt(n); ++i) {
        int exponent = 0;
        int term = 1;
        while (n % i == 0) {
            exponent++;
            n /= i;
            term *= i;
        }
        if (exponent > 0) {
            count *= (exponent + 1);
            sum *= (term * i - 1) / (i - 1);
        }
    }
    if (n > 1) {
        count *= 2;
        sum *= (n + 1); 
    }

    return {count, sum};
}

long long productOfDivisors(int n, int tau) {
    return (long long)(pow(n, tau / 2.0));
}

int main() {
    int n = 32000;
    int primes[100];     
    int exponents[100];  
    int size;            
    prime_factorize(n, primes, exponents, size);

    cout << "Tich cac thua so nguyen to cua " << n << " la:" << endl;
    cout << n << " = ";
    for (int i = 0; i < size; i++) {
        cout << primes[i];
    if(exponents[i] >= 0){
        cout << "^" << exponents[i];
    }
        if (i < size - 1) {
            cout << " * ";
    }
}
    int number = 90;
    printDivisors(number);

    DivisorInfo result = countSumDivisors(number);
    int totalDivisors = result.count;
    int totalSum = result.sum;
    long long product = productOfDivisors(number, totalDivisors);
    
    cout << "So luong uoc cua " << number << " la: " << totalDivisors << endl;
    cout << "Tong cac uoc cua " << number << " la: " << totalSum << endl;  
    return 0;
}
