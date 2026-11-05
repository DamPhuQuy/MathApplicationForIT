#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Phân tích n thành tích các thừa số nguyên tố
void primeFactorization(int n) {
    cout << "\nPhan tich " << n << " ra thua so nguyen to:\n";
    cout << n << " = ";

    bool first = true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int exponent = 0;

            while (n % i == 0) {
                n /= i;
                exponent++;
            }

            if (!first) {
                cout << " * ";
            }

            cout << i;

            if (exponent > 1) {
                cout << "^" << exponent;
            }

            first = false;
        }
    }

    if (n > 1) {
        if (!first) {
            cout << " * ";
        }
        cout << n;
    }

    cout << endl;
}

// Liệt kê các số nguyên tố nhỏ hơn n và tính tổng
void listPrimeLessThanN(int n) {
    int sum = 0;
    int count = 0;

    cout << "\nCac so nguyen to nho hon " << n << " la:\n";

    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
            sum += i;
            count++;
        }
    }

    cout << "\nSo luong cac so nguyen to nho hon " << n << " la: " << count;
    cout << "\nTong cac so nguyen to nho hon " << n << " la: " << sum << endl;
}

int main() {
    int n1, n2;

    cout << "Nhap n de phan tich thua so nguyen to: ";
    cin >> n1;

    if (n1 <= 1) {
        cout << "n phai lon hon 1.\n";
        return 0;
    }

    primeFactorization(n1);

    cout << "\nNhap n de tim cac so nguyen to nho hon n: ";
    cin >> n2;

    if (n2 <= 1) {
        cout << "n phai lon hon 1.\n";
        return 0;
    }

    listPrimeLessThanN(n2);

    return 0;
}