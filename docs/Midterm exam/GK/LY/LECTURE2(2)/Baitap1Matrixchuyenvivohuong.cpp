#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef vector<vector<double>> Matrix;

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            if (abs(val) < 1e-9) val = 0.0;
            cout << setw(8) << fixed << setprecision(2) << val << " ";
        }
        cout << endl;
    }
}

Matrix scalarMultiply(const Matrix& A, double lambda) {
    int n = A.size();
    Matrix result = A; // Tạo bản sao của A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] *= lambda; 
        }
    }
    return result;
}

Matrix transpose(const Matrix& A) {
    int n = A.size();
    Matrix result(n, vector<double>(n)); // Tạo ma trận mới cùng kích thước
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[j][i]; 
        }
    }
    return result;
}

int main() {
    
    Matrix A = {
        {2, -1,  4},
        {5,  2, -1},
        {0,  3,  2}
    };

    cout << "--- MA TRAN A BAN DAU ---" << endl;
    printMatrix(A);

    double lambda = 3.0;
    cout << "\n1. NHAN MA TRAN VOI SO VO HUONG (lambda = " << lambda << "):" << endl;
    Matrix scalarMat = scalarMultiply(A, lambda);
    printMatrix(scalarMat);

    cout << "\n2. MA TRAN CHUYEN VI cua A (A^T):" << endl;
    Matrix transMat = transpose(A);
    printMatrix(transMat);

    return 0;
}