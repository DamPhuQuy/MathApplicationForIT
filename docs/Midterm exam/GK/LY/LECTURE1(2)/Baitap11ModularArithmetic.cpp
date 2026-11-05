#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long addMod(long long a, long long b, long long m) {
    return ((a % m) + (b % m)) % m;
}


long long subMod(long long a, long long b, long long m) {
    return ((a % m) - (b % m) + m) % m;
}


long long mulMod(long long a, long long b, long long m) {
    return ((a % m) * (b % m)) % m;
}

long long powerMod(long long base, long long exp, long long m) {
    long long res = 1;
    base = base % m; 
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % m; 
        }
        
        base = (base * base) % m; 
        exp = exp / 2;
    }
    return res;
}

int main() {
    long long a, b, n,m;
    cin>>a>>b>>m;
    
    cout << "Module m = " << m << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "(a + b) % m = " << addMod(a, b, m) << endl;
    cout << "(a - b) % m = " << subMod(a, b, m) << endl;
    cout << "(b - a) % m [10 - 75] = " << subMod(b, a, m) << endl;
    cout << "(a * b) % m = " << mulMod(a, b, m) << endl;
    long long coSo = 2;
    long long soMu = 10;
    cout << "(" << coSo << "^" << soMu << ") % " << m << " = " 
         << powerMod(coSo, soMu, m) << endl;

    return 0;
}