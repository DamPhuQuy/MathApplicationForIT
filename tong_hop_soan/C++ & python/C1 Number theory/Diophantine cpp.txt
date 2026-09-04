#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void extended_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

void diophantine(int a, int b, int c) {
    int d = gcd(a, b);
    if (c % d != 0) {
        cout << "Phuong trinh khong ton tai nghiem nguyen!" << endl;
        return;
    }
    int x, y;
    extended_gcd(a, b, x, y);
    x *= c / d;
    y *= c / d;
    a /= d;
    b /= d;
    cout << "Nghiem nguyen tong quat x = " << x << " + " << b << "r" << endl;
    cout << "Nghiem nguyen tong quat y = " << y << " - " << a << "r" << endl;
}

int main() {
    int a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    diophantine(a, b, c);
    return 0;
}
