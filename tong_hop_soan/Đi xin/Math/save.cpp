// Convert ----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;

int main() {
    // Assume you have eigenvalues of type VectorXcd
    VectorXcd eigenvalues(3);
    eigenvalues << std::complex<double>(1.0, 2.0),
                   std::complex<double>(-3.0, 4.0),
                   std::complex<double>(5.0, -6.0);

    // Convert Eigen's VectorXcd to vector<vector<db>>
    vector<vector<double>> eigenvalues_real_imag(2, vector<double>(eigenvalues.size()));
    for (int i = 0; i < eigenvalues.size(); ++i) {
        eigenvalues_real_imag[0][i] = eigenvalues[i].real(); // Real part
        eigenvalues_real_imag[1][i] = eigenvalues[i].imag(); // Imaginary part
    }

    // Display the converted eigenvalues
    cout << "Converted eigenvalues:" << endl;
    for (int i = 0; i < eigenvalues_real_imag.size(); ++i) {
        for (int j = 0; j < eigenvalues_real_imag[i].size(); ++j) {
            cout << eigenvalues_real_imag[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// #include <iostream>
#include <vector>

using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    // Initialize the result matrix C with all elements as 0
    vector<vector<int>> C(m, vector<int>(p, 0));

    // Perform matrix multiplication: C = A * B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define matrices A and B
    vector<vector<int>> A = {{1, 2}, {3, 4}, {5, 6}};
    vector<vector<int>> B = {{7, 8, 9}, {10, 11, 12}};

    // Perform ma#include <iostream>


// Invesrt ----------------------------------------------------------------
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {
    // Define a diagonal matrix
    MatrixXd D(3, 3);
    D << 2, 0, 0,
         0, 3, 0,
         0, 0, 5;

    // Check if the diagonal matrix is invertible
    bool invertible = true;
    for (int i = 0; i < D.rows(); ++i) {
        if (D(i, i) == 0) {
            invertible = false;
            break;
        }
    }

    if (invertible) {
        // Calculate the inverse of the diagonal matrix
        MatrixXd D_inv(3, 3);
        for (int i = 0; i < D.rows(); ++i) {
            D_inv(i, i) = 1.0 / D(i, i);
        }

        // Print the inverse matrix
        cout << "Inverse of diagonal matrix:" << endl;
        cout << D_inv << endl;
    } else {
        cout << "Diagonal matrix is singular and does not have an inverse." << endl;
    }

    return 0;
}


#include <Eigen/Dense>
#include <iostream>

int main() {
    // Define the size of the matrix
    int n = 3; // Change this to your desired size

    // Assuming P is your MatrixXd object holding the real part of eigenvectors
    Eigen::MatrixXd P(n, n);

    // Assuming you have already computed eigenvectors and stored them in P

    // Create a double array A[n][n]
    double A[n][n];

    // Copy data from P to A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = P(i, j);
        }
    }

    // Now you can use A as a double array holding the real part of eigenvectors

    // Example: printing the elements of A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <Eigen/Dense>
#include <iostream>

int main() {
    // Define the size of the matrix
    int n = 3; // Change this to your desired size

    // Assuming P is your MatrixXd object holding the real part of eigenvectors
    Eigen::MatrixXd P(n, n);

    // Assuming you have already computed eigenvectors and stored them in P

    // Create a double array A[n][n]
    double A[n][n];

    // Copy data from P to A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = P(i, j);
        }
    }

    // Now you can use A as a double array holding the real part of eigenvectors

    // Example: printing the elements of A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

