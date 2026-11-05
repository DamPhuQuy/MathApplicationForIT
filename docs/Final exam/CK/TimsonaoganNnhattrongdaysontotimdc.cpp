 #include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; 
    int limit = sqrt(n); 
    for (int i = 3; i <= limit; i += 2) { 
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int M = 50, N = 500;
    int target = 300;
    
    int closestPrime = -1;
    int minDiff = 1000000; 
    
    for (int i = M + 1; i < N; i++) {
        if (isPrime(i)) {
            int currentDiff = abs(i - target);
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                closestPrime = i;
            }
        }
    }
    
    if (closestPrime != -1) {
        cout << "Trong cac so nguyen to tu " << M << " den " << N << "," << endl;
        cout << "So gan voi " << target << " nhat la: " << closestPrime << endl;
    }

    return 0;
}
