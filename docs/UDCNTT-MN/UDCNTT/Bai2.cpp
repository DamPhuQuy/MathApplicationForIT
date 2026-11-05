#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int so) {
    if (so <= 1) return false;
    if (so == 2) return true;
    if (so % 2 == 0) return false;
    
    int gioiHan = (int)sqrt(so);
    for (int i = 3; i <= gioiHan; i += 2) {
        if (so % i == 0) return false;
    }
    return true;
}

// Hàm liệt kê các tổ hợp mũ (các ước số)
void lietKeCacUoc(int n) {
    cout << "Cac to hop mu la:\n";
    cout << "1 ";
    
    int danhSachUoc[500];
    int soLuongUoc = 1;
    danhSachUoc[0] = 1;
    
    int soHienTai = 2;
    int soBanDau = n;
    
    while (soBanDau > 1) {
        if (laSoNguyenTo(soHienTai) && soBanDau % soHienTai == 0) {
            int soMu = 1;
            int luyThua = soHienTai;
            int soUocBanDau = soLuongUoc;
            
            while (soBanDau >= soHienTai && soBanDau % soHienTai == 0) {
                // Nhân tất cả ước hiện có với lũy thừa hiện tại
                for (int i = 0; i < soUocBanDau; i++) {
                    danhSachUoc[soLuongUoc] = danhSachUoc[i] * luyThua;
                    cout << danhSachUoc[soLuongUoc] << " ";
                    soLuongUoc++;
                }
                
                soBanDau /= soHienTai;
                luyThua *= soHienTai;
                soMu++;
            }
        }
        soHienTai++;
    }
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    
    if (n <= 1) {
        cout << "n khong hop le!";
    } else {
        lietKeCacUoc(n);
    }
    
    return 0;
}