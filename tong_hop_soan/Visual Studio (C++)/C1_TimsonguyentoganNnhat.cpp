//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool check_prime(int num) {
//    if (num < 2) return false;
//    for (int i = 2; i <= sqrt(num); i++) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//
//int find_closest_prime(int value) {
//    int lower = value, upper = value;
//
//    while (lower > 1 && !check_prime(lower)) lower--;
//    while (!check_prime(upper)) upper++;
//
//    return (value - lower <= upper - value) ? lower : upper;
//}
//
//int main() {
//    int number;
//    cout << "Nhap N: ";
//    cin >> number;
//
//    int result = find_closest_prime(number);
//    cout << "So nguyen to gan nhat cua " << number << " la: " << result << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool check_prime(int num) {
//    if (num < 2) return false;
//    for (int i = 2; i <= sqrt(num); i++) {
//        if (num % i == 0) return false;
//    }
//    return true;
//}
//
//int find_closest_prime(int value) {
//    int lower = value - 1; // Bắt đầu từ giá trị nhỏ hơn value
//    int upper = value + 1; // Bắt đầu từ giá trị lớn hơn value
//
//    while (lower > 1 && !check_prime(lower)) lower--;
//    while (!check_prime(upper)) upper++;
//
//    if (value - lower < upper - value) {
//        return lower;
//    }
//    else {
//        return upper;
//    }
//}
//
//int main() {
//    int number;
//    cout << "Nhap N: ";
//    cin >> number;
//
//    int result = find_closest_prime(number);
//    cout << "So nguyen to gan nhat cua " << number << " la: " << result << endl;
//
//    return 0;
//}
