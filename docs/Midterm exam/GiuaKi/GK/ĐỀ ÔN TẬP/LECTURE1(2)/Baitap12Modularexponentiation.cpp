#include <iostream>
//x^n mod m
using namespace std;
//Độ phức tạp: O(log n)
long long modPow(long long x, long long n, long long m) {
    if (n == 0) {
        return 1 % m; 
    }

    long long u = modPow(x, n / 2, m);

    u = (u * u) % m;

    if (n % 2 == 1) {
        u = (u * x) % m;
    }

    return u;
}

int main() {
    long long x, n, m;
    cout << "Nhap co so (x): ";
    cin >> x;
    cout << "Nhap so mu (n): ";
    cin >> n;
    cout << "Nhap module (m): ";
    cin >> m;
    long long result = modPow(x, n, m);

    cout << x << "^" << n << " mod " << m << " = " << result << endl;

    return 0;
}