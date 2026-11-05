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
            if (fabs(val) < EPS) val = 0.0;
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

double determinant(vector<vector<double>> M) {
    int n = M.size();
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int row = i + 1; row < n; row++) {
            if (fabs(M[row][i]) > fabs(M[pivot][i])) {
                pivot = row;
            }
        }

        if (fabs(M[pivot][i]) < EPS) {
            return 0.0;
        }

        if (pivot != i) {
            swap(M[i], M[pivot]);
            det = -det;
        }

        det *= M[i][i];

        for (int row = i + 1; row < n; row++) {
            double factor = M[row][i] / M[i][i];
            for (int col = i + 1; col < n; col++) {
                M[row][col] -= factor * M[i][col];
            }
        }
    }

    return det;
}

vector<vector<double>> getLeadingPrincipalSubmatrix(const vector<vector<double>>& A, int k) {
    vector<vector<double>> sub(k, vector<double>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            sub[i][j] = A[i][j];
        }
    }
    return sub;
}

bool canLDLT(const vector<vector<double>>& A, vector<double>& minors) {
    int n = A.size();
    minors.clear();

    if (!isSymmetric(A)) {
        cout << "-> Vi pham: Ma tran A khong doi xung (A != A^T).\n";
        return false;
    }

    bool isPositiveDefinite = true;
    for (int k = 1; k <= n; k++) {
        vector<vector<double>> sub = getLeadingPrincipalSubmatrix(A, k);
        double detK = determinant(sub);
        minors.push_back(detK);

        if (detK <= EPS) {
            isPositiveDefinite = false;
        }
    }

    return isPositiveDefinite;
}

void LDLT(const vector<vector<double>>& A,
          vector<vector<double>>& L,
          vector<double>& D) {
    int n = A.size();
    L.assign(n, vector<double>(n, 0.0));
    D.assign(n, 0.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * D[k] * L[j][k];
            }

            if (i == j) {
                D[i] = A[i][i] - sum;
                L[i][j] = 1.0;
            } else {
                L[i][j] = (A[i][j] - sum) / D[j];
            }
        }
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

    cout << "MA TRAN A BAN DAU (" << n << "x" << n << "):\n";
    printMatrix(A);

    cout << "\nPHAN RA LDL^T:\n";
    vector<double> minors;
    bool okLDLT = canLDLT(A, minors);

    if (minors.size() == (size_t)n) {
        cout << "Cac dinh thuc con chinh dan dau:\n";
        for (int k = 1; k <= n; k++) {
            cout << "  Delta_" << k << " = " << fixed << setprecision(6) << minors[k - 1];
            if (minors[k - 1] > EPS) {
                cout << " > 0\n";
            } else {
                cout << " <= 0 (Khong xac dinh duong)\n";
            }
        }
    }

    if (okLDLT) {
        cout << "Ma tran A doi xung va xac dinh duong. Thoa man dieu kien phan ra LDL^T.\n\n";

        vector<vector<double>> L;
        vector<double> D;
        LDLT(A, L, D);

        cout << "Ma tran tam giac duoi L (duong cheo = 1):\n";
        printMatrix(L);

        cout << "\nVector duong cheo D:\n";
        printVector(D);

        cout << "\nMa tran duong cheo D dang day du:\n";
        vector<vector<double>> D_matrix(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) D_matrix[i][i] = D[i];
        printMatrix(D_matrix);
    } else {
        cout << "Khong the phan ra LDL^T vi ma tran A khong thoa man dieu kien (khong doi xung hoac khong xac dinh duong).\n";
    }
}
