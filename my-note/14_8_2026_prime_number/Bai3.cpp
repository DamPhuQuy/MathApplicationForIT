#include <iostream>


using namespace std;


int main() {
   long long n;
   cout << "Nhap n: ";
   cin >> n;


   if (n <= 0) return 0;


   long long sigma = 1;
   long long temp = n;


   for (long long i = 2; i * i <= temp; i++) {
       if (temp % i == 0) {
           long long p_pow = 1;
           while (temp % i == 0) {
               p_pow *= i;
               temp /= i;
           }

           sigma *= (p_pow * i - 1) / (i - 1);
       }
   }


   if (temp > 1) {
       sigma *= (temp + 1);
   }


   cout << "Tong cac uoc cua n la: " << sigma << endl;


   return 0;
}
