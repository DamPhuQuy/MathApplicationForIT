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
//// Hàm tìm số gần nhất với giá trị target trong một vector
//int find_closest(const vector<int>& nums, int target) {
//    int closest = nums[0];
//    int min_diff = abs(nums[0] - target);
//
//    for (int num : nums) {
//        int diff = abs(num - target);
//        if (diff < min_diff) {
//            closest = num;
//            min_diff = diff;
//        }
//    }
//    return closest;
//}
//
//int main() {
//    const int M = 1;
//    const int N = 50;
//    const int target = 37;
//
//    vector<int> primes; // Danh sách các số nguyên tố trong khoảng [M, N]
//    int sum = 0; // Tổng các số nguyên tố
//
//    // Tìm các số nguyên tố trong khoảng [M, N]
//    for (int i = M; i <= N; i++) {
//        if (is_prime(i)) {
//            primes.push_back(i);
//            sum += i;
//        }
//    }
//
//    // In các số nguyên tố và tổng của chúng
//    cout << "Cac so nguyen to trong khoang [" << M << ", " << N << "]: ";
//    for (int prime : primes) {
//        cout << prime << " ";
//    }
//    cout << endl;
//
//    cout << "Tong cac so nguyen to: " << sum << endl;
//    cout << "So luong cac so nguyen to: " << primes.size() << endl;
//
//    // Tìm số gần nhất với 300
//    if (!primes.empty()) {
//        int closest = find_closest(primes, target);
//        cout << "So nguyen to gan nhat voi " << target << " la: " << closest << endl;
//    }
//    else {
//        cout << "Khong co so nguyen to nao trong khoang!" << endl;
//    }
//
//    return 0;
//}


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
//// Hàm tìm số gần nhất với giá trị target trong một vector, không tính target
//int find_closest(const vector<int>& nums, int target) {
//    int closest = -1; // Giá trị mặc định
//    int min_diff = INT_MAX;
//
//    for (int num : nums) {
//        if (num == target) continue; // Bỏ qua chính số target
//        int diff = abs(num - target);
//        if (diff < min_diff) {
//            closest = num;
//            min_diff = diff;
//        }
//    }
//    return closest;
//}
//
//int main() {
//    const int M = 1;
//    const int N = 50;
//    const int target = 37;
//
//    vector<int> primes; // Danh sách các số nguyên tố trong khoảng [M, N]
//    int sum = 0; // Tổng các số nguyên tố
//
//    // Tìm các số nguyên tố trong khoảng [M, N]
//    for (int i = M; i <= N; i++) {
//        if (is_prime(i)) {
//            primes.push_back(i);
//            sum += i;
//        }
//    }
//
//    // In các số nguyên tố và tổng của chúng
//    cout << "Cac so nguyen to trong khoang [" << M << ", " << N << "]: ";
//    for (int prime : primes) {
//        cout << prime << " ";
//    }
//    cout << endl;
//
//    cout << "Tong cac so nguyen to: " << sum << endl;
//    cout << "So luong cac so nguyen to: " << primes.size() << endl;
//
//    // Tìm số gần nhất với target
//    if (!primes.empty()) {
//        int closest = find_closest(primes, target);
//        if (closest != -1) {
//            cout << "So nguyen to gan nhat voi " << target << " la: " << closest << endl;
//        }
//        else {
//            cout << "Khong tim thay so nguyen to nao gan nhat voi " << target << " ma khac chinh no!" << endl;
//        }
//    }
//    else {
//        cout << "Khong co so nguyen to nao trong khoang!" << endl;
//    }
//
//    return 0;
//}
