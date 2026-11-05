#include <iostream>
#include <math.h>
using namespace std;

bool isPrime (int m) {
    if (m <= 1) return false;
    for (int i = 2; i <= sqrt(m); i++) {
        if (m % i == 0) return false;
    }
    return true;
}

void isPerfect1(int n) {
    if (n <= 1) cout << "n khong hop le!";
    else {
        int Tong = 1, m = n;
        int i = 2;
        int T[500], tong = 1;
        T[0] = 1;
        while (n > 1) {
            if (isPrime(i) && n % i == 0) {
                int j = 1, p = i;
                int old = tong;
                for (; n >= i && n % i == 0; j++) {
                    for (int h = 0; h < old; h++) {
                        T[tong++] = T[h] * p;
                        Tong += T[tong - 1];
                    }
                    n /= i;
                    p *= i;
                }
            }
            i ++;
        }

        if (Tong - m == m) cout << m << " la so hoan hao!\n";
        else cout << m << " khong phai la so hoan hao!\n";
    }
}

void isPerfect2(int n) {
    if (n <= 1) cout << "n khong hop le!";
    else {
        int m = n, o = 1;
        int i = 2;
        while (n > 1) {
            if (isPrime(i) && n % i == 0) {
                int j = 1, p = i;
                for (; n >= i && n % i == 0; j++) {
                    n /= i;
                    p *= i;
                }

                o *= (p - 1) / (i - 1);
            }
            i ++;
        }

        if (o - m == m) cout << m << " la so hoan hao!\n";
        else cout << m << " khong phai la so hoan hao!\n";
    }
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Chon cach xac dinh so hoan hao:\n";
    cout << "0. Dua vao liet ke uoc so\n1. Dua vao phan tich thua so nguyen to\n";
    cout << "Nhap lua chon: ";
    int choice;
    cin >> choice;
    if (choice == 1) isPerfect2(n);
    else isPerfect1(n);    
}

