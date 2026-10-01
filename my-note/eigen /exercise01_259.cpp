#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void diagonalize(const string& name, const MatrixXd& A) {
    cout << "--- " << name << " ---\n";

    EigenSolver<MatrixXd> es(A);

    // Kiem tra tri rieng thuc
    if (es.eigenvalues().imag().cwiseAbs().maxCoeff() > 1e-5) {
        cout << "Khong the cheo hoa tren R\n\n";
        return;
    }

    MatrixXd D = es.eigenvalues().real().asDiagonal();
    MatrixXd P = es.eigenvectors().real();

    // Kiem tra du vector rieng doc lap tuyen tinh
    FullPivLU<MatrixXd> lu(P);
    lu.setThreshold(1e-4);
    if (lu.rank() < A.rows()) {
        cout << "Khong the cheo hoa (thieu vector rieng)\n\n";
        return;
    }

    MatrixXd P_inv = lu.inverse();

    cout << "P:\n" << P << "\n\n";
    cout << "D:\n" << D << "\n\n";
    cout << "P^-1:\n" << P_inv << "\n\n";
    cout << "P * D * P^-1:\n" << (P * D * P_inv) << "\n\n";
}

int main() {
    cout << fixed << setprecision(4);

    // a. A1 (2x2)
    MatrixXd A1(2, 2);
    A1 << 3, 2,
          1, 4;
    diagonalize("A1", A1);

    // b. A2 (2x2)
    MatrixXd A2(2, 2);
    A2 << 3, 0,
          0, 3;
    diagonalize("A2", A2);

    // c. A3 (2x2)
    MatrixXd A3(2, 2);
    A3 << 2, 1,
          0, 2;
    diagonalize("A3", A3);

    // d. A4 (3x3)
    MatrixXd A4(3, 3);
    A4 << 3, -1, 1,
          0,  2, 0,
          1, -1, 3;
    diagonalize("A4", A4);

    // e. A5 (3x3)
    MatrixXd A5(3, 3);
    A5 << 4, 0, -2,
          2, 5,  4,
          0, 0,  5;
    diagonalize("A5", A5);

    // f. A6 (3x3) - MSSV: 259 => x=2, y=5, z=9
    MatrixXd A6(3, 3);
    A6 << 0, 2, 0,
          5, 0, 0,
          0, 0, 9;
    diagonalize("A6", A6);

    return 0;
}
