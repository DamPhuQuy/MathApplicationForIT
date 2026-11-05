#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n (>1): ";
    cin >> n;

    if (n <= 1) {
        cout << "n phai lon hon 1!";
        return 0;
    }

    cout << n << " = ";

    bool first = true;

    for (int i = 2; i * i <= n; i++) {
        int dem = 0;

        while (n % i == 0) {
            dem++;
            n /= i;
        }

        if (dem > 0) {
            if (!first) cout << " * ";
            cout << i << "^" << dem;
            first = false;
        }
    }

    if (n > 1) {
        if (!first) cout << " * ";
        cout << n << "^1";
    }

    return 0;
}
