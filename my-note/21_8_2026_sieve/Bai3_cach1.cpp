// Bài 3 - Cách 1: Euler’s totient function (Tìm số lượng số nguyên tố cùng nhau)
// Độ phức tạp: O(√n)

#include <iostream>
#include <vector>

using namespace std;

int timUCLN(int a, int b) {
    if (b == 0) return a;
    return timUCLN(b, a % b);
}

int tinhPhiEuler(int n) {
    int ketQua = n;
    int tam = n;
    for (int i = 2; i * i <= tam; i++) {
        if (tam % i == 0) {
            ketQua = ketQua - ketQua / i;
            while (tam % i == 0) tam /= i;
        }
    }
    if (tam > 1) ketQua = ketQua - ketQua / tam;
    return ketQua;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int phiN = tinhPhiEuler(n);
    if (phiN == n - 1 && n > 1) {
        cout << n << " la so nguyen to (Cach 2: Dung Totient Function)\n";
    } else {
        cout << n << " khong phai la so nguyen to\n";
    }

    cout << "So luong so nguyen to cung nhau (phi(n)): " << phiN << endl;
    cout << "Liet ke cac so do: ";
    for (int i = 1; i <= n; i++) {
        if (timUCLN(i, n) == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
