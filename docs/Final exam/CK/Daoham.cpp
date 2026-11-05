#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Ham f(x) = (e^(2x^2 + 1) - 2x + 1)^2 - 5(x + 1)^3
double f(double x) {
    double u = exp(2 * x * x + 1) - 2 * x + 1;
    return u * u - 5 * pow(x + 1, 3);
}

// Dao ham cap 1 cua f(x)
// f'(x) = 2(e^(2x^2 + 1) - 2x + 1)(4x.e^(2x^2 + 1) - 2) - 15(x + 1)^2
double df(double x) {
    double e = exp(2 * x * x + 1);
    double u = e - 2 * x + 1;
    double du = 4 * x * e - 2;

    return 2 * u * du - 15 * (x + 1) * (x + 1);
}

int main() {
    double x;

    cout << "Nhap x = ";
    cin >> x;

    cout << fixed << setprecision(10);
    cout << "f(x) = " << f(x) << endl;
    cout << "f'(x) = " << df(x) << endl;

    return 0;
}