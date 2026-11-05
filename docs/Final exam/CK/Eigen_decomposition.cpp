/*Điều kiện: Eigen decomposition
•	Ma trận phải là ma trận vuông.
•	Phải có đủ các giá trị riêng và vector riêng.*/
#include <bits/stdc++.h>
#include "Eigen/Dense"
using namespace std;

void InverseMatrix(Eigen::MatrixXd data, Eigen::MatrixXd &res, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            res(i, j) = 0;
        }
        res(i, i) = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(data(i, i) == 0) {
            for(int j = i + 1; j < n; ++j) {
                if(data(j, i) != 0) {
                    for(int k = 0; k < n; ++k) {
                        swap(data(i, k), data(j, k));
                        swap(res(i, k), res(j, k));
                    }
                }
            }
        }
        if(data(i, i) == 0) 
            throw invalid_argument("Ma tran khong co nghich dao!");
        for(int j = i + 1; j < n; ++j) {
            double ratio = -data(j, i) / data(i, i);
            for(int k = 0; k < n; ++k) {
                data(j, k) = data(i, k) * ratio + data(j, k);
                res(j, k) = res(i, k) * ratio + res(j, k);
            }
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        for(int j = i - 1; j >= 0; --j) {
            double ratio = -data(j, i)/data(i, i);
            for(int k = 0; k < n; ++k) {
                data(j, k) = data(i, k) * ratio + data(j, k);
                res(j, k) = res(i, k) * ratio + res(j, k);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        double ratio = data(i, i);
        for(int j = 0; j < n; ++j) {
            data(i, j) /= ratio;
            res(i, j) /= ratio;
        }
    }
}

int main() {    
    int n;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> n;
    Eigen::MatrixXd A(n, n), P(n, n), D(n, n), PInv(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> A(i, j);
        }
    } 
    Eigen::EigenSolver<Eigen::MatrixXd> solver(A);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            D(i, j) = 0;
        }
        D(i, i) = solver.eigenvalues().real()(i);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            P(i, j) = solver.eigenvectors().real()(i, j);
        }
    }
    InverseMatrix(P, PInv, n);
    cout << "P: " << endl <<setprecision(5) << P << endl;
    cout << "D: " << endl <<setprecision(5) << D << endl;
    cout << "PInv: " << endl <<setprecision(5) << PInv << endl;
    cout << "P * D * PInv: " << endl <<setprecision(5) << P * D * PInv << endl;
    return 0;
}
