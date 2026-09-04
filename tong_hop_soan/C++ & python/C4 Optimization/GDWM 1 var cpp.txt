#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double cost(double x) {
    return (exp(2 * x) + 3 * x * x + 8 * x) / (35 - x) - 5 * x;
}

double grad(double x) {
    double numerator = (35 - x) * (2 * exp(2 * x) + 6 * x + 8) + exp(2 * x) + 3 * x * x + 8 * x;
    double denominator = (35 - x) * (35 - x);
    return numerator / denominator - 5;
}

pair<double, vector<double>> gradient_descent_momentum(double alpha, double beta, double x0, double grad_thresh = 1e-5, int max_iter = 1000) {
    double x = x0;
    double v = 0;
    vector<double> history;
    history.push_back(x);

    for (int it = 0; it < max_iter; ++it) {
        double gradient = grad(x);
        v = beta * v + alpha * gradient;
        x = x - v;

        history.push_back(x);

        if (abs(gradient) < grad_thresh) {
            cout << "Gradient Descent với Momentum dừng sau " << it << " vòng lặp." << endl;
            break;
        }
    }

    return make_pair(x, history);
}

int main() {
    double alpha = 0.001;
    double beta = 0.1;
    double x0 = 0;

    pair<double, vector<double>> result = gradient_descent_momentum(alpha, beta, x0);

    double x_min = result.first;
    vector<double> history = result.second;

    cout << fixed << setprecision(6);
    cout << "Điểm cực tiểu x = " << x_min << ", f(x) = " << cost(x_min) << endl;

    return 0;
}
