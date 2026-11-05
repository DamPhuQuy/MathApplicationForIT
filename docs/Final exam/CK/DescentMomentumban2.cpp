#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Tham số theo đề
#define EPSILON 1e-5
#define GAMMA 0.001
#define N 1000
#define ALPHA 0.5

// f(x) = (e^x + 3x - 10)^2 + x^2
double func(double x) {
      return pow(log(2*pow(x,2)+1),2) + 9 * x + 3 * exp(x*x) - 5;


}

// f'(x) = 2(e^x + 3x - 10)(e^x + 3) + 2x
double grad(double x) {
return 2 * log(2*pow(x,2)+1)*((4*x)/(2*x*x+1)) + 9 + 6*x*exp(x*x);

}

// Gradient Descent with Momentum
double GD_momentum(double x) {
    double deltaX = 0.0;
    int iter = 0;

    for (int i = 1; i <= N; i++) {
        iter = i;

        double deltaX_new = ALPHA * deltaX - GAMMA * grad(x);
        double x_new = x + deltaX_new;

        // Kiểm tra nếu thuật toán bị phân kỳ
        if (!isfinite(x_new)) {
            cout << "=> Thuat toan bi phan ky. Hay giam learning rate GAMMA.\n";
            break;
        }

        if (fabs(x_new - x) < EPSILON) {
            x = x_new;
            break;
        }

        x = x_new;
        deltaX = deltaX_new;
    }

    cout << fixed << setprecision(5);
    cout << "=> Thuat toan hoi tu tai vong lap thu: " << iter << endl;
    cout << "=> Toa do cuc tieu gan dung Min x = " << x << endl;

    return func(x);
}

int main() {
    double x_init = -1.00000;

    cout << fixed << setprecision(5);
    cout << "Diem khoi tao x = " << x_init << endl;
    cout << "Learning rate gamma = " << GAMMA << endl;
    cout << "Momentum alpha = " << ALPHA << endl;
    cout << "So buoc lap N = " << N << endl;
    cout << "Sai so epsilon = " << EPSILON << endl;
    cout << endl;

    double min_fx = GD_momentum(x_init);

    cout << "=> Gia tri nho nhat gan dung Min f(x) = " << min_fx << endl;

    return 0;
}