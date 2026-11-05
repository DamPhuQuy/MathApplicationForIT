#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime_factorize(int n, int primes[], int exponents[], int &size) {
    size = 0; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime(i)) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                primes[size] = i;
                exponents[size] = count;
                size++;
            }
        }
    }
    if (n > 1) { 
        primes[size] = n;
        exponents[size] = 1;
        size++;
    }
}

int main() {
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;

    if (is_prime(n)) {
        cout << n << " la so nguyen to!" << endl;
    } else {
        cout << n << " khong phai la so nguyen to!" << endl;
    }

    int primes[100];     //mảng lưu thừa số nguyên tố
    int exponents[100];  //mảng lưu số mũ
    int size;            // số lượng phần tử thực tế

    prime_factorize(n, primes, exponents, size);

    cout << "Tich cac thua so nguyen to cua " << n << " la:" << endl;
    cout << n << " = ";
    for (int i = 0; i < size; i++) {
        cout << primes[i];
    if(exponents[i] >= 0){
        cout << "^" << exponents[i];
    }
        if (i < size - 1) {
            cout << " * ";
    }
}
    return 0;
}
