#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double MAX_GRAD = 15.0; 

double function2(double x) {
    if (x <= -25.0) return INFINITY; 
    
    double exponent = pow(x, 5) - pow(x, 4);
    if (exponent > 700.0) return INFINITY; 

    return pow(log(x * x + 10) + x - 5, 2) + 2*x;
}

double gradient(double x) {
    if (x <= -25.0) return -INFINITY;

    double exponent = pow(x, 5) - pow(x, 4);
    if (exponent > 700.0) return INFINITY;

    return 2*(log(x * x + 10) + x - 5)*((2 * x) / (x * x + 10) + 1) + 2;
}

double gradientDescent(double start_x, double gamma, int epochs, double epsilon) {
    double x = start_x;
    
    for (int i = 0; i < epochs; i++) {
        double current_grad = gradient(x);
        
        current_grad = max(-MAX_GRAD, min(MAX_GRAD, current_grad));
        
        double x_old = x;
        x = x_old - gamma * current_grad;
        
        if (x <= -25.0) {
            x = -24.99;
        }

        if (fabs(x - x_old) < epsilon) {
            cout << "=> Hoi tu thanh cong sau " << i + 1 << " vong lap.\n";
            return x;
        }
    }
    
    cout << "=> Cham gioi han so vong lap (" << epochs << ").\n";
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // đổi tham số dữ liệu đầu vào tại đây
    double start_x = 0.5;
    double gamma = 0.1; 
    int epochs = 1000; 
    double epsilon = 1e-5;

    double minimum_x = gradientDescent(start_x, gamma, epochs, epsilon);
    
    cout << "--- KET QUA TOI UU ---\n";
    cout << "Gia tri x tai diem cuc tieu : " << minimum_x << "\n";
    cout << "Gia tri nho nhat cua ham so : " << function2(minimum_x) << "\n";

    return 0;
}
