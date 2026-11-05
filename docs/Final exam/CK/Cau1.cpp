#include <iostream>
#include <vector>

using namespace std;

// Tao n so Fibonacci dau tien
vector<long long> generateFibonacci(int n) {
    vector<long long> fib(n + 1);

    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

// Liet ke cac so Fibonacci co dung 6 chu so va tinh tong
void findSixDigitFibonacci(const vector<long long>& fib, int n) {
    long long sum = 0;

    cout << "Cac so Fibonacci co dung 6 chu so trong "
         << n << " so Fibonacci dau tien la:\n";

    for (int i = 1; i <= n; i++) {
        if (fib[i] >= 100000 && fib[i] <= 999999) {
            cout << fib[i] << " ";
            sum += fib[i];
        }
    }

    cout << "\nTong cac so Fibonacci co dung 6 chu so la: " << sum << endl;
}

int main() {
    int n = 50;

    vector<long long> fib = generateFibonacci(n);

    findSixDigitFibonacci(fib, n);

    return 0;
}