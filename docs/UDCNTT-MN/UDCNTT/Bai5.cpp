#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    
    if (n <= 1) {
        cout << "n khong hop le! (n phai lon hon 1)\n";
    } else {
        // Sử dụng định lý số nguyên tố để ước lượng
        double uocLuong = n / log(n);
        cout << "So luong so nguyen to < " << n << " (uoc luong): ";
        cout << (int)uocLuong << endl;
        
        // Hiển thị thêm thông tin
        cout << "\nThong tin them:\n";
        cout << "- n/log(n) = " << uocLuong << endl;
        cout << "- Lam tron xuong: " << (int)uocLuong << endl;
        cout << "\n(Luu y: Day chi la uoc luong theo dinh ly so nguyen to)\n";
        cout << "(Gia tri thuc te co the khac biet)\n";
    }
    
    return 0;
}