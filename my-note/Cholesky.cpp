#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

using Matrix = vector<vector<double>>;

bool ldl_decomposition(const Matrix& A, Matrix& L, Matrix& D, int n) {
    for (int j = 0; j < n; j++) {
        double sumD = 0;
        for (int k = 0; k < j; k++) {
            sumD += L[j][k] * L[j][k] * D[k][k];
        }
        D[j][j] = A[j][j] - sumD;

        if (abs(D[j][j]) < 1e-15) return false;

        L[j][j] = 1.0;

        for (int i = j + 1; i < n; i++) {
            double sumL = 0;
            for (int k = 0; k < j; k++) {
                sumL += L[i][k] * L[j][k] * D[k][k];
            }
            L[i][j] = (A[i][j] - sumL) / D[j][j];
        }
    }
    return true;
}

void verify_result(const Matrix& L, const Matrix& D, int n) {
    Matrix result(n, vector<double>(n, 0.0));
    
    cout << "\n--- KIEM TRA: NHAN L * D * L^T ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double val = 0;
            for (int k = 0; k < n; k++) {
                val += L[i][k] * D[k][k] * L[j][k];
            }
            result[i][j] = val;
            cout << setw(12) << setprecision(6) << result[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    if (!(cin >> n) || n <= 0) return 0;

    Matrix A(n, vector<double>(n));
    Matrix L(n, vector<double>(n, 0.0));
    Matrix D(n, vector<double>(n, 0.0));

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    if (ldl_decomposition(A, L, D, n)) {
        cout << fixed << setprecision(5);
        
        cout << "\nMa tran L:\n";
        for (const auto& row : L) {
            for (double val : row) cout << setw(12) << val;
            cout << endl;
        }

        cout << "\nMa tran D:\n";
        for (const auto& row : D) {
            for (double val : row) cout << setw(12) << val;
            cout << endl;
        }

        cout << "\nMa tran L^T:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << setw(12) << L[j][i];
            cout << endl;
        }

        verify_result(L, D, n);
    } else {
        cout << "Loi phan ra!" << endl;
    }

    return 0;
}