#include <iostream>
#include <cmath>

using namespace std;

// This code still not perform correctly

typedef long long ll;
#define nln '\n'

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

double derivative1(double x) {
    return 2 * exp(fastpow(x, 5) - fastpow(x, 3)) * fastpow(x, 2) * (5 * fastpow(x, 2) - 3) - 15 * x * x - 1 + 1 / (x + 45);
}

double secondDerivative1(double x) {
    // f''(x) = 2*e^(x^5 - x^3)*((5x^4 - 3x^2)^2 + (20x^3 - 6x)) + 30x - 1/(x+45)^2
    return 2*exp(fastpow(x, 5) - fastpow(x, 3))*(fastpow(5*fastpow(x, 4) - 3*fastpow(x, 2), 2) + (20*fastpow(x, 3) - 6*x)) + 30*x - 1/fastpow(x+45, 2);
}

double function2(double x) {
    return 3*exp(fastpow(x, 5) - fastpow(x, 4)) + fastpow(x, 2) - 20*x + log(x + 25) - 10;
}

double derivative2(double x) { // derivative of loss function
    return 3*exp(fastpow(x, 5) - fastpow(x, 4))*(5*fastpow(x, 4) - 4*fastpow(x, 3)) + 2*x - 20 + 1/(x+25);
}

double secondDerivative2(double x) {
    // g''(x) = 3e^(x^5 - x^4)*((5x^4 - 4x^3)^2 + (20x^3 - 12x^2)) + 2 - 1/(x+25)^2
    return 3 * exp(fastpow(x, 5) - fastpow(x, 4)) * (pow(5 * fastpow(x, 4) - 4 * fastpow(x, 3), 2) + (20 * fastpow(x, 3) - 12 * fastpow(x, 2))) + 2 - 1 / fastpow(x + 25, 2);
}

double NewtonRaphson_Algorithm(double (*derivative)(double), double (*secondDerivative)(double)) {
    // (y0 - y)/(x0 - x) = slope --> (f(x) - y)/(x0 - x) = f'(x)
        // we need to find the intersection on x-axis then y = 0
        // --> (f(x) - 0) = f'(x) --> f(x)/(x0 - x) = f'(x)
        // --> x0 - x = f(x)/f'(x)

        // --> so when we want find the minimum or maximum, we need
        // to find the x where f'(x) == 0, it similarly above, we have 
        // the formular: x0 - x = f'(x)/f''(x) --> x = x0 - f'(x)/f''(x)

    double x0 = 0, x = x0, eps = 1e-5, i = 0, N = int(1e5);

    while (i < N) {
        double dx = - derivative(x) / secondDerivative(x);
        x += dx;
        if (fabs(dx) < eps || fabs(secondDerivative(x)) < eps) {
            return x;
        }
        i++;

    }
    return NAN;
}

int main(int argc, const char* argv[]) {
    // f(x) = 2e^(x^5 - x^3) - 5x^3 - x + ln(x + 45) + 20
    // f'(x) = 2e^(x^5 - x^3)*(5x^4 - 3x^2) - 15x^2 + 1 + 1/(x+45)
    // f''(x) = 2*e^(x^5 - x^3)*((5x^4 - 3x^2)^2 + (20x^3 - 6x)) + 30x - 1/(x+45)^2

    // g(x) = 3e^(x^5 - x^4) + x^2 - 20x + ln(x + 25) - 10
    // g'(x) = 3e^(x^5 - x^4)*(5x^4 - 4x^3) + 2x - 20 + 1/(x+25)
    // g''(x) = 3e^(x^5 - x^4)*((5x^4 - 4x^3)^2 + (20x^3 - 12x^2)) + 2 - 1/(x+25)^2

    cout << "Minimum value of the function f(x): " << function2(NewtonRaphson_Algorithm(derivative2, secondDerivative2)) << endl;


    return 0;
}