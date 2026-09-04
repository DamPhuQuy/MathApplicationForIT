#include <iostream>
#include <Eigen/Dense>
#include <stdexcept>

using namespace std;
using namespace Eigen;

MatrixXd get_inverse(MatrixXd data, int n) {
    MatrixXd res = MatrixXd::Identity(n, n);
    
    for (int i = 0; i < n; ++i) {
        if (abs(data(i, i)) < 1e-15) {
            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if (abs(data(j, i)) > 1e-15) {
                    data.row(i).swap(data.row(j));
                    res.row(i).swap(res.row(j));
                    found = true;
                    break;
                }
            }
            if (!found) throw invalid_argument("Loi: Ma tran khong kha nghich!");
        }

        double pivot = data(i, i);
        data.row(i) /= pivot;
        res.row(i) /= pivot;

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double factor = data(j, i);
                data.row(j) -= factor * data.row(i);
                res.row(j) -= factor * res.row(i);
            }
        }
    }
    return res;
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    MatrixXd A(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A(i, j);
        }
    }

    EigenSolver<MatrixXd> solver(A);
    
    MatrixXd D = solver.eigenvalues().real().asDiagonal();
    MatrixXd P = solver.eigenvectors().real();

    try {
        MatrixXd PInv = get_inverse(P, n);

        cout << "Ma tran P:\n" << P << "\n\n";
        cout << "Ma tran D:\n" << D << "\n\n";
        cout << "Ma tran P^-1:\n" << PInv << "\n\n";
        cout << "Kiem tra (P * D * PInv):\n" << P * D * PInv << endl;
    } 
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}