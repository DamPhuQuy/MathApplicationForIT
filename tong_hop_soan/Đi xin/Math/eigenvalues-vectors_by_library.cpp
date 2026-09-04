// Le Duc Phuc Long, 2024(c)

#include <bits/stdc++.h>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define nln '\n'

typedef long long ll;
typedef double db;
typedef vector<vector<db>> matrix;

MatrixXd toMatrixXd(matrix A) {
    MatrixXd P(A.size(), A.size());
    ll n = A.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            P(i, j) = A[i][j];
    return P;
}

int main(int argc, char* argv[]) {
    matrix A = {
        {9, 8, 6},
        {4, 8, 6},
        {8, 8, 6}
    };

    SelfAdjointEigenSolver<MatrixXd> es(toMatrixXd(A));
    VectorXd eigenvalues = es.eigenvalues().real();
    for (int i = 0; i < eigenvalues.size(); ++i)
        cout << eigenvalues[i] << ' ';
    cout << '\n';

    MatrixXd eigenvectors = es.eigenvectors().real();
    for (int i = 0; i < eigenvectors.rows(); ++i) {
        for (int j = 0; j < eigenvectors.cols(); ++j)
            cout << eigenvectors(i, j) << ' ';
        cout << nln;
    }
    cout << nln;


    return 0;
}