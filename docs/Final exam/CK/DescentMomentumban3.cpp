#include <iostream>
#include <cmath>
#include <iomanip> 

#define EPSILON 1e-5
#define GAMMA 0.001 
#define N 1000     
#define ALPHA 0.01   

using namespace std;

double func(double x) {
    return ((log10(2*pow(x,2)+1)+ exp(8*x)+14*x*x - 6*x)/(2*x*x + 1)) - (4*x*x);
}

// Đạo hàm f'(x)
double grad(double x) {
    double u = (((4*x)/((2*x*x + 1)*log(10))) + 8*exp(8*x) + 28*x - 6)*(2*x*x + 1);
    double v = 2*x*x + 1;
    double du = (log10(2*pow(x,2)+1) + exp(8*x) + 14*x*x - 6*x) * 4*x;
    return ((u-du)/(v*v)) - 8*x;

}

double GD_momentum(double x) {
    double deltaX = 0; // Động lượng ban đầu
    int iter = 0;

    for (int i = 1; i <= N; i++) {
        iter = i;

        double deltaX_new = ALPHA * deltaX - GAMMA * grad(x);

        double x_new = x + deltaX_new;

        if (fabs(x_new - x) < EPSILON) {
            x = x_new;
            break;
        }

        x = x_new;
        deltaX = deltaX_new;
    }
    
    cout << "=> Thuat toan hoi tu tai vong lap thu: " << iter << endl;
    cout << fixed << setprecision(5);
    cout << "=> Toa do cuc tieu (Min x) = " << x << endl;
    
    return func(x);
}

int main() {
    double x_init = -2; // Điểm khởi tạo ban đầu  
    double min_fx = GD_momentum(x_init);
    
    cout << "=> Gia tri nho nhat Min f(x) = " << min_fx << endl;
    
    return 0;
}
