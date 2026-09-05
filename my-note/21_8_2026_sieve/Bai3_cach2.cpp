// Bài 3 - Cách 2: Kiểm tra có chia cho 1 và chính nó không
// Độ phức tạp: O(n log n)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int timUCLN(int a, int b) {
    while (b != 0) {
        int tam = a % b;
        a = b;
        b = tam;
    }
    return a;
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (laSoNguyenTo(n)) {
        cout << n << " la so nguyen to (Cach 1: Kiem tra chia het)\n";
    } else {
        cout << n << " khong phai la so nguyen to\n";
    }

    vector<int> danhSach;
    for (int i = 1; i <= n; i++) {
        if (timUCLN(i, n) == 1) {
            danhSach.push_back(i);
        }
    }

    cout << "Co " << danhSach.size() << " so nguyen to cung nhau voi " << n << " la: ";
    for (int x : danhSach) cout << x << " ";
    cout << endl;

    return 0;
}
