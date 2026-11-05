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

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 1) cout << "n khong hop le!";
    else {
        cout << "Cac to hop mu la:\n";
        cout << "1 ";
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
                        cout << T[tong - 1] << " ";
                    }
                    n /= i;
                    p *= i;
                }
            }
            i ++;
        }
    }
}