#include <iostream>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;

int main() {
    // Define the matrix A
    MatrixXd A(3, 3);
    A << 1, 3, 7,
         5, 6, 7,
         7, 9, 7;


    // Compute the eigenvalues and eigenvectors of A
    EigenSolver<MatrixXd> es(A);
    VectorXcd eigenvalues = es.eigenvalues();
    MatrixXcd eigenvectors = es.eigenvectors();

    // Check if the matrix is diagonalizable
    if (eigenvalues.rows() != A.rows()) {
        cout << "Matrix is not diagonalizable. Insufficient eigenvectors." << endl;
        return 1;
    }

    // Reconstruct the original matrix using eigenvalues and eigenvectors
    MatrixXd P = eigenvectors.real();
    MatrixXd D = eigenvalues.real().asDiagonal();
    MatrixXd A_reconstructed = P * D * P.inverse();

    cout << "P matrix: " << endl << P << endl;
    cout << "D matrix: " << endl << D << endl;

    cout << "P^T matrix: " << endl << P.inverse() << endl;

    // Print the original and reconstructed matrices
    cout << "Checking the result........\n";
    cout << "Original matrix A:" << endl << A << endl;
    cout << "Reconstructed matrix A:" << endl << A_reconstructed << endl;

    return 0;
}
