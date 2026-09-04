//#include <iostream>
//#include <vector>
//#include <stdexcept>
//using namespace std;
//
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = a;
//        a = b;
//        b = temp % b;
//    }
//    return a;
//}
//
//void extended_gcd(int a, int b, int& gcd_val, int& x, int& y) {
//    if (b == 0) {
//        gcd_val = a;
//        x = 1;
//        y = 0;
//        return;
//    }
//    int x1, y1;
//    extended_gcd(b, a % b, gcd_val, x1, y1);
//    x = y1;
//    y = x1 - (a / b) * y1;
//}
//
//pair<int, int> chinese_remainder_theorem(const vector<int>& a, const vector<int>& m) {
//    int M = 1, result = 0;
//    for (int mod : m) M *= mod;
//    for (size_t i = 0; i < a.size(); ++i) {
//        int Mi = M / m[i], gcd_value, xi, _;
//        extended_gcd(Mi, m[i], gcd_value, xi, _);
//        if (gcd_value != 1) throw runtime_error("Không thể tìm nghiệm do gcd(Mi, mi) != 1");
//        result += a[i] * xi * Mi;
//    }
//    return { result % M, M };
//}
//
//int main() {
//    int k;
//    cin >> k;
//    vector<int> a(k), m(k);
//    for (int i = 0; i < k; ++i) {
//        cin >> a[i] >> m[i];
//    }
//    try {
//        auto [x, M] = chinese_remainder_theorem(a, m);
//        cout << "x = " << x << " (mod " << M << ")" << endl;
//    }
//    catch (const runtime_error& e) {
//        cout << e.what() << endl;
//    }
//    return 0;
//}


#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

void extended_gcd(int a, int b, int& gcd_val, int& x, int& y) {
    if (b == 0) {
        gcd_val = a;
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extended_gcd(b, a % b, gcd_val, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

pair<int, int> chinese_remainder_theorem(const vector<int>& a, const vector<int>& m) {
    int M = 1, result = 0;
    for (int mod : m) M *= mod;
    for (size_t i = 0; i < a.size(); ++i) {
        int Mi = M / m[i], gcd_value, xi, _;
        extended_gcd(Mi, m[i], gcd_value, xi, _);
        if (gcd_value != 1) throw runtime_error("Không thể tìm nghiệm do gcd(Mi, mi) != 1");
        result += a[i] * xi * Mi;
    }
    return { result % M, M };
}

int main() {
    int k;
    cin >> k;
    vector<int> a(k), m(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i] >> m[i];
    }
    try {
        auto result = chinese_remainder_theorem(a, m);
        int x = result.first;
        int M = result.second;
        x = (x % M + M) % M;  // Đảm bảo x luôn không âm
        cout << "x = " << x << " (mod " << M << ")" << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}

