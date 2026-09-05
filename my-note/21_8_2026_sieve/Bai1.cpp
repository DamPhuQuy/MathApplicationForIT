// Bài 1: Nhập n và liệt kê các số nguyên tố từ 2 đến n và từ a đến b.
// Độ phức tạp: O(n log(log n))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> layDanhSachSoNguyenTo(int batDau, int ketThuc) {
    if (ketThuc < 2) return {};

    vector<int> mangSang(ketThuc + 1, 0);
    for (int x = 2; x <= ketThuc; x++) {
        if (mangSang[x]) continue;
        for (int u = 2 * x; u <= ketThuc; u += x) {
            mangSang[u] = x;
        }
    }

    vector<int> ketQua;
    int batDauThucTe = max(batDau, 2);
    for (int i = batDauThucTe; i <= ketThuc; i++) {
        if (mangSang[i] == 0) {
            ketQua.push_back(i);
        }
    }
    return ketQua;
}

int main() {
    int n, a, b;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Cac so nguyen to tu 2 den n la: \n";
    for (int so : layDanhSachSoNguyenTo(2, n)) {
        cout << so << " ";
    }
    cout << endl;

    cout << "Nhap a va b: ";
    cin >> a >> b;
    cout << "Cac so nguyen to tu a den b la: \n";
    for (int so : layDanhSachSoNguyenTo(a, b)) {
        cout << so << " ";
    }
    cout << endl;

    return 0;
}
