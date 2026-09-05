// Bài 2: Viết chương trình thực hiện thuật toán Euclid (Tìm GCD, LCM)
// Độ phức tạp: O(log n)

#include <iostream>

using namespace std;

long long Euclid_GCD(long long a, long long b) {
    if (b == 0) return a;
    return Euclid_GCD(b, a % b);
}

long long Euclid_LCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / Euclid_GCD(a, b);
}

int main() {
    long long a, b;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;

    long long ucln = Euclid_GCD(a, b);
    long long bcnn = Euclid_LCM(a, b);

    cout << "Uoc chung lon nhat (GCD) theo Euclid: " << ucln << endl;
    cout << "Boi chung nho nhat (LCM) theo Euclid: " << bcnn << endl;

    return 0;
}
