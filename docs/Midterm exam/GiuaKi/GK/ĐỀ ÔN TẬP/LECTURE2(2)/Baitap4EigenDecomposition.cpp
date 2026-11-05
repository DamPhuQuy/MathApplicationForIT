#include <iostream>
#include <iomanip>
#include <cmath>
#include <Eigen/Dense> 

using namespace std;
using namespace Eigen;

const int MAX = 100;

void Nhan2MaTran(float A[][MAX], float B[][MAX], float C[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Hàm tính định thức (Det)
float det(float a[][MAX], int n) {
    int i, j, k, dem = 0, kt;
    float b[MAX], h, kq = 1;
    for (i = 0; i < n - 1; i++) {
        if (a[i][i] == 0) {
            kt = 0;
            for (j = i + 1; j < n; j++) {
                if (a[i][j] != 0) {
                    for (k = 0; k < n; k++) {
                        float t = a[k][i];
                        a[k][i] = a[k][j];
                        a[k][j] = t;
                    }
                    dem++; kt++; break;
                }
            }
            if (kt == 0) return 0;
        }
        b[i] = a[i][i];
        for (j = 0; j < n; j++) a[i][j] /= b[i];
        for (j = i + 1; j < n; j++) {
            h = a[j][i];
            for (k = 0; k < n; k++) a[j][k] = a[j][k] - h * a[i][k];
        }
    }
    b[n - 1] = a[n - 1][n - 1];
    for (i = 0; i < n; i++) kq *= b[i];
    if (dem % 2 == 0) return kq;
    return -kq;
}

// Tính định thức ma trận con
float con(float a[][MAX], int n, int h, int c) {
    float b[MAX][MAX];
    int x = -1, y;
    for (int i = 0; i < n; i++) {
        if (i == h) continue;
        x++; y = -1;
        for (int j = 0; j < n; j++) {
            if (j == c) continue;
            y++;
            b[x][y] = a[i][j];
        }
    }
    if ((h + c) % 2 == 0) return det(b, n - 1);
    return -det(b, n - 1);
}

// Hàm tìm ma trận nghịch đảo
void nghichdao(float a[][MAX], float b[][MAX], int n) {
    float temp[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) temp[i][j] = a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) b[i][j] = con(a, n, i, j);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            float t = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = t;
        }

    float k = det(a, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a[i][j] = temp[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) b[i][j] /= k;
}

// Hàm in ma trận
void inMaTran(float A[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (abs(A[i][j]) < 1e-6) A[i][j] = 0.0;
            cout << setw(8) << setprecision(3) << fixed << A[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int n;
    cout << "Nhap kich thuoc ma tran vuong n = ";
    cin >> n;

    float A[MAX][MAX];
    MatrixXd Eigen_A(n, n); 

    cout << "--- Nhap ma tran A ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
            Eigen_A(i, j) = A[i][j]; 
        }
    }

    EigenSolver<MatrixXd> solver(Eigen_A);
    VectorXd eigen_vals = solver.eigenvalues().real();
    MatrixXd eigen_vecs = solver.eigenvectors().real();

    float D[MAX][MAX] = {0}; 
    float V[MAX][MAX] = {0}; 

    for (int i = 0; i < n; i++) {
        D[i][i] = eigen_vals(i); 
        for (int j = 0; j < n; j++) {
            V[i][j] = eigen_vecs(i, j); 
        }
    }

    float V_inv[MAX][MAX];
    nghichdao(V, V_inv, n);

    // 4. IN KẾT QUẢ
    cout << "\n--- MA TRAN V (Vecto rieng) ---\n";
    inMaTran(V, n);

    cout << "\n--- MA TRAN D (Gia tri rieng) ---\n";
    inMaTran(D, n);

    cout << "\n--- MA TRAN V^-1 (Nghich dao) ---\n";
    inMaTran(V_inv, n);

    float Temp[MAX][MAX];
    float Reconstruct[MAX][MAX];
    
    Nhan2MaTran(V, D, Temp, n);          
    Nhan2MaTran(Temp, V_inv, Reconstruct, n); 

    cout << "\n(V * D * V^-1)\n";
    inMaTran(Reconstruct, n);

    return 0;
}