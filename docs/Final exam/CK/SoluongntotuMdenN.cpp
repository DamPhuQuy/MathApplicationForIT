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
   int M=50,N=500;
   long long sum = 0;
   int count = 0;
   cout << "Cac so nguyen to nam trong khoang tu " << M << " den "<<N<<" la: ";
   for (int i = M+1; i <N; i++) {
       if (isPrime(i)) {
           cout << i << " ";
           sum += i;
           count++;
       }
   }
   cout << "\nTong cac so nguyen to: " << sum;
   cout << "\nSo luong cac so nguyen to trong khoang M den N la: " << count << endl;
   return 0;
}
