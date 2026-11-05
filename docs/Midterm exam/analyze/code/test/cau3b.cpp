#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const double EPS = 1e-5;

void printMatrix(const vector<vector<double>>& A, int precision = 6) {
    int rows = A.size();
    if (rows == 0) return;
    int cols = A[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double val = A[i][j];
            if (fabs(val) < EPS) val = 0.0; // Tránh hiển thị -0.000000 theo sai số e = 1e-5
            cout << setw(13) << fixed << setprecision(precision) << val;
        }
        cout << '\n';
    }
}

void printVector(const vector<double>& v, int precision = 6) {
    for (size_t i = 0; i < v.size(); i++) {
        double val = v[i];
        if (fabs(val) < EPS) val = 0.0;
        cout << setw(13) << fixed << setprecision(precision) << val;
    }
    cout << '\n';
}

bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(A[i][j] - A[j][i]) > EPS) {
                return false;
            }
        }
    }
    return true;
}

bool canEigen(const vector<vector<double>>& A) {
    return isSymmetric(A);
}

void eigenDecomposition(vector<vector<double>> A,
                        vector<vector<double>>& Q,
                        vector<double>& lambda,
                        double eps) {
    int n = A.size();


    Q.assign(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        Q[i][i] = 1.0;
    }

    if (n <= 1) {
        lambda.resize(n);
        if (n == 1) lambda[0] = A[0][0];
        return;
    }

    int maxIterations = 10000;
    int iter = 0;

    while (iter++ < maxIterations) {
        int p = 0, q = 1;
        double maxVal = fabs(A[0][1]);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (fabs(A[i][j]) > maxVal) {
                    maxVal = fabs(A[i][j]);
                    p = i;
                    q = j;
                }
            }
        }

        if (maxVal < eps) {
            break;
        }

        double theta = 0.5 * atan2(2.0 * A[p][q], A[p][p] - A[q][q]);
        double c = cos(theta);
        double s = sin(theta);

        double App = A[p][p];
        double Aqq = A[q][q];
        double Apq = A[p][q];

        A[p][p] = c * c * App + 2.0 * c * s * Apq + s * s * Aqq;
        A[q][q] = s * s * App - 2.0 * c * s * Apq + c * c * Aqq;
        A[p][q] = 0.0;
        A[q][p] = 0.0;

        for (int k = 0; k < n; k++) {
            if (k != p && k != q) {
                double Akp = A[k][p];
                double Akq = A[k][q];

                A[k][p] = A[p][k] = c * Akp + s * Akq;
                A[k][q] = A[q][k] = -s * Akp + c * Akq;
            }
        }

        for (int k = 0; k < n; k++) {
            double Qkp = Q[k][p];
            double Qkq = Q[k][q];

            Q[k][p] = c * Qkp + s * Qkq;
            Q[k][q] = -s * Qkp + c * Qkq;
        }
    }

    lambda.resize(n);
    for (int i = 0; i < n; i++) {
        lambda[i] = A[i][i];
    }
}

int main() {
    int n;
    cout << "Nhap cap cua ma tran vuong n: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Kich thuoc ma tran khong hop le!\n";
        return 1;
    }

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "\nPhan eigendecomposition:\n";
    cout << "Kiem tra dieu kien phan ra\n";

    if (canEigen(A)) {
        cout << "Ma tran A doi xung thuc. Thoa man dieu kien Jacobi.\n\n";

        vector<vector<double>> Q;
        vector<double> lambda;
        eigenDecomposition(A, Q, lambda, EPS);

        cout << "Cac tri rieng:\n";
        printVector(lambda);

        cout << "\nMa tran vector rieng Q (cac cot la cac vector rieng truc chuan tuong ung):\n";
        printMatrix(Q);

        cout << "\nKiem tra Lambda dang ma tran duong cheo:\n";
        vector<vector<double>> Lambda_matrix(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) Lambda_matrix[i][i] = lambda[i];
        printMatrix(Lambda_matrix);
    } else {
        cout << "Khong the ap dung phuong phap Jacobi vi ma tran A khong doi xung thuc.\n";
    }

    return 0;
}
