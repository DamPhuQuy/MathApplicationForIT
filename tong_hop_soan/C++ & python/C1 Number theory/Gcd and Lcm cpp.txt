#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool is_coprime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (is_coprime(a, b)) {
        cout << "a va b la so nguyen to cung nhau" << endl;
    } else {
        cout << "a va b khong la so nguyen to cung nhau" << endl;
    }

    cout << "Gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    cout << "Lcm(" << a << ", " << b << ") = " << lcm(a, b) << endl;

    return 0;
}
