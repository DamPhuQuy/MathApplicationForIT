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

int FmodPow(int x, int n, int m) {
    n %= (m - 1);
    if (n == 0) return 1 % m;
    long u = FmodPow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

bool isCondition(int A[], int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < i; j++) {
            if (!isCoprime(A[i], A[j])) return false;
        }
    }
    return true;
}

int extend_UCLN(int& x, int& y, int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int result = extend_UCLN(x, y, b, a % b);

    int _x = x, _y = y;
    x = _y;
    y = _x - (a / b) * _y;

    return result;
}

int modularInverse(int a, int m) {
    int x, y;
    int g = extend_UCLN(x, y, a, m);
    if (g == 1) return (x % m + m) % m;
    return -1;
}

int main() {
    cout << "Nhap so luong dieu kien (n >= 1): ";
    int n;
    cin >> n;
    if (n < 1) cout << "n khong hop le" << endl;
    else {
        int A[n + 1], M[n + 1], mul = 1, nghiem = 0;
        for (int i = 1; i <= n; i++) {
            cout << "a" << i << " = ";
            cin >> A[i];
            cout << "m" << i << " = ";
            cin >> M[i];
            mul *= M[i];
        }

        if (isCondition(M, n)) {
            for (int i = 1; i <= n; i++) {
                int Mi = mul / M[i];
                int yi = modularInverse(Mi, M[i]);
                if (yi == -1) {
                    cout << "Khong ton tai nghich dao!" << endl;
                    return 0;
                }
                nghiem += A[i] * Mi * yi;
            }

            cout << "x = " << nghiem / mul << "k " << " + " << nghiem % mul << endl;
        }
        else {
            cout << "mi khong hop le" << endl;
        }
    }
}