#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) {
    int count = 1;
    
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) {
            int exponent = 0;

            while (n % x == 0) {
                exponent++;
                n /= x; 
            }
            count *= (exponent + 1);
        }
    }
    
    if (n > 1) {
        count *= 2; 
    }
    
    return count;
}

double productOfDivisors(int n) {
    int totalDivisors = countDivisors(n);

    return pow(n, totalDivisors / 2.0); 
}

int main() {
    int n = 102240204;
    cout << "Nhap n: " << n << endl;
    
    int divisors = countDivisors(n);
    cout << "Tich cac uoc cua " << n << " la: " << productOfDivisors(n) << endl;
    
    return 0;
}
