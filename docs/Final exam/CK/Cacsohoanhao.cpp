#include <iostream>
#include <cmath>

using namespace std;

bool checkPerfectNumber(int n) {
    if (n <= 1) return false;

    int sum = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;

            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    return sum == n;
}

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    int count = 0;

    cout << "Cac so hoan hao be hon " << n << " la: ";

    for (int i = 2; i < n; i++) {
        if (checkPerfectNumber(i)) {
            cout << i << " ";
            count++;
        }
    }

    cout << "\nSo luong cac so hoan hao la: " << count << endl;

    return 0;
}