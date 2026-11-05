#include <iostream>
using namespace std;

// --- Chuẩn hóa giá trị về [0, m-1] ---
long long normalize(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// --- Cộng modulo ---
bool addMod(int x, int y, int m) {
    long long lhs = normalize(x + y, m);
    long long rhs = normalize(normalize(x, m) + normalize(y, m), m);
    cout << "(" << x << " + " << y << ") mod " << m << " = " << lhs << '\n';
    cout << "(" << x << " mod " << m << " + " << y << " mod " << m << ") mod " << m << " = " << rhs << '\n';
    return lhs == rhs;
}

// --- Trừ modulo ---
bool subMod(int x, int y, int m) {
    long long lhs = normalize(x - y, m);
    long long rhs = normalize(normalize(x, m) - normalize(y, m), m);
    cout << "(" << x << " - " << y << ") mod " << m << " = " << lhs << '\n';
    cout << "(" << x << " mod " << m << " - " << y << " mod " << m << ") mod " << m << " = " << rhs << '\n';
    return lhs == rhs;
}

// --- Nhân modulo ---
bool mulMod(int x, int y, int m) {
    long long lhs = normalize(1LL * x * y, m);
    long long rhs = normalize(normalize(x, m) * normalize(y, m), m);
    cout << "(" << x << " * " << y << ") mod " << m << " = " << lhs << '\n';
    cout << "(" << x << " mod " << m << " * " << y << " mod " << m << ") mod " << m << " = " << rhs << '\n';
    return lhs == rhs;
}

// --- Lũy thừa modulo nhanh O(log n) ---
long long modPow(long long x, int n, int m) {
    long long res = 1 % m;
    x = normalize(x, m);
    while (n > 0) {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

// --- Kiểm tra tính chất lũy thừa ---
bool expMod(int x, int n, int m) {
    long long normalPow = 1;
    for (int i = 0; i < n; ++i)
        normalPow = (normalPow * x) % m;
    long long fastPow = modPow(x, n, m);
    cout << x << "^" << n << " mod " << m << " = " << normalPow << '\n';
    cout << "(" << x << " mod " << m << ")^" << n << " mod " << m << " = " << fastPow << '\n';
    return normalPow == fastPow;
}

// --- Main ---
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int choice;
    cout << "=== KIEM TRA CAC TINH CHAT SO HOC MODULO ===\n";
    cout << "1. (x + y) mod m = (x mod m + y mod m) mod m\n";
    cout << "2. (x - y) mod m = (x mod m - y mod m) mod m\n";
    cout << "3. (x * y) mod m = (x mod m * y mod m) mod m\n";
    cout << "4. x^n mod m = (x mod m)^n mod m\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    int x, y, m, n;
    bool result = false;

    switch (choice) {
        case 1:
            cout << "Nhap x, y, m: ";
            cin >> x >> y >> m;
            result = addMod(x, y, m);
            break;
        case 2:
            cout << "Nhap x, y, m: ";
            cin >> x >> y >> m;
            result = subMod(x, y, m);
            break;
        case 3:
            cout << "Nhap x, y, m: ";
            cin >> x >> y >> m;
            result = mulMod(x, y, m);
            break;
        case 4:
            cout << "Nhap x, n, m: ";
            cin >> x >> n >> m;
            result = expMod(x, n, m);
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            return 0;
    }

    cout << (result ? "=> BANG NHAU " : "=> KHONG BANG NHAU ") << '\n';
    return 0;
}
