#include <iostream>
#include <vector>
// Function to multiply two matrices
std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int n = A.size();
    std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}
// Function to calculate probabilities of states after given time steps
std::vector<double> calculateProbabilities(const std::vector<std::vector<double>>& transitionMatrix, const std::vector<double>& initialState, int timeSteps) {
    std::vector<double> state = initialState;
    std::vector<std::vector<double>> P = transitionMatrix;
    for (int t = 0; t < timeSteps; ++t) {
        state = multiplyMatrices(P, state); // Corrected function call to multiplyMatrices
    }
    return state;
}
int main() {
    // Transition matrix
    std::vector<std::vector<double>> P = {
        {0, 0.75, 0.2, 0.05},
        {0.05, 0.2, 0.3, 0.45},
        {0.1, 0.4, 0.3, 0.2},
        {0, 0.15, 0.3, 0.55}
    };
    // Initial state vector
    std::vector<double> initialState = {0, 1, 0, 0};
    // Time steps to calculate probabilities for
    std::vector<int> timeSteps = {1, 2, 3};
    // Calculate and print results for each time step
    for (int t : timeSteps) {
        std::vector<double> probabilities = calculateProbabilities(P, initialState, t);
        std::cout << "Probabilities of states after time step " << t << ":" << std::endl;
        for (int i = 0; i < probabilities.size(); ++i) {
            std::cout << "State " << i + 1 << ": " << probabilities[i] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
