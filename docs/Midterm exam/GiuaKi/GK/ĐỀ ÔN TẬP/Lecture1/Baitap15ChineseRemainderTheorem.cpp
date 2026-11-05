#include <iostream>

using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGCD(a, m, x, y);
    if (g != 1) return -1; 
    return (x % m + m) % m; 
}

long long chineseRemainderTheorem(int n, long long a[], long long m[]) {
    long long M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long Xi = M / m[i];
        long long Yi = modInverse(Xi, m[i]); 
        result = (result + a[i] * Xi * Yi) % M;
    }
    return result;
}

int main() {
    int n = 3; 
    long long a[] = {3, 4, 2}; 
    long long m[] = {5, 7, 3}; 

    cout << "He phuong trinh:" << endl;
    for(int i=0; i<n; i++) {
        cout << "x = " << a[i] << " mod " << m[i] << endl;
    }

    long long x = chineseRemainderTheorem(n, a, m);
    cout << "Ket qua x = " << x << endl;

    return 0;
}