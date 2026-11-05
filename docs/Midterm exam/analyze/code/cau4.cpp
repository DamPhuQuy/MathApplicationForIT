#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// In ma trận
void printMatrix(const vector<vector<double>>& A) {
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A[i].size(); j++) {
            double val = A[i][j];
            if (fabs(val) < 1e-12) val = 0;
            cout << setw(12) << fixed << setprecision(6) << val;
        }
        cout << '\n';
    }
}

// Chuyển vị ma trận
vector<vector<double>> transpose(const vector<vector<double>>& A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<double>> AT(n, vector<double>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            AT[j][i] = A[i][j];
    return AT;
}

// Nhân hai ma trận
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int m = A.size();
    int p = A[0].size();
    int n = B[0].size();

    vector<vector<double>> C(m, vector<double>(n, 0.0));
    for (int i = 0; i < m; i++)
        for (int k = 0; k < p; k++)
            for (int j = 0; j < n; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Tìm trị riêng và vector riêng bằng Jacobi cho ma trận đối xứng thực S (n x n)
void eigenJacobi(vector<vector<double>> S,
                 vector<vector<double>>& V,
                 vector<double>& lambda,
                 double eps) {
    int n = S.size();

    V.assign(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
        V[i][i] = 1.0;

    while (true) {
        int p = 0, q = 1;
        double maxVal = fabs(S[0][1]);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (fabs(S[i][j]) > maxVal) {
                    maxVal = fabs(S[i][j]);
                    p = i;
                    q = j;
                }
            }
        }

        if (maxVal < eps)
            break;

        double theta = 0.5 * atan2(2.0 * S[p][q], S[p][p] - S[q][q]);
        double c = cos(theta);
        double s = sin(theta);

        double Spp = S[p][p];
        double Sqq = S[q][q];
        double Spq = S[p][q];

        S[p][p] = c * c * Spp + 2.0 * c * s * Spq + s * s * Sqq;
        S[q][q] = s * s * Spp - 2.0 * c * s * Spq + c * c * Sqq;
        S[p][q] = S[q][p] = 0.0;

        for (int k = 0; k < n; k++) {
            if (k != p && k != q) {
                double Skp = S[k][p];
                double Skq = S[k][q];

                S[k][p] = S[p][k] = c * Skp + s * Skq;
                S[k][q] = S[q][k] = -s * Skp + c * Skq;
            }
        }

        for (int k = 0; k < n; k++) {
            double Vkp = V[k][p];
            double Vkq = V[k][q];

            V[k][p] = c * Vkp + s * Vkq;
            V[k][q] = -s * Vkp + c * Vkq;
        }
    }

    lambda.resize(n);
    for (int i = 0; i < n; i++)
        lambda[i] = (S[i][i] < 0.0 && S[i][i] > -1e-10) ? 0.0 : S[i][i];
}

// Phân rã SVD trường hợp m >= n
void svdCore(const vector<vector<double>>& A,
             vector<vector<double>>& U,
             vector<vector<double>>& Sigma,
             vector<vector<double>>& V,
             double eps) {
    int m = A.size();
    int n = A[0].size();

    // S = A^T * A
    vector<vector<double>> AT = transpose(A);
    vector<vector<double>> S = multiply(AT, A);

    vector<vector<double>> V_raw;
    vector<double> lambda_raw;
    eigenJacobi(S, V_raw, lambda_raw, eps);

    // Sắp xếp trị riêng giảm dần
    vector<pair<double, int>> order(n);
    for (int i = 0; i < n; i++)
        order[i] = {lambda_raw[i], i};

    sort(order.begin(), order.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    });

    vector<double> lambda(n);
    V.assign(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        lambda[i] = max(0.0, order[i].first);
        int oldCol = order[i].second;
        for (int r = 0; r < n; r++)
            V[r][i] = V_raw[r][oldCol];
    }

    // Giá trị kỳ dị sigma_i = sqrt(lambda_i)
    vector<double> sigma(min(m, n), 0.0);
    for (int i = 0; i < min(m, n); i++)
        sigma[i] = sqrt(lambda[i]);

    // Ma trận Sigma (m x n)
    Sigma.assign(m, vector<double>(n, 0.0));
    for (int i = 0; i < min(m, n); i++)
        Sigma[i][i] = sigma[i];

    // Tính các cột u_i = A * v_i / sigma_i
    vector<vector<double>> U_cols;
    for (int i = 0; i < min(m, n); i++) {
        if (sigma[i] > eps) {
            vector<double> ui(m, 0.0);
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++)
                    ui[r] += A[r][c] * V[c][i];
                ui[r] /= sigma[i];
            }
            U_cols.push_back(ui);
        }
    }

    // Bổ sung các cột trực giao bằng Gram-Schmidt nếu rank < m
    for (int col = 0; col < m && (int)U_cols.size() < m; col++) {
        vector<double> cand(m, 0.0);
        cand[col] = 1.0;

        for (const auto& uj : U_cols) {
            double dot = 0.0;
            for (int r = 0; r < m; r++) dot += uj[r] * cand[r];
            for (int r = 0; r < m; r++) cand[r] -= dot * uj[r];
        }

        double norm = 0.0;
        for (int r = 0; r < m; r++) norm += cand[r] * cand[r];
        norm = sqrt(norm);

        if (norm > 1e-7) {
            for (int r = 0; r < m; r++) cand[r] /= norm;
            U_cols.push_back(cand);
        }
    }

    U.assign(m, vector<double>(m, 0.0));
    for (int c = 0; c < m; c++)
        for (int r = 0; r < m; r++)
            U[r][c] = U_cols[c][r];
}

// Phân rã SVD tổng quát cho ma trận m x n
void SVD(const vector<vector<double>>& A,
         vector<vector<double>>& U,
         vector<vector<double>>& Sigma,
         vector<vector<double>>& V,
         double eps) {
    int m = A.size();
    int n = A[0].size();

    if (m >= n) {
        svdCore(A, U, Sigma, V, eps);
    } else {
        vector<vector<double>> AT = transpose(A);
        vector<vector<double>> U_t, Sigma_t, V_t;
        svdCore(AT, U_t, Sigma_t, V_t, eps);

        U = V_t;
        Sigma = transpose(Sigma_t);
        V = U_t;
    }
}

int main() {
    int m, n;
    cout << "Nhap so hang va so cot: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    double eps = 1e-5;

    vector<vector<double>> U, Sigma, V;
    SVD(A, U, Sigma, V, eps);

    vector<vector<double>> VT = transpose(V);

    cout << "\n=== SVD ===\n";

    cout << "U =\n";
    printMatrix(U);

    cout << "\nSigma =\n";
    printMatrix(Sigma);

    cout << "\nVT =\n";
    printMatrix(VT);

    cout << "\nU * Sigma * VT =\n";
    vector<vector<double>> A_rec = multiply(multiply(U, Sigma), VT);
    printMatrix(A_rec);

    return 0;
}
