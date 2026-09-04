
//int n;
//cin >> n;

//cout << (is_prime(n) ? "La so nguyen to!" : "Khong phai so nguyen to!") << endl;

//vector<int> p, e;
//prime_factorization(n, p, e);

//cout << n << " = ";
//for (size_t i = 0; i < p.size(); i++)
//    cout << p[i] << (e[i] > 1 ? "^" + to_string(e[i]) : "") << (i < p.size() - 1 ? "." : "");
//cout << endl;

//cout << "Tong cac uoc so: " << sum_factors(p, e) << endl;
//cout << "So uoc so: " << num_factors(e) << endl;

//vector<int> factors = factor_list(num_factors(e), p, e);
//for (int f : factors) cout << f << " ";
//cout << endl;

//cout << "Tich cac uoc so: " << prod_of_factors(n, num_factors(e)) << endl;

//vector<int> perfect_nums = perfect_numbers(n);
//if (!perfect_nums.empty()) {
//    for (int num : perfect_nums) cout << num << " ";
//}
//else cout << "Khong co so hoan hao nao.";
//cout << endl;

//return 0;


//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include<string>
//using namespace std;
//
//bool is_prime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i <= sqrt(n); i++)
//        if (n % i == 0) return false;
//    return true;
//}
//
//void prime_factorization(int n, vector<int>& p, vector<int>& e) {
//    for (int x = 2; x <= sqrt(n); x++) {
//        if (is_prime(x) && n % x == 0) {
//            int count = 0;
//            while (n % x == 0) n /= x, count++;
//            p.push_back(x), e.push_back(count);
//        }
//    }
//    if (n > 1) p.push_back(n), e.push_back(1);
//}
//
//int sum_factors(const vector<int>& p, const vector<int>& e) {
//    int sum = 1;
//    for (size_t i = 0; i < p.size(); i++)
//        sum *= (pow(p[i], e[i] + 1) - 1) / (p[i] - 1);
//    return sum;
//}
//
//int num_factors(const vector<int>& e) {
//    int num = 1;
//    for (int exp : e) num *= (exp + 1);
//    return num;
//}
//
//vector<int> factor_list(int num, const vector<int>& p, const vector<int>& e) {
//    vector<int> factors = { 1 }, temp(e.size(), 0);
//    for (int i = 1; i < num; i++) {
//        int factor = 1, j = e.size() - 1;
//        while (j >= 0 && temp[j] == e[j]) temp[j--] = 0;
//        if (j >= 0) temp[j]++;
//        for (size_t k = 0; k < p.size(); k++) factor *= pow(p[k], temp[k]);
//        factors.push_back(factor);
//    }
//    sort(factors.begin(), factors.end());
//    return factors;
//}
//
//int prod_of_factors(int n, int num) {
//    return pow(n, num / 2);
//}
//
//vector<int> perfect_numbers(int limit) {
//    vector<int> res;
//    for (int p = 2; p < limit; p++) {
//        int m = pow(2, p) - 1;
//        if (is_prime(m)) {
//            int perfect = pow(2, p - 1) * m;
//            if (perfect <= limit) res.push_back(perfect);
//            else break;
//        }
//    }
//    return res;
//}
//
//int main() {
//
//    int n;
//    cout << "Nhập một số nguyên n: ";
//    cin >> n;
//
//    // Kiểm tra số nguyên tố
//    cout << "Kiểm tra số nguyên tố: ";
//    cout << (is_prime(n) ? "Là số nguyên tố!" : "Không phải số nguyên tố!") << endl;
//
//    // Phân tích thừa số nguyên tố
//    vector<int> p, e;
//    prime_factorization(n, p, e);
//
//    cout << "Phân tích thừa số nguyên tố: ";
//    cout << n << " = ";
//    for (size_t i = 0; i < p.size(); i++)
//        cout << p[i] << (e[i] > 1 ? "^" + to_string(e[i]) : "") << (i < p.size() - 1 ? " . " : "");
//    cout << endl;
//
//    // Tính tổng các ước số
//    cout << "Tổng các ước số: ";
//    cout << sum_factors(p, e) << endl;
//
//    // Tính số lượng ước số
//    cout << "Số lượng ước số: ";
//    cout << num_factors(e) << endl;
//
//    // Liệt kê danh sách các ước số
//    cout << "Danh sách các ước số: ";
//    vector<int> factors = factor_list(num_factors(e), p, e);
//    for (int f : factors) cout << f << " ";
//    cout << endl;
//
//    // Tính tích các ước số
//    cout << "Tích các ước số: ";
//    cout << prod_of_factors(n, num_factors(e)) << endl;
//
//    // Tìm số hoàn hảo
//    cout << "Danh sách các số hoàn hảo nhỏ hơn hoặc bằng n: ";
//    vector<int> perfect_nums = perfect_numbers(n);
//    if (!perfect_nums.empty()) {
//        for (int num : perfect_nums) cout << num << " ";
//    }
//    else {
//        cout << "Không có số hoàn hảo nào.";
//    }
//    cout << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//bool is_prime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i <= sqrt(n); i++)
//        if (n % i == 0) return false;
//    return true;
//}
//
//void prime_factorization(int n, vector<int>& p, vector<int>& e) {
//    for (int x = 2; x <= sqrt(n); x++) {
//        if (is_prime(x) && n % x == 0) {
//            int count = 0;
//            while (n % x == 0) n /= x, count++;
//            p.push_back(x), e.push_back(count);
//        }
//    }
//    if (n > 1) p.push_back(n), e.push_back(1);
//}
//
//int sum_factors(const vector<int>& p, const vector<int>& e) {
//    int sum = 1;
//    for (size_t i = 0; i < p.size(); i++)
//        sum *= (pow(p[i], e[i] + 1) - 1) / (p[i] - 1);
//    return sum;
//}
//
//int num_factors(const vector<int>& e) {
//    int num = 1;
//    for (int exp : e) num *= (exp + 1);
//    return num;
//}
//
//vector<int> factor_list(int num, const vector<int>& p, const vector<int>& e) {
//    vector<int> factors = { 1 }, temp(e.size(), 0);
//    for (int i = 1; i < num; i++) {
//        int factor = 1, j = e.size() - 1;
//        while (j >= 0 && temp[j] == e[j]) temp[j--] = 0;
//        if (j >= 0) temp[j]++;
//        for (size_t k = 0; k < p.size(); k++) factor *= pow(p[k], temp[k]);
//        factors.push_back(factor);
//    }
//    sort(factors.begin(), factors.end());
//    return factors;
//}
//
//int prod_of_factors(int n, int num) {
//    return pow(n, num / 2);
//}
//
//vector<int> perfect_numbers(int limit) {
//    vector<int> res;
//    for (int p = 2; p < limit; p++) {
//        int m = pow(2, p) - 1;
//        if (is_prime(m)) {
//            int perfect = pow(2, p - 1) * m;
//            if (perfect <= limit) res.push_back(perfect);
//            else break;
//        }
//    }
//    return res;
//}
//
//bool is_perfect_number(int n) {
//    vector<int> p, e;
//    prime_factorization(n, p, e);
//    int sum = sum_factors(p, e) - n; // Tổng các ước số nhỏ hơn n
//    return sum == n;
//}
//
//int main() {
//    int n;
//    cout << "Nhập một số nguyên n: ";
//    cin >> n;
//
//    // Kiểm tra số nguyên tố
//    cout << "Kiểm tra số nguyên tố: ";
//    cout << (is_prime(n) ? "Là số nguyên tố!" : "Không phải số nguyên tố!") << endl;
//
//    // Phân tích thừa số nguyên tố
//    vector<int> p, e;
//    prime_factorization(n, p, e);
//
//    cout << "Phân tích thừa số nguyên tố: ";
//    cout << n << " = ";
//    for (size_t i = 0; i < p.size(); i++)
//        cout << p[i] << (e[i] > 1 ? "^" + to_string(e[i]) : "") << (i < p.size() - 1 ? " . " : "");
//    cout << endl;
//
//    // Tính tổng các ước số
//    cout << "Tổng các ước số: ";
//    cout << sum_factors(p, e) << endl;
//
//    // Tính số lượng ước số
//    cout << "Số lượng ước số: ";
//    cout << num_factors(e) << endl;
//
//    // Liệt kê danh sách các ước số
//    cout << "Danh sách các ước số: ";
//    vector<int> factors = factor_list(num_factors(e), p, e);
//    for (int f : factors) cout << f << " ";
//    cout << endl;
//
//    // Tính tích các ước số
//    cout << "Tích các ước số: ";
//    cout << prod_of_factors(n, num_factors(e)) << endl;
//
//    // Kiểm tra số hoàn hảo
//    cout << "Kiểm tra số hoàn hảo: ";
//    cout << (is_perfect_number(n) ? "Là số hoàn hảo!" : "Không phải số hoàn hảo!") << endl;
//
//    // Tìm số hoàn hảo
//    cout << "Danh sách các số hoàn hảo nhỏ hơn hoặc bằng n: ";
//    vector<int> perfect_nums = perfect_numbers(n);
//    if (!perfect_nums.empty()) {
//        for (int num : perfect_nums) cout << num << " ";
//    }
//    else {
//        cout << "Không có số hoàn hảo nào.";
//    }
//    cout << endl;
//
//    return 0;
//}


