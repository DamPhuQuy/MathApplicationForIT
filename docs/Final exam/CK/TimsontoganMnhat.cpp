#include <iostream>
#include <cmath>
using namespace std;
 
bool is_prime(int n) {
   if (n <= 1) return false;
   for (int i = 2; i <= sqrt(n); ++i) {
       if (n % i == 0) return false;
   }
   return true;
}
 
int nearest_prime(int N) {
   int lower_prime = N - 1;
   int upper_prime = N + 1;
 
   while (lower_prime > 1 && !is_prime(lower_prime)) {
       lower_prime--;
   }
 
   while (!is_prime(upper_prime)) {
       upper_prime++;
   }
 
   if (lower_prime <= 1) {
       return upper_prime;
   }
 
   if ((N - lower_prime) <= (upper_prime - N)) {
       return lower_prime;
   } else {
       return upper_prime;
   }
}
 
int main() {
   int target;
   cout << "Nhap M: ";
   cin >> target;
 
   int closest = nearest_prime(target);
   cout << "So nguyen to gan nhat voi " << target << " la: " << closest << endl;
 
   return 0;
}

