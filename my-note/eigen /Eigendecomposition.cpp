#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

using Matrix = vector<vector<double>>;

double calculate_det(Matrix a, int n) {
    int dem = 0;
    double kq = 1;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i][i]) < 1e-15) {
            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (abs(a[j][i]) > 1e-15) {
                    swap(a[i], a[j]);
                    dem++;
                    found = true;
                    break;
                }
            }
            if (!found) return 0;
        }
        double anchor = a[i][i];
        kq *= anchor;
        for (int j = i; j < n; j++) a[i][j] /= anchor;
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i];
            for (int k = i; k < n; k++) a[j][k] -= factor * a[i][k];
        }
    }
    kq *= a[n - 1][n - 1];
    return (dem % 2 == 0) ? kq : -kq;
}

Matrix get_minor(const Matrix& a, int n, int h, int c) {
    Matrix b(n - 1, vector<double>(n - 1));
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (i == h) continue;
        int y = 0;
        for (int j = 0; j < n; j++) {
            if (j == c) continue;
            b[x][y] = a[i][j];
            y++;
        }
        x++;
    }
    return b;
}

Matrix invert_matrix(const Matrix& A, int n) {
    Matrix B(n, vector<double>(n));
    double k = calculate_det(A, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matrix minor = get_minor(A, n, i, j);
            double val = calculate_det(minor, n - 1);
            if ((i + j) % 2 != 0) val = -val;
            B[j][i] = val / k;
        }
    }
    return B;
}

Matrix multiply(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void solve_cubic(double C[], double X[]) {
    double delta = pow(C[1], 2) - 3 * C[0] * C[2];
    double k = (9 * C[0] * C[1] * C[2] - 2 * pow(C[1], 3) - 27 * pow(C[0], 2) * C[3]) / (2 * sqrt(pow(abs(delta), 3)));
    double PI = acos(-1.0);
    if (delta > 0) {
        if (abs(k) <= 1) {
            X[0] = (2 * sqrt(delta) * cos(acos(k) / 3) - C[1]) / (3 * C[0]);
            X[1] = (2 * sqrt(delta) * cos(acos(k) / 3 - (2 * PI / 3)) - C[1]) / (3 * C[0]);
            X[2] = (2 * sqrt(delta) * cos(acos(k) / 3 + (2 * PI / 3)) - C[1]) / (3 * C[0]);
        } else {
            X[0] = ((sqrt(delta) * abs(k)) / (3 * C[0] * k)) * (pow((abs(k) + sqrt(k * k - 1)), 1.0 / 3) + pow((abs(k) - sqrt(k * k - 1)), 1.0 / 3)) - (C[1] / (3 * C[0]));
        }
    } else if (delta == 0) {
        X[0] = (-C[1] - pow(-(pow(C[1], 3) - 27 * pow(C[0], 2) * C[3]), 1.0 / 3)) / (3 * C[0]);
    } else {
        X[0] = (sqrt(abs(delta)) / (3 * C[0])) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (C[1] / (3 * C[0]));
    }
}

void eigen_decomposition(Matrix A, int n) {
    Matrix C(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) C[i][i] = 1.0;

    for (int k = n - 2; k >= 0; k--) {
        Matrix M(n, vector<double>(n, 0.0));
        Matrix M1(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) {
            if (i != k) {
                M[i][i] = 1.0;
                M1[i][i] = 1.0;
            } else {
                for (int j = 0; j < n; j++) {
                    M1[i][j] = A[k + 1][j];
                    if (j == k) M[i][j] = 1.0 / A[k + 1][k];
                    else M[i][j] = -A[k + 1][j] / A[k + 1][k];
                }
            }
        }
        A = multiply(M1, multiply(A, M, n), n);
        C = multiply(C, M, n);
    }

    double coefficients[4] = {1, -A[0][0], -A[0][1], -A[0][2]};
    double roots[3] = {0};
    solve_cubic(coefficients, roots);

    Matrix D(n, vector<double>(n, 0.0));
    Matrix T(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        D[i][i] = roots[i];
        for (int j = 0; j < n; j++) T[i][j] = pow(roots[j], n - i - 1);
    }

    Matrix P = multiply(C, T, n);
    for (int j = 0; j < n; j++) {
        double norm = 0;
        for (int i = 0; i < n; i++) norm += P[i][j] * P[i][j];
        norm = sqrt(norm);
        for (int i = 0; i < n; i++) P[i][j] /= norm;
    }

    Matrix P_inv = invert_matrix(P, n);

    cout << fixed << setprecision(4);
    cout << left << setw(25) << "P" << setw(25) << "D" << setw(25) << "P_inv" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << setw(8) << P[i][j] << " ";
        cout << "  ";
        for (int j = 0; j < n; j++) cout << setw(8) << D[i][j] << " ";
        cout << "  ";
        for (int j = 0; j < n; j++) cout << setw(8) << P_inv[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n = 3;
    Matrix A = {{4, 1, 2}, {1, 4, 1}, {2, 1, 4}};
    eigen_decomposition(A, n);
    return 0;
}