// Cho số nguyên dương N = 5769. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

// 1. Phân tích thừa số nguyên tố đối với số N.
// 2. Tìm số M là ước số nguyên tố lớn nhất của N.
// 3. Liệt kê các số nguyên tố nhỏ hơn M và tính tổng của chúng.

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

pair<vector<int>, int> primeNumbersLessThanAndSum(int n) {
    vector<int> primes;
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
            sum += i;
        }
    }
    return {primes, sum};
}

pair<vector<int>, int> perfectNumbersLessThanAndSum(int n) {
    vector<int> perfectNumbers;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
            sum += i;
        }
    }
    return {perfectNumbers, sum};
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    return factors;
}

int largestPrimeFactor(int n) {
    int M = 1;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            M = i;
            n /= i;
        }
    }

    if (n > 1) M = n;

    return M;
}

int largestPerfectNumber(int n) {
    int largest = 0;

    for (int i = 1; i < n; i++) {
        if (isPerfect(i)) {
            largest = i;
        }
    }

    return largest;
}

int timKGanM_ChiaHetChoE(int M, int E) {

    if (M == 0) return 0;

    for (int delta = 1; ; delta++) {

        if ((M - delta) > 0 && (M - delta) % E == 0) return M - delta;

        if ((M + delta) % E == 0) return M + delta;

    }

}

int timUCLN(int a, int b) {

    while (b) {

        a %= b;

        swap(a, b);

    }

    return a;

}

void xuLyNguyenToCungNhau(int K) {

    if (K <= 0) return;

    int dem = 0;

    long long tong = 0;

    cout << "Cac so nguyen to cung nhau voi " << K << " (khong in chi tiet vi qua dai):\n";

    for (int i = 1; i < K; ++i) {

        if (timUCLN(i, K) == 1) {

            dem++;

            tong += i;

        }

    }

    cout << "=> So luong: " << dem << endl;

    cout << "=> Tong: " << tong << endl;

}


int timP_NguyenToGanK(int K) {

    if (K <= 0) return 2;

    for (int delta = 0; ; delta++) {

        if (delta == 0) {

            if (checkNguyenTo(K)) return K;

        } else {

            int duoi = K - delta;

            int tren = K + delta;

            if (duoi >= 2 && checkNguyenTo(duoi)) return duoi;

            if (checkNguyenTo(tren)) return tren;

        }

    }

}

int sumOfPrimesBelow(int n) {
    int M = largestPrimeFactor(n);
    int sum = 0;

    for (int i = 2; i < M; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

int sumOfPrimesBelowAndList(int n) {
    int M = largestPrimeFactor(n);
    int sum = 0;

    cout << "Cac so nguyen to nho hon " << M << " la: ";
    for (int i = 2; i < M; i++) {
        if (isPrime(i)) {
            cout << i << " ";
            sum += i;
        }
    }
    cout << endl;

    return sum;
}

int sumOfPerfectNumbersBelow(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (isPerfect(i)) {
            sum += i;
        }
    }

    return sum;
}

int sumOfPerfectNumbersBelowAndList(int n) {
    int sum = 0;

    cout << "Cac so hoan hao nho hon " << n << " la: ";
    for (int i = 1; i < n; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
            sum += i;
        }
    }
    cout << endl;

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> factors = primeFactors(n);
    cout << "Phan tich thua so nguyen to cua " << n << " la: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    cout << "Uoc so nguyen to lon nhat cua " << n << " la: ";
    cout << largestPrimeFactor(n) << endl;

    cout << "Tong cac so nguyen to nho hon " << largestPrimeFactor(n) << " la: ";
    cout << sumOfPrimesBelow(n) << endl;

    cout << "Tong cac so nguyen to nho hon " << largestPrimeFactor(n) << " la: ";
    cout << sumOfPrimesBelowAndList(n) << endl;

    cout << "Tong cac so hoan hao nho hon " << n << " la: ";
    cout << sumOfPerfectNumbersBelow(n) << endl;

    cout << "Cac so hoan hao nho hon " << n << " la: ";
    for (int num : perfectNumbersLessThan(n)) {
        cout << num << " ";
    }
    cout << endl;
}
