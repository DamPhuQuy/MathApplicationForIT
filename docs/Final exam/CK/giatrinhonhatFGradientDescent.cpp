#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x1, x2;
};

double func_obj(Point p) {
    double y = p.x1;
    double z = p.x2;
    
    if (z >= 0) {
        return z - z * y + log10(1.0 + exp(-z));
    } else {
        return -z * y + log10(exp(z) + 1.0);
    }
}
Point gradient(Point p) {
    double y = p.x1;
    double z = p.x2;
    double ln10 = log(10.0);
    
    double grad_y = -z; 
    double grad_z = 0.0;
    
    if (z >= 0) {
        grad_z = 1.0 - y - exp(-z) / ((1.0 + exp(-z)) * ln10);
    } else {
        grad_z = -y + exp(z) / ((exp(z) + 1.0) * ln10);
    }
    
    return {grad_y, grad_z};
}

Point gradientDescentWithMomentum(Point start, double gamma, double alpha, double epsilon, long long max_iter) {
    Point current = start;
    Point velocity = {0.0, 0.0};
   
    for (long long i = 1; i <= max_iter; i++) {
        Point grad = gradient(current);
       
        velocity.x1 = alpha * velocity.x1 + gamma * grad.x1;
        velocity.x2 = alpha * velocity.x2 + gamma * grad.x2;
       
        Point next_point;
        next_point.x1 = current.x1 - velocity.x1;
        next_point.x2 = current.x2 - velocity.x2;
       
        double step_size = hypot(next_point.x1 - current.x1, next_point.x2 - current.x2);

        if (step_size < epsilon) {
            cout << "=> Hoi tu thanh cong sau " << i << " vong lap.\n";
            return next_point;
        }
       
        current = next_point;
    }
   
    cout << "=> Cham gioi han so vong lap (" << max_iter << ").\n";
    return current;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Point start = {1.0, 10.0};   
    double gamma = 0.0001;       
    double alpha = 0.4;         
    double epsilon = 1e-5;       

    long long max_iter = 1000000000LL; 
    
    Point optimal = gradientDescentWithMomentum(start, gamma, alpha, epsilon, max_iter);
    
    cout << "--- KET QUA TOI UU ---\n";
    cout << "Ham so dat gia tri nho nhat tai: y (x1) = " << optimal.x1
         << ", z (x2) = " << optimal.x2 << "\n";
    cout << "Min f(y, z) = " << func_obj(optimal) << "\n";
    
    return 0;
}
