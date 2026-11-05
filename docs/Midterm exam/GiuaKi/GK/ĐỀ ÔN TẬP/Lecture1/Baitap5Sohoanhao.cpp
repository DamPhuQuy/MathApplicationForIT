#include <iostream>
using namespace std;

int sumProperDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool isPerfect(int n) {
    return sumProperDivisors(n) == n;
}

int main() {
    int limit;
    cout << "Nhap vao gioi han n: ";
    cin >> limit;
    cout << "Cac so hoan hao tu 1 den " << limit << " la:" << endl;
    for (int i = 2; i <= limit; ++i) {
        if (isPerfect(i)) {
            cout << i << " la so hoan hao!" << endl;
        }
    }

    return 0;
}
