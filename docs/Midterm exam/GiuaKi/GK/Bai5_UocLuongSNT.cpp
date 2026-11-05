#include <iostream>
#include <math.h>
using namespace std;

int main() {
    cout << "n = ";
    int n;
    cin >> n;
    if (n <= 1) cout << "n khong hop le!\n";
    else {
        cout << "So luong so nguyen to < " << n << " la: ";
        cout << (int)(n / log(n)) << endl;

    }
}