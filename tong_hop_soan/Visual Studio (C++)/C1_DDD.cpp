//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//// Hàm kiểm tra số nguyên tố
//bool is_prime(int num) {
//    if (num < 2) return false;
//    for (int i = 2; i <= sqrt(num); i++) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//
//// Hàm tìm số nguyên tố gần nhất với target, không tính target
//int find_closest_prime(int target) {
//    int lower = target - 1; // Bắt đầu từ số nhỏ hơn target
//    int upper = target + 1; // Bắt đầu từ số lớn hơn target
//
//    while (lower > 1 && !is_prime(lower)) lower--;
//    while (!is_prime(upper)) upper++;
//
//    return (target - lower <= upper - target) ? lower : upper;
//}
//
//int main() {
//    const int N = 499;
//
//    vector<int> primes; // Danh sách các số nguyên tố nhỏ hơn N
//    int sum = 0; // Tổng các số nguyên tố
//
//    // Tìm các số nguyên tố nhỏ hơn N   // nếu bằng nữa thì thêm dấu bằng vào
//    for (int i = 2; i <N; i++) {
//        if (is_prime(i)) {
//            primes.push_back(i);
//            sum += i;
//        }
//    }
//
//    // Liệt kê các số nguyên tố
//    cout << "Cac so nguyen to nho hon " << N << ": ";
//    for (int prime : primes) {
//        cout << prime << " ";
//    }
//    cout << endl;
//
//    // Tổng các số nguyên tố
//    cout << "Tong cac so nguyen to: " << sum << endl;
//    cout << "So luong cac so nguyen to: " << primes.size() << endl;
//
//    // Tìm số nguyên tố gần nhất với N
//    int closest_prime = find_closest_prime(N);
//    cout << "So nguyen to gan nhat voi " << N << " la: " << closest_prime << endl;
//
//    return 0;
//}
