#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

// Define the objective function f(x, y)
double objective(double x, double y) {
    return x*x + y*y;
}

// Define the constraint function g(x, y) - constraint: x + y = 1
double constraint(double x, double y) {
    return x + y - 1;
}

// Gradient of the objective function with respect to x
double grad_f_x(double x, double y) {
    return 2 * x;
}

// Gradient of the objective function with respect to y
double grad_f_y(double x, double y) {
    return 2 * y;
}

// Gradient of the constraint function with respect to x
double grad_g_x(double x, double y) {
    return 1;
}

// Gradient of the constraint function with respect to y
double grad_g_y(double x, double y) {
    return 1;
}

// Augmented Lagrange Multiplier Method
pair<double, double> ALMM(double initial_x, double initial_y, double penalty, double tolerance, int max_iterations) {
    double x = initial_x;
    double y = initial_y;
    double lambda = 0; // Lagrange multiplier initialization

    for (int i = 0; i < max_iterations; ++i) {
        // Update Lagrange multiplier
        lambda -= penalty * constraint(x, y);

        // Update x and y using gradient descent with penalty term
        x -= (grad_f_x(x, y) + lambda * grad_g_x(x, y)) / (2 + penalty);
        y -= (grad_f_y(x, y) + lambda * grad_g_y(x, y)) / (2 + penalty);

        // Check convergence
        if (abs(constraint(x, y)) < tolerance) {
            cout << "Converged after " << i+1 << " iterations." << endl;
            return make_pair(x, y);
        }
    }

    cout << "Did not converge within max iterations." << endl;
    return make_pair(x, y);
}

int main() {
    double initial_x = 0; // Initial guess for x
    double initial_y = 0; // Initial guess for y
    double penalty = 1;   // Penalty parameter
    double tolerance = 1e-6; // Tolerance for convergence
    int max_iterations = 1000; // Maximum number of iterations

    // Solve the constrained optimization problem using ALMM
    pair<double, double> solution = ALMM(initial_x, initial_y, penalty, tolerance, max_iterations);

    // Print the solution
    cout << "Optimal solution: x = " << solution.first << ", y = " << solution.second << endl;
    cout << "Objective function value: " << objective(solution.first, solution.second) << endl;

    return 0;
}
