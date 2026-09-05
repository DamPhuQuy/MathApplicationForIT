// Bài 4: Kiểm tra tính đúng đắn của Modular arithmetic.

#include <iostream>
#include <string>

using namespace std;

void inKetQua(string bieuThuc, long long v1, long long v2) {
    cout << bieuThuc << endl;
    cout << "Gia tri truc tiep: " << v1 << endl;
    cout << "Gia tri qua modulo tung phan: " << v2 << endl;
    cout << (v1 == v2 ? "KET QUA: BANG NHAU" : " KET QUA: KHONG BANG NHAU") << endl;
}

long long luyThuaNhanh(long long x, long long n, long long m) {
    long long res = 1 % m;
    x %= m;
    while (n > 0) {
        if (n % 2 == 1) res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int main() {
    int luaChon;
    do {
        cout << "\n---KIEM TRA TINH CHAT MODULO--- \n";
        cout << "1. Phep cong\n2. Phep tru\n3. Phep nhan\n4. Luy thua nhanh O(log n)\n0. Thoat\nChon: ";
        cin >> luaChon;

        if (luaChon == 0) break;

        long long x, y, n, m;
        if (luaChon >= 1 && luaChon <= 3) {
            cout << "Nhap x, y, m: ";
            cin >> x >> y >> m;
        } else if (luaChon == 4) {
            cout << "Nhap x, n, m: ";
            cin >> x >> n >> m;
        }

        switch (luaChon) {
            case 1:
                inKetQua("(x + y) % m", (x + y) % m, (x % m + y % m) % m);
                break;
            case 2:
                inKetQua("(x - y) % m", (x - y) % m, (x % m - y % m + m) % m);
                break;
            case 3:
                inKetQua("(x * y) % m", (x * y) % m, (x % m * (y % m)) % m);
                break;
            case 4: {
                long long ttt = 1;
                for (int i = 0; i < n; i++) ttt = (ttt * x) % m;
                inKetQua("x^n % m", ttt, luyThuaNhanh(x, n, m));
                break;
            }
        }
    } while (luaChon != 0);

    return 0;
}
