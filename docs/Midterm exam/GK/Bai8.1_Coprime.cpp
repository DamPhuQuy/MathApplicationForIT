#include <iostream>
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

int main() {
    cout << "n = ";
    int n;
    cin >> n;
    if (n < 1) cout << "n khong hop le!\n";
    else {
        cout << "Cac so nguyen to cung nhau voi n trong khoang tu 1..n la:" << endl;
        for (int i = 1; i < n; i++) {
            if (isCoprime(n, i)) cout << i << " ";
        }
    }    
}