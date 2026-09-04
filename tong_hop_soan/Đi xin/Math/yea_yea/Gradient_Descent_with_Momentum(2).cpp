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

double log_custom(double a, double b) {
    return log(b) / log(a);
}

double function1(double x) {
    return -log10(1 / (1 + exp(-x)));
}

double gradient1(double x) {
    double exp_neg_x = exp(-x);
    double denominator = 1 + exp_neg_x;
    double ln10 = log(10);  // log_e(10)
    return exp_neg_x / (ln10 * denominator);
}

double gradient(double x){
        return -1 *  1 /((1 +  1 / (exp(x))) * exp(x));
}


double function2(double x) {
    double exp_neg_x = exp(-x);
    double denominator = 1 + exp_neg_x;
    double value = 1 - 1 / denominator;
    return -log_custom(10, value); 
}

double gradient2(double x) {
    double exp_neg_x = exp(-x);
    double denominator = 1 + exp_neg_x;
    double ln10 = log(10);
    double g_x = 1 - 1 / denominator;  // g(x) = 1 - 1 / (1 + exp(-x))
    return exp_neg_x / (ln10 * denominator * g_x); // Correct gradient for function2
}

double gradientDescentWithMomentum(double (*function)(double), double (*gradient)(double), double learning_rate, double momentum, int N, double epsilon, double velocity = 0.0, double x = 5) {
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
    double learning_rate = 0.0001;
    double momentum = 0.4;
    int N = 100000;
    double epsilon = 1e-5;

    cout << "Minimum value of the function f(x, y) when y = 1: " << function1(gradientDescentWithMomentum(function1, gradient1, learning_rate, momentum, N, epsilon)) << endl;
    cout << "Minimum value of the function f(x, y) when y = 0: " << function2(gradientDescentWithMomentum(function2, gradient2, learning_rate, momentum, N, epsilon)) << endl;

    return 0;
}
