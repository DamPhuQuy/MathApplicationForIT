#include <iostream>
#include <cmath>
using namespace std;

double gamma = 0.01;
int N = 1000;
double e = 0.00001;

double function(double x1, double x2) {
    return x1 * x1 + x2 * x2;
}

double grad1(double x1) {
    return 2 * x1;
}

double grad2(double x2) {
    return 2 * x2;
}

void GradientDescent(double x1, double x2) {
    for (int i = 0; i < N; i++) {
        double x1_new = x1 - gamma * grad1(x1);
        double x2_new = x2 - gamma * grad2(x2);

        cout << x1_new << " " << x2_new << endl;

        if (abs(x1_new - x1) < e && abs(x2_new - x2) < e) {
            break;
        }

        x1 = x1_new;
        x2 = x2_new;
    }

    cout << "Ham so dat nho nhat tai x1 = " << x1 << ", x2 = " << x2 << endl;
    cout << "Min = " << function(x1, x2) << endl;
}

int main() {
    double x1 = 1, x2 = -1;
    GradientDescent(x1, x2);
    return 0;
}
