#include <iostream>
using namespace std;

// --- Hàm GCD (phiên bản lặp) ---
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// --- Hàm LCM ---
long long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return 1LL * abs(a / gcd(a, b)) * abs(b); // tránh tràn số
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;

    cout << "Uoc chung lon nhat (GCD): " << gcd(a, b) << '\n';
    cout << "Boi chung nho nhat (LCM): " << lcm(a, b) << '\n';

    return 0;
}
