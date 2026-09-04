#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef double db;
typedef vector<vector<db>> matrix;

#define nln '\n'

void viewMatrix(const matrix &arr) {
    for (auto row : arr) {
        for (auto val : row)
            cout << setw(6) << val << '\t';
        cout << endl;
    }
}

matrix Cholesky_Decomposition(const matrix& A) {
    int n = A.size();
    matrix L(n, vector<db>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            if (i == j) {
                db sum = 0;
                for (int k = 0; k < i; ++k)
                    sum += L[i][k]*L[i][k];
                L[i][j] = sqrt(A[i][j] - sum);
            } else {
                db sum = 0;
                for (int k = 0; k < j; ++k)
                    sum += L[i][k]*L[j][k];
                L[i][j] = (A[i][j] - sum)/L[j][j];
            }
        }
    return L;
}

bool isSymmetric(const matrix& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
}

db determinantNxN(const matrix& mtx) {
    int n = mtx.size();
    if (n == 1) {
        return mtx[0][0];
    }
    db det = 0;
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        matrix minor(n - 1, vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k < i) {
                    minor[j - 1][k] = mtx[j][k];
                } else if (k > i) {
                    minor[j - 1][k - 1] = mtx[j][k];
                }
            }
        }
        db minorDet = determinantNxN(minor);
        det += sign * mtx[0][i] * minorDet;
        sign *= -1;
    }
    return det;
}

bool isPositiveDefinite(const matrix& A) {
    if (!isSymmetric(A)) {
        return false;
    }
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        matrix submatrix(i + 1, vector<double>(i + 1));
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) {
                submatrix[j][k] = A[j][k];
            }
        }
        if (determinantNxN(submatrix) <= 0) {
            return false;
        }
    }
    return true;
}

matrix transpose(const matrix& A) {
    int n = A.size();
    matrix result(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[j][i];
        }
    }
    return result;
}

int main() {
    // Example matrix
    // matrix A = {
    //     {2, 4, 3, 5},
    //     {-4, -7, -5, -8},
    //     {6, 8, 2, 9},
    //     {4, 9, -2, 14}
    // };

    matrix A = {
        {1, 2, 0, 0, 0, 0, 0},
        {2, 5, 2, 0, 0, 0, 0},
        {0, 2, 5, 2, 0, 0, 0},
        {0, 0, 2, 5, 2, 0, 0},
        {0, 0, 0, 2, 5, 2, 0},
        {0, 0, 0, 0, 2, 5, 2},
        {0, 0, 0, 0, 0, 2, 5}
    };

    cout << "A matrix: " << endl;
    viewMatrix(A);
    cout << endl;

    if (isPositiveDefinite(A)) {
        matrix L = Cholesky_Decomposition(A);
        matrix LT = transpose(L);

        cout << "L matrix:" << endl;
        viewMatrix(L);
        cout << endl;

        cout << "LT matrix:" << endl;
        viewMatrix(LT);
        cout << endl;   
    } else {
        cout << "The matrix is not positive definite." << endl;
    }

    return 0;
}
