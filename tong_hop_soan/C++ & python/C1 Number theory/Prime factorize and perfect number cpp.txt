#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime_factorization(int n, vector<int>& p, vector<int>& e) {
    for (int x = 2; x <= sqrt(n); x++) {
        if (is_prime(x)) {
            if (n % x == 0) {
                int count = 0;
                while (n % x == 0) {
                    n /= x;
                    count++;
                }
                p.push_back(x);
                e.push_back(count);
            }
        }
    }
    if (n > 1) {
        p.push_back(n);
        e.push_back(1);
    }
}

int sum_factors(const vector<int>& p, const vector<int>& e) {
    int total_sum = 1;
    for (size_t i = 0; i < p.size(); i++) {
        total_sum *= (pow(p[i], e[i] + 1) - 1) / (p[i] - 1);
    }
    return total_sum;
}

int num_factors(const vector<int>& e) {
    int num_of_factors = 1;
    for (int exp : e) {
        num_of_factors *= (exp + 1);
    }
    return num_of_factors;
}

vector<int> factor_list(int num_of_factors, const vector<int>& p, const vector<int>& e) {
    vector<int> factors = {1};
    vector<int> temp_expo(e.size(), 0);
    for (int i = 1; i < num_of_factors; i++) {
        int factor = 1;
        int j = e.size() - 1;
        while (j >= 0 && temp_expo[j] == e[j]) {
            temp_expo[j] = 0;
            j--;
        }
        if (j >= 0) {
            temp_expo[j]++;
        }
        for (size_t k = 0; k < p.size(); k++) {
            factor *= pow(p[k], temp_expo[k]);
        }
        factors.push_back(factor);
    }
    sort(factors.begin(), factors.end());
    return factors;
}

int prod_of_factors(int n, int num_of_factors) {
    return pow(n, num_of_factors / 2);
}

vector<int> perfect_numbers(int limit) {
    vector<int> perfect_nums;
    for (int p = 2; p < limit; p++) {
        int mersenne_prime = pow(2, p) - 1;
        if (is_prime(mersenne_prime)) {
            int perfect_num = pow(2, p - 1) * mersenne_prime;
            if (perfect_num <= limit) {
                perfect_nums.push_back(perfect_num);
            } else {
                break;
            }
        }
    }
    return perfect_nums;
}

int main() {
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;

    if (is_prime(n)) {
        cout << "La so nguyen to!" << endl;
    } else {
        cout << "Khong phai so nguyen to!" << endl;
    }

    vector<int> p, e;
    prime_factorization(n, p, e);

    cout << "Tich cac thua so nguyen to cua " << n << ": " << n << " = ";
    for (size_t i = 0; i < p.size(); i++) {
        cout << p[i];
        if (e[i] > 1) {
            cout << "^" << e[i];
        }
        if (i < p.size() - 1) {
            cout << ".";
        }
    }
    cout << endl;

    int sum_of_factors = sum_factors(p, e);
    cout << "Tong cac uoc so cua " << n << " la: " << sum_of_factors << endl;

    int num = num_factors(e);
    cout << "So uoc so cua " << n << " la: " << num << endl;

    vector<int> factors = factor_list(num, p, e);
    cout << "Cac uoc so cua " << n << " la: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    int prod = prod_of_factors(n, num);
    cout << "Tich cac uoc so cua " << n << " la: " << prod << endl;

    vector<int> perfect_nums = perfect_numbers(n);
    if (!perfect_nums.empty()) {
        cout << "Cac so hoan hao nho hon hoac bang " << n << " la: ";
        for (int perfect_num : perfect_nums) {
            cout << perfect_num << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co so hoan hao nao nho hon hoac bang " << n << "." << endl;
    }

    return 0;
}
