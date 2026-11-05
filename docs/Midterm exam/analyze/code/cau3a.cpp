#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

// ==========================================================
// 1. CÁC HÀM TIỆN ÍCH MA TRẬN
// ==========================================================

// In ma trận cấp n x m
void printMatrix(const vector<vector<double>>& A, int precision = 6) {
    int rows = A.size();
    if (rows == 0) return;
    int cols = A[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double val = A[i][j];
            if (fabs(val) < 1e-12) val = 0.0; // Tránh hiển thị -0.000000
            cout << setw(13) << fixed << setprecision(precision) << val;
        }
        cout << '\n';
    }
}

// In vector
void printVector(const vector<double>& v, int precision = 6) {
    for (size_t i = 0; i < v.size(); i++) {
        double val = v[i];
        if (fabs(val) < 1e-12) val = 0.0;
        cout << setw(13) << fixed << setprecision(precision) << val;
    }
    cout << '\n';
}

// Kiểm tra ma trận đối xứng thực (A = A^T)
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

// Tính định thức ma trận vuông bằng phép khử Gauss (phục vụ tiêu chuẩn Sylvester)
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

// Trích xuất ma trận con dẫn đầu cấp k x k
vector<vector<double>> getLeadingPrincipalSubmatrix(const vector<vector<double>>& A, int k) {
    vector<vector<double>> sub(k, vector<double>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            sub[i][j] = A[i][j];
        }
    }
    return sub;
}

// ==========================================================
// 2. PHÂN RÃ CHOLESKY BIẾN THỂ LDL^T
// ==========================================================

// Kiểm tra điều kiện phân rã LDL^T:
// A phải là ma trận thực đối xứng và xác định dương (Sylvester criterion).
bool canLDLT(const vector<vector<double>>& A, vector<double>& minors) {
    int n = A.size();
    minors.clear();

    // 1. Kiểm tra đối xứng
    if (!isSymmetric(A)) {
        cout << "-> Vi pham: Ma tran A khong doi xung (A != A^T).\n";
        return false;
    }

    // 2. Kiểm tra tất cả các định thức con chính dẫn đầu (Leading Principal Minors > 0)
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

// Thực hiện phân rã A = L * D * L^T
// L là ma trận tam giác dưới với đường chéo = 1
// D là mảng đường chéo
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

// ==========================================================
// 3. PHÂN RÃ EIGENDECOMPOSITION (PHƯƠNG PHÁP JACOBI)
// ==========================================================

// Điều kiện Jacobi: A là ma trận thực đối xứng
bool canEigen(const vector<vector<double>>& A) {
    return isSymmetric(A);
}

// Phân rã A = Q * Lambda * Q^T bằng thuật toán xoay Jacobi
void eigenDecomposition(vector<vector<double>> A,
                        vector<vector<double>>& Q,
                        vector<double>& lambda,
                        double eps) {
    int n = A.size();

    // Khởi tạo Q = I (ma trận đơn vị cấp n)
    Q.assign(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        Q[i][i] = 1.0;
    }

    int maxIterations = 10000;
    int iter = 0;

    while (iter++ < maxIterations) {
        // Tìm phần tử ngoài đường chéo có giá trị tuyệt đối lớn nhất: |A[p][q]|
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

        // Đạt độ chính xác mong muốn
        if (maxVal < eps) {
            break;
        }

        // Tính góc quay Jacobi theta
        double theta = 0.5 * atan2(2.0 * A[p][q], A[p][p] - A[q][q]);
        double c = cos(theta);
        double s = sin(theta);

        // Lưu các giá trị cũ tại các vị trí bị ảnh hưởng
        double App = A[p][p];
        double Aqq = A[q][q];
        double Apq = A[p][q];

        // Cập nhật ma trận A
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

        // Cập nhật ma trận vector riêng Q: Q_new = Q_old * R
        for (int k = 0; k < n; k++) {
            double Qkp = Q[k][p];
            double Qkq = Q[k][q];

            Q[k][p] = c * Qkp + s * Qkq;
            Q[k][q] = -s * Qkp + c * Qkq;
        }
    }

    // Trị riêng là các phần tử trên đường chéo của ma trận đường chéo thu được
    lambda.resize(n);
    for (int i = 0; i < n; i++) {
        lambda[i] = A[i][i];
    }
}

// ==========================================================
// 4. CHƯƠNG TRÌNH CHÍNH (MAIN)
// ==========================================================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    double eps = 1e-5;
    cout << "Nhap sai so epsilon cho Jacobi (mac dinh 1e-5, nhap <= 0 de dung mac dinh): ";
    double inputEps;
    if (cin >> inputEps && inputEps > 0) {
        eps = inputEps;
    }

    cout << "\n========================================\n";
    cout << "MA TRAN A BAN DAU (" << n << "x" << n << "):\n";
    printMatrix(A);
    cout << "========================================\n";

    // ------------------------------------------------------
    // a) Phân rã LDL^T
    // ------------------------------------------------------
    cout << "\n>>> a) PHAN RA LDL^T <<<\n";
    cout << "--- Kiem tra dieu kien phan ra ---\n";

    vector<double> minors;
    bool okLDLT = canLDLT(A, minors);

    if (minors.size() == (size_t)n) {
        cout << "Cac dinh thuc con chinh dan dau (Leading Principal Minors):\n";
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
        cout << "=> Ma tran A doi xung va xac dinh duong. Thoa man dieu kien phan ra LDL^T.\n\n";

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
        cout << "=> KHONG THE phan ra LDL^T vi ma tran A khong thoa man dieu kien (khong doi xung hoac khong xac dinh duong).\n";
    }

    // ------------------------------------------------------
    // b) Phân rã Eigendecomposition (Jacobi)
    // ------------------------------------------------------
    cout << "\n>>> b) PHAN RA TRI RIENG (EIGENDECOMPOSITION) BANG JACOBI <<<\n";
    cout << "--- Kiem tra dieu kien phan ra ---\n";

    if (canEigen(A)) {
        cout << "=> Ma tran A doi xung thuc. Thoa man dieu kien Jacobi.\n\n";

        vector<vector<double>> Q;
        vector<double> lambda;
        eigenDecomposition(A, Q, lambda, eps);

        cout << "Cac tri rieng (Eigenvalues - Lambda):\n";
        printVector(lambda);

        cout << "\nMa tran vector rieng Q (cac cot la cac vector rieng truc chuan tuong ung):\n";
        printMatrix(Q);

        cout << "\nKiem tra Lambda dang ma tran duong cheo:\n";
        vector<vector<double>> Lambda_matrix(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) Lambda_matrix[i][i] = lambda[i];
        printMatrix(Lambda_matrix);
    } else {
        cout << "=> KHONG THE ap dung phuong phap Jacobi vi ma tran A khong doi xung thuc.\n";
    }

    return 0;
}
