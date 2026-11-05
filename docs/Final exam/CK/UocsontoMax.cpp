#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
   if (n <= 1) return false;
   for (int i = 2; i <= sqrt(n); i++) {
       if (n % i == 0) return false;
   }
   return true;
}
int main() {
   int n;
   cout << "Nhap so nguyen duong N : ";
   cin >> n;
   int temp = n;
   int M = -1;
   for (int i = 2; i <= sqrt(temp); i++) {
       if (temp % i == 0) {
           int count = 0;
           while (temp % i == 0) {
               temp /= i;
               count++;
           }
           M = max(M, i); // Cập nhật số nguyên tố lớn nhất
       }
   }
   if (temp > 1) {
       M = max(M, temp);
   }
   cout << "\n\nUoc so nguyen to lon nhat cua " << n << " la: M = " << M << "\n\n";
}
