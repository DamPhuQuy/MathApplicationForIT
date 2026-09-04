//#include <iostream>
//#include <vector>
//#include <numeric> // For std::gcd
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
//int main() {
//    int N;
//    cout << "Nhap N: ";
//    cin >> N;
//
//    vector<int> M; // Tập M chứa các số nguyên tố cùng nhau với N
//    for (int i = 2; i < 500; i++) {
//        if (gcd(i, N) == 1) {
//            M.push_back(i);
//        }
//    }
//
//    vector<int> perfect_numbers; // Lưu các số hoàn hảo trong M
//    int total_sum = 0; // Tổng các số hoàn hảo
//
//    for (int m : M) {
//        if (is_perfect(m)) {
//            perfect_numbers.push_back(m);
//            total_sum += m;
//        }
//    }
//
//    // Kết quả
//    cout << "Cac so hoan hao trong M: ";
//    for (int num : perfect_numbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    cout << "Tong cac so hoan hao: " << total_sum << endl;
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//// Hàm tính GCD theo thuật toán Euclid
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
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
//int main() {
//    int N;
//    cout << "Nhap N: ";
//    cin >> N;
//
//    vector<int> M; // Tập M chứa các số nguyên tố cùng nhau với N
//    for (int i = 2; i < 500; i++) {
//        if (gcd(i, N) == 1) {
//            M.push_back(i);
//        }
//    }
//
//    vector<int> perfect_numbers; // Lưu các số hoàn hảo trong M
//    int total_sum = 0; // Tổng các số hoàn hảo
//
//    for (int m : M) {
//        if (is_perfect(m)) {
//            perfect_numbers.push_back(m);
//            total_sum += m;
//        }
//    }
//
//    // Kết quả
//    cout << "Cac so hoan hao trong M: ";
//    for (int num : perfect_numbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    cout << "Tong cac so hoan hao: " << total_sum << endl;
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//// Hàm tính GCD theo thuật toán Euclid
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
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
//int main() {
//    int N;
//    cout << "Nhap N: ";
//    cin >> N;
//
//    vector<int> M; // Tập M chứa các số nguyên tố cùng nhau với N
//    for (int i = 2; i < 500; i++) {
//        if (gcd(i, N) == 1) {
//            M.push_back(i);
//        }
//    }
//
//    // In tập M
//    cout << "Tap M (cac so nguyen to cung nhau voi " << N << "): ";
//    for (int m : M) {
//        cout << m << " ";
//    }
//    cout << endl;
//
//    vector<int> perfect_numbers; // Lưu các số hoàn hảo trong M
//    int total_sum = 0; // Tổng các số hoàn hảo
//
//    for (int m : M) {
//        if (is_perfect(m)) {
//            perfect_numbers.push_back(m);
//            total_sum += m;
//        }
//    }
//
//    // Kết quả
//    cout << "Cac so hoan hao trong M: ";
//    for (int num : perfect_numbers) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    cout << "Tong cac so hoan hao: " << total_sum << endl;
//
//    return 0;
//}

