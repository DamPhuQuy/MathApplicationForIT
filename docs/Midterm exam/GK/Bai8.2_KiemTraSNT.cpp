#include <iostream>
#include <math.h>
using namespace std;

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

bool isCoprime (int a, int b) {
    int ucln;
    if (a < b) ucln = UCLN(b, a);
    else ucln = UCLN(a, b);
    if (ucln == 1) return true;
    else return false;
}

bool isPrime1(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrime2(int n) {
    int num = 1;
    for (int i = 2; i < n; i++) {
        if (isCoprime(n, i)) num++; 
    }

    if (num == n - 1) return true;
    return false;
}

int main() {
    cout << "n = ";
    int n;
    cin >> n;
    cout << "1. Tim uoc cua n tu 2...n - 1" << endl;
    cout << "2. Tim so luong so nguyen to cung nhau voi m" << endl;
    cout << "Chon cach de kiem tra n co la prime hay khong: ";
    int choice;
    bool check;
    cin >> choice;
    if (choice == 1) check = isPrime1(n);
    else check = isPrime1(n);
    if (check) cout << n << " la so nguyen to" << endl;
    else cout << n << " khong phai la so nguyen to" << endl;
}