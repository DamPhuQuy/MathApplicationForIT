/*
### a) Thuật toán Gradient Descent with Momentum:

**Mã giả:**
```
1. Khởi tạo vị trí ban đầu (x0, y0)
2. Khởi tạo vận tốc ban đầu (vx0, vy0) = (0, 0)
3. Đặt hệ số momentum (beta) và tốc độ học (learning rate) (0 < beta < 1, 0 < learning rate < 1)
4. Lặp cho đến khi đạt điều kiện dừng:
    a. Tính gradient của hàm f(x, y) tại vị trí hiện tại (x, y)
    b. Cập nhật vận tốc theo công thức: 
       vx = beta * vx - learning_rate * df/dx
       vy = beta * vy - learning_rate * df/dy
    c. Cập nhật vị trí mới theo công thức:
       x = x + vx
       y = y + vy
5. Trả về vị trí cuối cùng (x, y) là điểm cực tiểu cục bộ của hàm f(x, y)
```

**Giải thích tính hội tụ của Gradient Descent with Momentum:**

- **Vận tốc momentum**: Giúp giảm độ dao động của việc di chuyển trên bề mặt hàm, giúp thuật toán tiến xa hơn vào hướng cực tiểu và tránh việc rơi vào cực tiểu cục bộ.
- **Hệ số momentum (beta)**: Điều chỉnh mức độ ảnh hưởng của vận tốc momentum. Một giá trị beta lớn hơn sẽ giảm độ dao động nhiều hơn, nhưng có thể làm chậm quá trình hội tụ.
- **Tốc độ học (learning rate)**: Điều chỉnh kích thước của bước di chuyển. Một giá trị learning rate lớn có thể làm cho thuật toán bị vượt quá điểm cực tiểu, trong khi một giá trị nhỏ có thể làm chậm quá trình hội tụ.
- **Sự phụ thuộc vào gradient**: Thuật toán sử dụng gradient của hàm để xác định hướng di chuyển và kích thước của bước tiếp theo. Gradient càng lớn, bước di chuyển càng lớn, và ngược lại.

Kết hợp giữa vận tốc momentum và gradient giúp thuật toán Gradient Descent with Momentum hội tụ nhanh hơn và tránh được các vùng cực tiểu cục bộ.

### b) Hàm tính giá trị nhỏ nhất của f(x, y) sử dụng Gradient Descent with Momentum:

```cpp
#include <iostream>
#include <cmath>

using namespace std;

// Hàm số cần tối ưu
double f(double x, double y) {
    return pow(x - 3, 2) + pow(y - 5, 2);
}

// Đạo hàm riêng theo x
double df_dx(double x, double y) {
    return 2 * (x - 3);
}

// Đạo hàm riêng theo y
double df_dy(double x, double y) {
    return 2 * (y - 5);
}

// Hàm tối ưu hóa bằng Gradient Descent with Momentum
pair<double, double> gradientDescentWithMomentum(double x, double y, double learning_rate, double beta) {
    double vx = 0; // Vận tốc theo x
    double vy = 0; // Vận tốc theo y
    int max_iterations = 1000; // Số lần lặp tối đa
    double epsilon = 1e-6; // Điều kiện dừng

    for (int i = 0; i < max_iterations; ++i) {
        // Tính gradient
        double gradient_x = df_dx(x, y);
        double gradient_y = df_dy(x, y);

        // Cập nhật vận t
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

double fastpow(double n, ll m) {
    if (m == 0)
        return 1;
    double tmp = fastpow(n, m/2);
    if (m & 1)
        return tmp*tmp*n;
    else
        return tmp*tmp;
}

double function1(double x) {
    return 2 * exp(fastpow(x, 5) - fastpow(x, 3)) - 5 * fastpow(x, 3) - x + log(x + 45) + 20;
}

double gradient1(double x) {
    return 2 * exp(fastpow(x, 5) - fastpow(x, 3)) * fastpow(x, 2) * (5 * fastpow(x, 2) - 3) - 15 * x * x - 1 + 1 / (x + 45);
}

double function2(double x) {
    return 3*exp(fastpow(x, 5) - fastpow(x, 4)) + fastpow(x, 2) - 20*x + log(x + 25) - 10;
}

double gradient2(double x) { // derivative of loss function
    return 3*exp(fastpow(x, 5) - fastpow(x, 4))*(5*fastpow(x, 4) - 4*fastpow(x, 3)) + 2*x - 20 + 1/(x+25);
} 


double gradientDescentWithMomentum(double (*function)(double), double (*gradient)(double)) {
    // reference: https://www.youtube.com/watch?v=WyAZ97igZxA&t=390s

    double gamma = 1e-3; // step, learningrate
    double x = 0.0;
    ll N = int(1e4);;
    double epsilon = 1e-5;
    double momentum = 0.1;
    double velocity = 0;
    
    for (ll i = 0; i < N; ++i) {
        double x_old = x; 
        velocity = momentum*velocity + (1-momentum)*gradient(x_old);
        x = x_old - gamma*velocity;
        if (fabs(x - x_old) < epsilon)
            break;
    }
    return x;
}

double gradientDescentWithMomentumNorm(double (*function)(double), double (*gradient)(double)) {
    double learning_rate = 0.001;
    double momentum = 0.9;
    double x = 0.0;
    double velocity = 0.0;
    int N = 1000000;
    double epsilon = 1e-7;
    int i = 0;

    while (i < N) {
        double x_old = x;
        double grad = gradient(x_old);
        velocity = momentum * velocity - learning_rate * grad;
        x = x_old + velocity;
        if (fabs(x - x_old) < epsilon)
            break;
        i++;
    }
    return x;
}

int main() {

    // f(x) = 2e^(x^5 - x^3) - 5x^3 - x + ln(x + 45) + 20
    // f'(x) = 2e^(x^5 - x^3)*(5x^4 - 3x^2) - 15x^2 + 1 + 1/(x+45)

    // g(x) = 3e^(x^5 - x^4) + x^2 - 20x + ln(x + 25) - 10
    // g'(x) = 3e^(x^5 - x^4)*(5x^4 - 4x^3) + 2x - 20 + 1/(x+25)

    cout << "Minimum value of the function f(x): " << function1(gradientDescentWithMomentum(function1, gradient1)) << endl;
    cout << "Minimum value of the function g(x): " << function2(gradientDescentWithMomentum(function2, gradient2)) << endl;

    return 0;
}