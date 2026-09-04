#include <iostream>
#include <C:/library/EigenLib/Eigen/Dense>

int main() {
    freopen("out", "w", stdout);
    // Define the matrix
    Eigen::MatrixXd A(2, 2);
    // A << 1, 2, 3,
    //      4, 5, 6,
    //      7, 8, 9;
    A << 5, 5,
        -1, 7;
         

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Get the singular values
    Eigen::VectorXd singularValues = svd.singularValues();
    std::cout << "Singular values:\n" << singularValues << std::endl;

    // Get the left singular vectors
    Eigen::MatrixXd leftSingularVectors = svd.matrixU();
    std::cout << "Left singular vectors:\n" << leftSingularVectors << std::endl;

    // Get the right singular vectors
    Eigen::MatrixXd rightSingularVectors = svd.matrixV();
    std::cout << "Right singular vectors:\n" << rightSingularVectors << std::endl;

    return 0;
}
