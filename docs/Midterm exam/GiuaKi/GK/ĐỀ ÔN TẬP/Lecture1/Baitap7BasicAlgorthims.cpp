#include <iostream>
#include <cmath>

using namespace std;

// Độ phức tạp: O(sqrt(N))
bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}

void printPrimeFactors(int n) {
    cout << n << " = ";
    
    bool first = true; 

    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            if (!first) cout << " * ";
            cout << x;
            first = false;
            
            n /= x; 
        }
    }
    if (n > 1) {
        if (!first) cout << " * ";
        cout << n;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " la so nguyen to." << endl;
        cout << "Phan tich: " << n << " = " << n << endl;
    } else {
        cout << n << " khong phai la so nguyen to." << endl;
        cout << "Phan tich thua so: ";
        printPrimeFactors(n);
    }

    return 0;
}