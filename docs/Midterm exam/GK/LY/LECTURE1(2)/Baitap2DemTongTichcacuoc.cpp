#include <iostream>
#include <cmath>
using namespace std;

struct DivisorInfo {
    int count;
    int sum;
};

DivisorInfo countSumDivisors(int n) {
    int count = 1; 
    int sum = 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        int exponent = 0;
        int term = 1;
        while (n % i == 0) {
            exponent++;
            n /= i;
            term *= i;
        }
        if (exponent > 0) {
            count *= (exponent + 1);
            sum *= (term * i - 1) / (i - 1);
        }
    }

    if (n > 1) {
        count *= 2;
        sum *= (n * n - 1) / (n - 1);
    }

    return {count, sum};
}

long long productOfDivisors(int n, int tau) {
    return pow(n, tau / 2);
}

int main() {
    int number;
    cin >> number;
    DivisorInfo result = countSumDivisors(number);
    int totalDivisors = result.count;
    int totalSum = result.sum;
    long long product = productOfDivisors(number, totalDivisors);
    cout << "So luong uoc cua " << number << " la: " << totalDivisors << endl;
    cout << "Tong cac uoc cua " << number << " la: " << totalSum << endl;
    cout << "Tich cac uoc cua " << number << " la: " << product << endl;
    return 0;
}
