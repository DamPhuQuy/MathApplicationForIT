#include <iostream>
using namespace std;

long long sumOfDivisors(int n) {
    long long totalSum = 1;
    
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) {
            long long currentSum = 1; 
            long long term = 1;       

            while (n % x == 0) {
                term *= x;
                currentSum += term;
                n /= x; 
            }
            totalSum *= currentSum;
        }
    }

    if (n > 1) {
        totalSum *= (1 + n);
    }
    
    return totalSum;
}

int main() {
    int n = 102240204;
    cout << "Nhap n: " << n << endl;
    cout << "Tong cac uoc cua " << n << " la: " << sumOfDivisors(n) << endl;
    return 0;
}
