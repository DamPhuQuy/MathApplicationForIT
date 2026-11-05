#include <iostream>
using namespace std;

// --- Hàm tính ước chung lớn nhất (Euclid) ---
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// --- Đếm số lượng các số nguyên tố cùng nhau với n ---
int countCoprime(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i)
        if (gcd(i, n) == 1)
            ++count;
    return count;
}

// --- Liệt kê các số nguyên tố cùng nhau với n ---
void listCoprime(int n) {
    for (int i = 1; i <= n; ++i)
        if (gcd(i, n) == 1)
            cout << i << " ";
}

// --- Kiểm tra một số cụ thể có cùng nhau với n hay không ---
void checkCoprime(int n, int x) {
    if (gcd(n, x) == 1)
        cout << x << " cung nhau voi " << n << '\n';
    else
        cout << x << " KHONG cung nhau voi " << n << '\n';
}

// --- Main ---
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Vui long nhap n > 0!\n";
        return 0;
    }

    cout << "So luong so nguyen to cung nhau voi " << n << ": " << countCoprime(n) << '\n';
    cout << "Danh sach cac so nguyen to cung nhau voi " << n << ":\n";
    listCoprime(n);
    cout << "\n\n";

    int x;
    cout << "Nhap mot so x de kiem tra cung nhau voi " << n << ": ";
    cin >> x;
    checkCoprime(n, x);

    return 0;
}
