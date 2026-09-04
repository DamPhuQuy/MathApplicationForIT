#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Euclidean algorithm to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

// Extended Euclidean algorithm to find x and y such that ax + by = gcd(a, b)
void extended_gcd(int a, int b, int &gcd_val, int &x, int &y) {
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

// Chinese Remainder Theorem
pair<int, int> chinese_remainder_theorem(const vector<int>& a, const vector<int>& m) {
    int M = 1;
    for (int mod : m) {
        M *= mod;
    }
    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        int Mi = M / m[i];
        int gcd_value, xi, _; // We don't need y
        extended_gcd(Mi, m[i], gcd_value, xi, _);
        if (gcd_value != 1) {
            throw runtime_error("Không thể tìm nghiệm do gcd(Mi, mi) != 1");
        }
        result += a[i] * xi * Mi;
    }
    return make_pair(result % M, M);
}

int main() {
    int k;
    cout << "Nhập số lượng phương trình k: ";
    cin >> k;
    
    vector<int> a(k), m(k);
    for (int i = 0; i < k; ++i) {
        cout << "a" << i + 1 << " = ";
        cin >> a[i];
        cout << "m" << i + 1 << " = ";
        cin >> m[i];
    }
    
    try {
        pair<int, int> result = chinese_remainder_theorem(a, m); // Using explicit type declaration
        int x = result.first;  // Unpacking the pair
        int M = result.second;
        cout << "Nghiệm tổng quát là: x = " << x << " (mod " << M << ")" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
