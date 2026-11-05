#include <iostream>
using namespace std;

// Hàm tính lũy thừa nhị phân: (base^exp) % m
long long powerMod(long long base, long long exp, long long m) {
    long long res = 1;
    base = base % m;
    
    while (exp > 0) {
        // Nếu exp là số lẻ, nhân base vào kết quả
        if (exp % 2 == 1) {
            res = (res * base) % m;
        }
        // exp = exp / 2
        exp = exp >> 1; 
        // base = base^2
        base = (base * base) % m;
    }
    return res;
}

// Hàm tính f(n) % m
long long fibMod(long long n, long long m) {
    if (n == 0) return 0;
    if (n == 1) return 1 % m;
    
    long long f0 = 0;
    long long f1 = 1 % m;
    long long fn;
    
    for (long long i = 2; i <= n; ++i) {
        fn = (f0 + f1) % m;
        f0 = f1;
        f1 = fn;
    }
    
    return fn;
}

// Hàm tổng hợp: tính (f(n)^n) % m
long long calculateFibPowerMod(long long n, long long m) {
    if (m == 0) return -1; // Tránh lỗi chia cho 0
    
    // Bước 1: Tính F = f(n) % m
    long long fn_mod = fibMod(n, m);
    
    // Bước 2: Tính F^n % m
    return powerMod(fn_mod, n, m);
}

int main() {
    long long n = 100;
    long long m = 10;
    
    cout << "Ket qua cua (f(" << n << ")^" << n << ") mod " << m << " la: ";
    cout << calculateFibPowerMod(n, m) << endl;
    
    return 0;
}
/* # Trả lời:  Mã nguồn hàm tính f(n)

long long tinhFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long f0 = 0;
    long long f1 = 1;
    long long fn = 0;
    
    for (int i = 2; i <= n; ++i) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    
    return fn;
}

# Trả lời:  Mã nguồn hàm kiểm tra số nguyên tố

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

#  Trả lời:  Mã nguồn hàm tìm số nguyên tố gần nhất

int nearest_prime(int N) {
    int lower_prime = N - 1;
    int upper_prime = N + 1;

    while (lower_prime > 1 && !is_prime(lower_prime)) {
        lower_prime--;
    }

    while (!is_prime(upper_prime)) {
        upper_prime++;
    }

    if (lower_prime <= 1) {
        return upper_prime;
    }

    if ((N - lower_prime) <= (upper_prime - N)) {
        return lower_prime;
    } else {
        return upper_prime;
    }
}
*/