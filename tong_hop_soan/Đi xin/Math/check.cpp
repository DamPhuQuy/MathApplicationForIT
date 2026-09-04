#include <iostream>
#include <C:/library/EigenLib/Eigen/Dense>

int main() {
    freopen("out", "w", stdout);

    // Define the matrix
    Eigen::MatrixXd A(2, 2);
    A << 5, 5,
        -1, 7;

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Get the singular values
    Eigen::VectorXd singularValues = svd.singularValues();

    // Get the left singular vectors
    Eigen::MatrixXd leftSingularVectors = svd.matrixU();

    // Get the right singular vectors
    Eigen::MatrixXd rightSingularVectors = svd.matrixV();

    // Check correctness by multiplying the original matrix by its left and right singular vectors
    Eigen::MatrixXd reconstructedMatrix = leftSingularVectors * singularValues.asDiagonal() * rightSingularVectors.transpose();

    // Print the reconstructed matrix
    std::cout << "Reconstructed matrix:\n" << reconstructedMatrix << std::endl;

    return 0;
}
