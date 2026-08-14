#include <iostream>
#include <cmath>


using namespace std;


int main() {
   long long n;
   cout << "Nhap n: ";
   cin >> n;


   if (n <= 0) return 0;


   long long tau = 1;
   long long temp = n;


    for (long long i = 2; i * i <= temp; i++) {
       if (temp % i == 0) {
           int a = 0;
           while (temp % i == 0) {
               a++;
               temp /= i;
           }
           tau *= (a + 1);
       }
   }
   if (temp > 1) tau *= 2;




   long long mu = pow(n, tau / 2.0);


   cout <<"Tich cac uoc cua n la: " << mu << endl;


   return 0;
}
