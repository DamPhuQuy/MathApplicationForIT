//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//// Hàm kiểm tra số hoàn hảo
//bool is_perfect(int num) {
//    int sum = 1; // Tổng các ước của num, bắt đầu từ 1
//    for (int i = 2; i <= num / 2; i++) {
//        if (num % i == 0) {
//            sum += i;
//        }
//    }
//    return sum == num;
//}
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
//// Hàm tìm số nguyên tố gần nhất với một số cho trước
//int find_closest_prime(int value) {
//    int lower = value - 1; // Bắt đầu từ số nhỏ hơn value
//    int upper = value + 1; // Bắt đầu từ số lớn hơn value
//
//    while (lower > 1 && !is_prime(lower)) lower--;
//    while (!is_prime(upper)) upper++;
//
//    return (value - lower <= upper - value) ? lower : upper;
//}
//
//int main() {
//    const int N = 9000;
//
//    vector<int> perfect_numbers; // Danh sách các số hoàn hảo
//
//    // Tìm các số hoàn hảo nhỏ hơn N
//    for (int i = 2; i < N; i++) {
//        if (is_perfect(i)) {
//            perfect_numbers.push_back(i);
//        }
//    }
//
//    // Liệt kê và đếm các số hoàn hảo
//    cout << "Cac so hoan hao nho hon " << N << ": ";
//    for (int num : perfect_numbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    cout << "So luong so hoan hao: " << perfect_numbers.size() << endl;
//
//    // Tìm số hoàn hảo lớn nhất
//    int M = perfect_numbers.empty() ? -1 : perfect_numbers.back();
//    if (M != -1) {
//        cout << "So hoan hao lon nhat: " << M << endl;
//
//        // Tìm số nguyên tố gần nhất với M
//        int closest_prime = find_closest_prime(M);
//        cout << "So nguyen to gan nhat voi " << M << " la: " << closest_prime << endl;
//    }
//    else {
//        cout << "Khong co so hoan hao nao!" << endl;
//    }
//
//    return 0;
//}
