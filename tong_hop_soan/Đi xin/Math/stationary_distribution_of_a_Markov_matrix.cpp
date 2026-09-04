#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

// Function to normalize the eigenvector
VectorXd normalize(const VectorXd &vec) {
    double sum = vec.sum();
    return vec / sum;
}

// Function to find the stationary distribution
VectorXd findStationaryDistribution(const MatrixXd &P) {
    EigenSolver<MatrixXd> solver(P.transpose());

    VectorXd stationaryDistribution;
    for (int i = 0; i < solver.eigenvalues().size(); ++i) {
        if (abs(solver.eigenvalues()[i].real() - 1.0) < 1e-10 && solver.eigenvalues()[i].imag() == 0.0) {
            stationaryDistribution = solver.eigenvectors().col(i).real();
            break;
        }
    }

    return normalize(stationaryDistribution);
}

int main() {
    // Define the Markov matrix
    MatrixXd P(3, 3);
    P << 0.2, 0.6, 0.2,
         0.3, 0, 0.7,
         0.5, 0, 0.5;

    cout << "Markov matrix P:" << endl;
    cout << P << endl;

    // Find the stationary distribution
    VectorXd stationaryDistribution = findStationaryDistribution(P);

    cout << "Stationary distribution:" << endl;
    cout << stationaryDistribution.transpose() << endl;

    return 0;
}
