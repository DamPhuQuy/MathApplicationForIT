#include <iostream>

using namespace std;
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solveDiophantine(long long a, long long b, long long c) {
    long long x0, y0;
    long long g = extendedGCD(a, b, x0, y0); // Giải a*x0 + b*y0 = g

    if (c % g != 0) {
        cout << "Phuong trinh vo nghiem!" << endl;
    } else {
        long long k = c / g;
        long long x = x0 * k;
        long long y = y0 * k;
        
        cout << "Phuong trinh: " << a << "x + " << b << "y = " << c << endl;
        cout << "Mot nghiem rieng: x = " << x << ", y = " << y << endl;
        
        cout << "Nghiem tong quat (k thuoc Z):" << endl;
        cout << "x = " << x << " + k*" << (b / g) << endl;
        cout << "y = " << y << " - k*" << (a / g) << endl;
    }
}

int main() {
    long long a, b, c;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;

    solveDiophantine(a, b, c);
    
    return 0;
}