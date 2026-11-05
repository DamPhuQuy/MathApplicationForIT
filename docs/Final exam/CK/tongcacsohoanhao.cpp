#include <iostream>
using namespace std;

// Hàm kiểm tra số hoàn hảo
bool isPerfect(int n) {
    if (n <= 1) return false;
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum == n;
}

int main() {
    int M;
    cout << "Nhap so M: ";
    cin >> M;
    
    long long sumPerfect = 0;
    int countPerfect = 0;
    
    cout << "Cac so hoan hao nho hon " << M << " la:\n";
    
    for (int i = 2; i < M; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
            sumPerfect += i;
            countPerfect++;
        }
    }
    
    cout << "\n\nSo luong cac so hoan hao nho hon " << M << " la: " << countPerfect;
    cout << "\nTong cua cac so hoan hao do la: " << sumPerfect << "\n";
    
    return 0;
}
