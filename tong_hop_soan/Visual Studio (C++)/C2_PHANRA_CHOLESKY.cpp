//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//// Hàm phân rã Cholesky
//int check = 1;
//void cholesky_decomposition(double** matrix, double** L, int n) {
//    int i, j, k;
//    double sum;
//    // Khoi tao ma tran l voi gia tri 0
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            L[i][j] = 0.0;
//        }
//    }
//    // Phân rã Cholesky
//    for (i = 0; i < n; i++) {
//
//        for (j = 0; j <= i; j++) {
//            sum = matrix[i][j];
//            for (k = 0; k < j; k++) {
//                sum -= L[i][k] * L[j][k];
//                if (sum <= 0) {
//                    printf("ma tran khong phai la ma tran xac dinh duong");
//                    check = 0;
//                    return;
//                }
//            }
//            if (i == j) {
//                L[i][j] = sqrt(sum);
//
//            }
//            else {
//                L[i][j] = sum / L[j][j];
//            }
//        }
//    }
//}
//// Hàm in ma tran
//void print_matrix(double** matrix, int n) {
//    int i, j;
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%6.2f ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n\n\n");
//}
//void print_matrix_T(double** matrix, int n) {
//    int i, j;
//    double T[n][n];
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            T[i][j] = matrix[j][i];
//            printf("%6.2f ", T[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main() {
//    int n, i, j;
//    double** A, ** L;
//
//    // Nhap kich thuoc ma tran
//    printf("Nhap kích thuoc ma tran: ");
//    scanf("%d", &n);
//
//    // Cap phát bo nho cho ma tran A và L
//    A = (double**)malloc(n * sizeof(double*));
//    L = (double**)malloc(n * sizeof(double*));
//    for (i = 0; i < n; i++) {
//        A[i] = (double*)malloc(n * sizeof(double));
//        L[i] = (double*)malloc(n * sizeof(double));
//    }
//
//    // Nhap ma tran tu nguoi dùng
//    printf("Nhap ma tran %dx%d:\n", n, n);
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            printf("A[%d][%d] = ", i, j);
//            scanf("%lf", &A[i][j]);
//        }
//    }
//
//    // Kiem tra ma tran co phai la doi xung,kiem tra mt xacdinh duong o trong ham phan ra phia tren
//    for (i = 0; i < n; i++) {
//        for (j = i + 1; j < n; j++) {
//            if (fabs(A[i][j] - A[j][i]) > 1e-9) {
//                printf("Ma tran không phai là doi xung.\n");
//
//                // Giai phóng bo nho
//                for (i = 0; i < n; i++) {
//                    free(A[i]);
//                    free(L[i]);
//                }
//                free(A);
//                free(L);
//
//                return 1;
//            }
//        }
//    }
//
//    // thuc hien phan ra
//    cholesky_decomposition(A, L, n);
//
//    // In ma tran L:
//    if (check != 0) {
//        printf("Ma tran L:\n");
//        print_matrix(L, n);
//        print_matrix_T(L, n);
//
//    }
//    //    printf("Ma tran L:\n");
//    //    print_matrix(L, n);
//    //    print_matrix_T(L,n);
//
//        // Giai phong bo nho:
//    for (i = 0; i < n; i++) {
//        free(A[i]);
//        free(L[i]);
//    }
//    free(A);
//    free(L);
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//// Hàm phân rã Cholesky
//int check = 1;
//void cholesky_decomposition(const vector<vector<double>>& matrix, vector<vector<double>>& L, int n) {
//    int i, j, k;
//    double sum;
//    // Khởi tạo ma trận L với giá trị 0
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            L[i][j] = 0.0;
//        }
//    }
//    // Phân rã Cholesky
//    for (i = 0; i < n; i++) {
//        for (j = 0; j <= i; j++) {
//            sum = matrix[i][j];
//            for (k = 0; k < j; k++) {
//                sum -= L[i][k] * L[j][k];
//                if (sum <= 0) {
//                    cout << "Ma tran khong phai la ma tran xac dinh duong" << endl;
//                    check = 0;
//                    return;
//                }
//            }
//            if (i == j) {
//                L[i][j] = sqrt(sum);
//            }
//            else {
//                L[i][j] = sum / L[j][j];
//            }
//        }
//    }
//}
//
//// Hàm in ma trận
//void print_matrix(const vector<vector<double>>& matrix, int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << fixed << setprecision(2) << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void print_matrix_T(const vector<vector<double>>& matrix, int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << fixed << setprecision(2) << matrix[j][i] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int n;
//    cout << "Nhap kich thuoc ma tran: ";
//    cin >> n;
//
//    vector<vector<double>> A(n, vector<double>(n));
//    vector<vector<double>> L(n, vector<double>(n));
//
//    // Nhập ma trận từ người dùng
//    cout << "Nhap ma tran " << n << "x" << n << ":\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << "A[" << i << "][" << j << "] = ";
//            cin >> A[i][j];
//        }
//    }
//
//    // Kiểm tra ma trận có phải là đối xứng
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (fabs(A[i][j] - A[j][i]) > 1e-9) {
//                cout << "Ma tran khong phai la doi xung." << endl;
//                return 1;
//            }
//        }
//    }
//
//    // Thực hiện phân rã Cholesky
//    cholesky_decomposition(A, L, n);
//
//    // In ma trận L
//    if (check != 0) {
//        cout << "Ma tran L:\n";
//        print_matrix(L, n);
//        cout << "Ma tran L^T:\n";
//        print_matrix_T(L, n);
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <iomanip> // Thêm thư viện này
//
//using namespace std;
//
//// Hàm phân rã Cholesky
//int check = 1;
//void cholesky_decomposition(const vector<vector<double>>& matrix, vector<vector<double>>& L, int n) {
//    int i, j, k;
//    double sum;
//    // Khởi tạo ma trận L với giá trị 0
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            L[i][j] = 0.0;
//        }
//    }
//    // Phân rã Cholesky
//    for (i = 0; i < n; i++) {
//        for (j = 0; j <= i; j++) {
//            sum = matrix[i][j];
//            for (k = 0; k < j; k++) {
//                sum -= L[i][k] * L[j][k];
//                if (sum <= 0) {
//                    cout << "Ma tran khong phai la ma tran xac dinh duong" << endl;
//                    check = 0;
//                    return;
//                }
//            }
//            if (i == j) {
//                L[i][j] = sqrt(sum);
//            }
//            else {
//                L[i][j] = sum / L[j][j];
//            }
//        }
//    }
//}
//
//// Hàm in ma trận
//void print_matrix(const vector<vector<double>>& matrix, int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << std::fixed << std::setprecision(2) << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void print_matrix_T(const vector<vector<double>>& matrix, int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << std::fixed << std::setprecision(2) << matrix[j][i] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int n;
//    cout << "Nhap kich thuoc ma tran: ";
//    cin >> n;
//
//    vector<vector<double>> A(n, vector<double>(n));
//    vector<vector<double>> L(n, vector<double>(n));
//
//    // Nhập ma trận từ người dùng
//    cout << "Nhap ma tran " << n << "x" << n << ":\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << "A[" << i << "][" << j << "] = ";
//            cin >> A[i][j];
//        }
//    }
//
//    // Kiểm tra ma trận có phải là đối xứng
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (fabs(A[i][j] - A[j][i]) > 1e-9) {
//                cout << "Ma tran khong phai la doi xung." << endl;
//                return 1;
//            }
//        }
//    }
//
//    // Thực hiện phân rã Cholesky
//    cholesky_decomposition(A, L, n);
//
//    // In ma trận L
//    if (check != 0) {
//        cout << "Ma tran L:\n";
//        print_matrix(L, n);
//        cout << "Ma tran L^T:\n";
//        print_matrix_T(L, n);
//    }
//
//    return 0;
//}
