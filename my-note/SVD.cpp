#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using namespace Eigen;

void perform_svd(const MatrixXd& A, MatrixXd& U, MatrixXd& Sigma, MatrixXd& VT) {
    int m = A.rows();
    int n = A.cols();

    MatrixXd S = A.transpose() * A;

    SelfAdjointEigenSolver<MatrixXd> eigensolver(S);
    VectorXd eigenvalues = eigensolver.eigenvalues();
    MatrixXd V = eigensolver.eigenvectors();

    vector<pair<double, VectorXd>> eigen_pairs;
    for (int i = 0; i < n; i++) {
        eigen_pairs.push_back({eigenvalues(i), V.col(i)});
    }

    sort(eigen_pairs.begin(), eigen_pairs.end(), [](const pair<double, VectorXd>& a, const pair<double, VectorXd>& b) {
        return a.first > b.first;
    });

    VectorXd sorted_eigenvalues(n);
    for (int i = 0; i < n; i++) {
        sorted_eigenvalues(i) = max(0.0, eigen_pairs[i].first);
        V.col(i) = eigen_pairs[i].second;
    }

    VT = V.transpose();

    Sigma = MatrixXd::Zero(m, n);
    int rank = 0;
    for (int i = 0; i < min(m, n); i++) {
        double s = sqrt(sorted_eigenvalues(i));
        Sigma(i, i) = s;
        if (s > 1e-9) rank++;
    }

    U = MatrixXd::Zero(m, m);
    for (int i = 0; i < rank; i++) {
        U.col(i) = A * V.col(i) / Sigma(i, i);
    }

    if (rank < m) {
        FullPivLU<MatrixXd> lu(U.leftCols(rank).transpose());
        MatrixXd null_space = lu.kernel(); 
        U.rightCols(m - rank) = U.leftCols(rank).fullPivHouseholderQr().matrixQ().block(0, rank, m, m - rank);
    }
}

int main() {
    int rows, cols;
    cout << "Nhap hang va cot: ";
    cin >> rows >> cols;

    MatrixXd A(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A(i, j);
        }
    }

    MatrixXd U, Sigma, VT;
    perform_svd(A, U, Sigma, VT);

    cout << fixed << setprecision(5);
    cout << "\nMatrix U:\n" << U << endl;
    cout << "\nMatrix Sigma:\n" << Sigma << endl;
    cout << "\nMatrix V^T:\n" << VT << endl;

    cout << "\nKiem tra lai A (U * Sigma * V^T):\n" << U * Sigma * VT << endl;
    cout << "\nMa tran A goc:\n" << A << endl;

    return 0;
}