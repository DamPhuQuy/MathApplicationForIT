// Le Duc Phuc Long, 2024, 20 yo
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<vector<db>> matrix;

#define nln '\n'

void enterMatrix(matrix &mtx, ll &n) {
    cout << "Enter the size of matrix: ";
    cin >> n;
    mtx.resize(n, vector<db>(n));
    cout << "Enter Matrix: " << nln;
    for (auto &row : mtx)
        for (auto &val : row)
            cin >> val;
}

void viewMatrix(const matrix &arr) {
    for (auto row : arr) {
        for (auto val : row)
            cout << val << ' ';
        cout << endl;
    }
}

void LU_Decomposition(const matrix& A, matrix& L, matrix& U) {
    int n = A.size();

    // Initialize L as identity matrix and U as zero matrix
    L = matrix(n, vector<db>(n, 0));
    U = matrix(n, vector<db>(n, 0));
   
    // Perform LU decomposition
    for (int i = 0; i < n; ++i) {
        // Now we will compute the U matrix first
        for (int j = i; j < n; ++j) { // row of matrix U 
            int sum = 0;
            for (int k = 0; k < i; ++k)
                sum += L[i][k]*U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        // つぎは　we continue to compute the L matrix
        for (int j = i; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < i; ++k)
                sum += L[j][k]*U[k][i];
            L[j][i] = (A[j][i]-sum)/U[i][i];
        }
    }
}

int main(int argc, char* argv[]) {
    // Example matrix
    vector<vector<double>> A = {
        {2, 4, 3, 5},
        {-4, -7, -5, -8},
        {6, 8, 2, 9},
        {4, 9, -2, 14}
    };

    // Variables to store L and U matrices
    vector<vector<double>> L, U;

    // Perform LU decomposition
    LU_Decomposition(A, L, U);

    viewMatrix(A); cout << nln;

    // Print L and U matrices
    cout << "L matrix:" << endl;
    viewMatrix(L);
    cout << endl;

    cout << "U matrix:" << endl;
    viewMatrix(U);

    return 0;
}