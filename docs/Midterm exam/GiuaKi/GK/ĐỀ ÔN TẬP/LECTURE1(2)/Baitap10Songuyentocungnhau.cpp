#include <iostream>
//Số có ước chung lớn nhất là 1
using namespace std;

long long eulerPhi(long long n) {
    long long result = n; 

    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            
            result = result - (result / i);

            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        result = result - (result / n);
    }

    return result;
}

int main() {
    long long n;
    cout << "Nhap so n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Vui long nhap so nguyen duong." << endl;
        return 0;
    }

    cout << "Gia tri phi(" << n << ") la: " << eulerPhi(n) << endl;
    
    return 0;
}