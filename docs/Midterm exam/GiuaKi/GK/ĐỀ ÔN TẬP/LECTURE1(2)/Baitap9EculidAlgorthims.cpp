#include <iostream>
//Tìm ước chung lớn nhất và bội chung nhỏ nhất
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0; 
    long long ucln = gcd(a, b);
    return (a / ucln) * b;
}

int main() {
    long long a, b;
    cout << "Nhap so thu nhat (a): ";
    cin >> a;
    cout << "Nhap so thu hai (b): ";
    cin >> b;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long ucln = gcd(a, b);
    long long bcnn = lcm(a, b);

    cout << "--- Ket qua ---" << endl;
    cout << "Uoc chung lon nhat (GCD) cua " << a << " va " << b << " la: " << ucln << endl;
    cout << "Boi chung nho nhat (LCM) cua " << a << " va " << b << " la: " << bcnn << endl;

    return 0;
}