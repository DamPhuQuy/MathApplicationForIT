#include <iostream>
#include <cmath>
using namespace std;
long long countFactors(long long n) {
   long long total = 1;
   long long temp = n;
   for (long long i = 2; i * i <= temp; i++) {
       if (temp % i == 0) {
           int a = 0;
           while (temp % i == 0) {
               a++;
               temp /= i;
           }
           total *= (a + 1);
       }
   }
   if (temp > 1) total *= 2;
   return total;
}
int main() {
   long long n;
   cout << "Nhap n: ";
   cin >> n;
   if (n <= 0) return 0;
   cout << countFactors(n) << endl;
   for (long long i = 1; i * i <= n; i++) {
       if (n % i == 0) {
           cout << i << " ";
       }
   }
   for (long long i = sqrt(n); i >= 1; i--) {
       if (n % i == 0) {
           long long other = n / i;
           if (other != i) {
               cout << other << (other == n ? "" : " ");
           }
       }
   }
   cout << endl;


   return 0;
}
