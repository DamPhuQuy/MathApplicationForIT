#include <iostream>
using namespace std;

int UCLN1(int n, int m) {
    for (int i = n > m ? m : n; i >= 1; i--) {
        if (m % i == 0 && n % i == 0) return i;
    }
    return 1;
}

int BCNN1(int n, int m) {
    if (n == 0 || m == 0) return 0;

    int l, b;
    if (n > m) {
        l = n;
        b = m;
    }
    else {
        l = m;
        b = n;
    }

    for (int i = 1; ; i++) {
        if ((l * i) % b == 0) return l * i;
    }
}

int UCLN2(int n, int m) {
    if (m == 0) return n;
    return UCLN2(m, n % m);
}

int BCNN2(int n, int m) {
    if (n == 0 || m == 0) return 0;
    return n * m / UCLN2(n, m);
}

int main() {
    cout << "Moi nhap 2 so: ";
    int a, b;
    cin >> a >> b;
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    cout << "1. Cach don gian\n2. Cach Euclid\nChon: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "UCLN cua " << a << " va " << b << " la: " << UCLN1(a, b) << endl;
        cout << "BCNN cua " << a << " va " << b << " la: " << BCNN1(a, b) << endl;  
    }
    else {
        cout << "UCLN cua " << a << " va " << b << " la: " << UCLN2(a, b) << endl;
        cout << "BCNN cua " << a << " va " << b << " la: " << BCNN2(a, b) << endl;  
    }
}