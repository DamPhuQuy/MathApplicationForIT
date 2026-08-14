#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double ulsnt(long long n) {
   if (n <= 1) return 0;
   return (double)n / log(n);
}
int main() {
   long long n;
   cout << "Nhap n (n > 1): ";
   cin >> n;
   if (n > 1) {
       cout << "Uoc luong so luong so nguyen to tu 1 den " << n << " la: "
            << fixed << setprecision(0) << ulsnt(n) << endl;
   } else {
       cout << "Vui long nhap n > 1!" << endl;
   }


   return 0;
}
