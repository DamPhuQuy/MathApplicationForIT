#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd powerViaDiagonalization(const MatrixXd& P, const MatrixXd& D, const MatrixXd& P_inv, int k) {
    MatrixXd D_k = MatrixXd::Zero(D.rows(), D.cols());
    for (int i = 0; i < D.rows(); ++i) D_k(i, i) = pow(D(i, i), k);
    return P * D_k * P_inv;
}

void processMatrix(const string& name, const MatrixXd& A) {
    cout << "--- " << name << " ---\n";

    EigenSolver<MatrixXd> es(A);

    if (es.eigenvalues().imag().cwiseAbs().maxCoeff() > 1e-5) {
        cout << "Khong the cheo hoa tren R\n\n";
        return;
    }

    MatrixXd D = es.eigenvalues().real().asDiagonal();
    MatrixXd P = es.eigenvectors().real();

    FullPivLU<MatrixXd> lu(P);
    lu.setThreshold(1e-4);
    if (lu.rank() < A.rows()) {
        cout << "Khong the cheo hoa\n\n";
        return;
    }

    MatrixXd P_inv = lu.inverse();

    cout << "P:\n" << P << "\n\n";
    cout << "D:\n" << D << "\n\n";
    cout << "A^2:\n" << powerViaDiagonalization(P, D, P_inv, 2) << "\n\n";
    cout << "A^10:\n" << powerViaDiagonalization(P, D, P_inv, 10) << "\n\n";
    cout << "A^100:\n" << powerViaDiagonalization(P, D, P_inv, 100) << "\n\n";
}

int main() {
    cout << fixed << setprecision(4);

    // a. A7 (x = 2, y = 9)
    MatrixXd A7(3, 3);
    A7 << 5,  0, 0,
          0, -1, 2,
          3,  0, 9;
    processMatrix("A7", A7);

    // b. A8 (x = 2, y = 0)
    MatrixXd A8(3, 3);
    A8 << 2, 3,  2,
          1, 0, -1,
          1, 1,  0;
    processMatrix("A8", A8);

    // c. A9 (x = 2, y = 3)
    MatrixXd A9(3, 3);
    A9 << 4,  2, -1,
          4,  0,  2,
          2, -1,  3;
    processMatrix("A9", A9);

    return 0;
}
