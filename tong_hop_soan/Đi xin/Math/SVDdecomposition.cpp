// Le Duc Phuc Long, 2024, 20 yo
// You don't think twice, you code twice

#include <bits/stdc++.h>
#include <C:/library/EigenLib/Eigen/Dense>

using namespace std;
using namespace Eigen;

typedef long long ll;
typedef double db;
typedef vector<vector<db>> matrix;

#define nln '\n'

const double eps = 1e-5;

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
            cout << setw(10) << setprecision(3) << fixed << val;
        cout << endl;
    }
}

matrix transpose(matrix A) {
    ll n = A.size();
    matrix B = matrix(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            B[i][j] = A[j][i];
    return B;
}

matrix multi(matrix A, matrix B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    // Initialize the result matrix C with all elements as 0
    matrix C = matrix(m, vector<db>(p, 0));

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

matrix tomatrix(MatrixXd P) {
    ll n = P.rows();
    matrix A = matrix(n, vector<db>(n, 0));
    for (int i = 0; i < P.rows(); i++)
        for (int j = 0; j < P.cols(); ++j)
            A[i][j] = P(i,j);
    return A;
}

MatrixXd toMatrixXd(matrix A) {
    MatrixXd P(A.size(), A.size());
    ll n = A.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            P(i, j) = A[i][j];
    return P;
}

void viewMatrixXd(const Eigen::MatrixXd& matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            std::cout << setw(6) << setprecision(3) << fixed <<  matrix(i, j);
        }
        std::cout << std::endl;
    }
}

void SVD_decomposition(const matrix& A, matrix& V, matrix& S, matrix& U) {
    int n = A.size();
    matrix ATA = multi(transpose(A), A);
    
    MatrixXd ATA_E = toMatrixXd(ATA);
    // cout << "ATA:" << '\n';
    // viewMatrixXd(ATA_E);

    SelfAdjointEigenSolver<MatrixXd> es(ATA_E);
    MatrixXd eigenvectors = es.eigenvectors().real();
    V = tomatrix(eigenvectors);
    // cout << "see V: " << nln;
    // viewMatrix(V);

    VectorXd eigenvalues = es.eigenvalues().real();
    vector<double> eigenvl(eigenvalues.data(), eigenvalues.data() + eigenvalues.size());

    S = matrix(n, vector<db>(n, 0));
    for (int i = 0; i < n; ++i) {
        if (abs(eigenvalues[i]) > eps)
            S[i][i] = sqrt(eigenvl[i]);
    }

    matrix ST = matrix(n, vector<db>(n, 0));
    for (int i = 0; i < n; ++i)
        if (abs(S[i][i]) > eps)
            ST[i][i] = 1 / S[i][i];
   
    U = multi(multi(A, V), ST);
    // cout << "See U: " << nln;
    // viewMatrix(U);
}


int main(int argc, char* argv[]) {
    // Example matrix
    matrix A = {
        {2, 4, 8},
        {4, 8, 16},
        {1, 2, 3},
    };
    // matrix A = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // matrix A = {
    //     {5, 5},
    //     {-1, 7}
    // };


    matrix U, V, S;
    SVD_decomposition(A, V, S, U);

    cout << "A: " << nln;
    viewMatrix(A);
    cout << "V: " << nln;
    viewMatrix(V);
    cout << "U: " << nln;
    viewMatrix(U);
    cout << "S: " << nln;
    viewMatrix(S);
    cout << "\nReconstruct: U*S*V^T = A" << nln;;
    viewMatrix(multi(multi(U, S), transpose(V)));


    return 0;
}