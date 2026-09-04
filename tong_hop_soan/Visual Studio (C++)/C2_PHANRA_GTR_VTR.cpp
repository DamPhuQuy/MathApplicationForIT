// Quân



//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//
//using namespace std;
//
//
//const float PI = 3.1415926536898;
//
//
//#define MAX_SIZE 3
//
//
//typedef float MATRIX[MAX_SIZE][MAX_SIZE];
//MATRIX A, P, P1, D;
//
//
//void inputMatrix(MATRIX matrix, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            cout << "Enter matrix[" << i << "][" << j << "]: ";
//            cin >> matrix[i][j];
//        }
//    }
//}
//
//
//void outputMatrix(MATRIX matrix, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            cout << setw(10) << fixed << setprecision(4) << matrix[i][j];
//        }
//        cout << endl;
//    }
//}
//
//
//void multiplyMatrix(MATRIX A, MATRIX B, MATRIX C, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            C[i][j] = 0;
//            for (int k = 0; k < size; k++)
//            {
//                C[i][j] += A[i][k] * B[k][j];
//            }
//        }
//    }
//}
//
//
//void copyMatrix(MATRIX A, MATRIX B, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            B[i][j] = A[i][j];
//        }
//    }
//}
//
//
//void transposeMatrix(MATRIX A, MATRIX B, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            B[i][j] = A[j][i];
//        }
//    }
//}
//
//
//void swap(float& a, float& b)
//{
//    float temp = a;
//    a = b;
//    b = temp;
//}
//
//
//bool isSymmetricMatrix(MATRIX A, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            if (A[i][j] != A[j][i])
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//bool compareMatrix(MATRIX A, MATRIX B, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            if (fabs(A[i][j] - B[i][j]) > 1e-5)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//float inverseMatrix(MATRIX A, int size)
//{
//    MATRIX tmpA = {};
//    MATRIX I = {};
//    copyMatrix(A, tmpA, size);
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            if (i == j)
//            {
//                I[i][j] = 1;
//            }
//            else
//            {
//                I[i][j] = 0;
//            }
//        }
//    }
//
//
//    for (int k = 0; k < size; k++)
//    {
//        float tmp = tmpA[k][k];
//        for (int j = 0; j < size; j++)
//        {
//            tmpA[k][j] /= tmp;
//            I[k][j] /= tmp;
//        }
//
//
//        for (int i = 0; i < size; i++)
//        {
//            if (i == k)
//                continue;
//            float tmp = tmpA[i][k];
//            for (int j = 0; j < size; j++)
//            {
//                tmpA[i][j] -= tmpA[k][j] * tmp;
//                I[i][j] -= I[k][j] * tmp;
//            }
//        }
//    }
//
//
//    copyMatrix(I, A, size);
//    return 0;
//}
//vector<float> solveCubicEquation(vector<float> A)
//{
//    vector<float> sols;
//    float a = A[0], b = A[1], c = A[2], d = A[3];
//
//
//    float Q = (3 * a * c - b * b) / (9 * a * a);
//    float R = (9 * a * b * c - 27 * a * a * d - 2 * b * b * b) / (54 * a * a * a);
//    float D = Q * Q * Q + R * R;
//
//
//    if (D >= 0)
//    {
//        float S = cbrt(R + sqrt(D));
//        float T = cbrt(R - sqrt(D));
//        sols.push_back(-b / (3 * a) + S + T);
//    }
//    else
//    {
//        float theta = acos(R / sqrt(-Q * Q * Q));
//        sols.push_back(2 * sqrt(-Q) * cos(theta / 3) - b / (3 * a));
//        sols.push_back(2 * sqrt(-Q) * cos((theta + 2 * PI) / 3) - b / (3 * a));
//        sols.push_back(2 * sqrt(-Q) * cos((theta + 4 * PI) / 3) - b / (3 * a));
//    }
//    return sols;
//}
//// can't handle 1/ 0
//vector<float> Danhilepxki(MATRIX& A, int n)
//{
//    MATRIX tmpA = {};
//    MATRIX M = {}, M1 = {};
//    MATRIX B = {};
//    MATRIX C = {};
//    copyMatrix(A, tmpA, n);
//    for (int k = n - 2; k >= 0; k--)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (i != k)
//                {
//                    if (i == j)
//                    {
//                        M[i][j] = 1;
//                        M1[i][j] = 1;
//                    }
//                    else
//                    {
//                        M[i][j] = 0;
//                        M1[i][j] = 0;
//                    }
//                }
//                else
//                {
//                    M1[i][j] = tmpA[k + 1][j];
//                    if (j == k)
//                        M[i][j] = 1 / tmpA[k + 1][k];
//                    else
//                    {
//                        M[i][j] = -tmpA[k + 1][j] / tmpA[k + 1][k];
//                    }
//                }
//            }
//        }
//        multiplyMatrix(tmpA, M, B, n);
//        multiplyMatrix(M1, B, tmpA, n);
//
//
//        if (k == n - 2)
//            copyMatrix(M, C, n);
//        else
//        {
//            multiplyMatrix(C, M, B, n);
//            copyMatrix(B, C, n);
//        }
//    }
//    vector<float> lambda;
//    lambda.push_back(1);
//    for (int i = 0; i < n; ++i)
//    {
//        lambda.push_back(-tmpA[0][i]);
//    }
//
//
//    lambda = solveCubicEquation(lambda);
//    sort(lambda.begin(), lambda.end(), greater<float>()); //...
//
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            B[j][i] = pow(lambda[i], n - j - 1);
//        }
//    }
//    multiplyMatrix(C, B, P, n);
//    return lambda;
//}
//
//
//void Diagonalization(int n)
//{
//    vector<float> lambda = Danhilepxki(A, n);
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            if (i == j)
//            {
//                D[i][j] = lambda[i];
//            }
//            else
//            {
//                D[i][j] = 0;
//            }
//        }
//    }
//
//
//    copyMatrix(P, P1, n);
//    inverseMatrix(P1, n);
//    MATRIX diagonalized, hold;
//
//
//    multiplyMatrix(P, D, hold, n);
//    multiplyMatrix(hold, P1, diagonalized, n);
//
//
//    outputMatrix(diagonalized, n);
//
//
//    // return compareMatrix(A, diagonalized, n);
//}
//
//
//void subtractMatrix(MATRIX A, MATRIX B, MATRIX C, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            C[i][j] = A[i][j] - B[i][j];
//        }
//    }
//}
//
//
//int main()
//{
//    int n = 3;
//
//
//    inputMatrix(A, n);
//    Diagonalization(n);
//
//
//    cout << "Diagonalization successfully!" << endl;
//    cout << "Matrix P: " << endl;
//    outputMatrix(P, n);
//    cout << "Matrix D: " << endl;
//    outputMatrix(D, n);
//    cout << "Matrix P1: " << endl;
//    outputMatrix(P1, n);
//    cout << "Test secure: " << endl;
//    MATRIX hold, test;
//    multiplyMatrix(P, D, hold, n);
//    multiplyMatrix(hold, P1, test, n);
//    cout << "A - PDP1: " << endl;
//    MATRIX diff;
//    subtractMatrix(A, test, diff, n);
//    outputMatrix(diff, n);
//    return 0;
//}


// KHOA

//#include <iostream>
////#include <Eigen/Dense>
//#include "library/eigen/Eigen/Dense"
//using namespace std;
//using namespace Eigen;
//
//// Hàm kiểm tra ma trận có đối xứng không
//bool is_symmetric(const MatrixXd& matrix) {
//    return matrix.isApprox(matrix.transpose());
//}
//
//int main() {
//    int n;
//    cout << "Nhập kích thước của ma trận vuông (n): ";
//    cin >> n;
//
//    // Nhập ma trận A từ người dùng
//    MatrixXd A(n, n);
//    cout << "Nhập ma trận A:" << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << "A[" << i + 1 << "," << j + 1 << "]: ";
//            cin >> A(i, j);
//        }
//    }
//
//    // Kiểm tra nếu ma trận là ma trận đối xứng
//    if (is_symmetric(A)) {
//        cout << "\nMa trận đối xứng." << endl;
//
//        // Phân rã giá trị riêng cho ma trận đối xứng
//        SelfAdjointEigenSolver<MatrixXd> solver(A);
//        VectorXd eigenvalues = solver.eigenvalues();
//        MatrixXd eigenvectors = solver.eigenvectors();
//
//        // In ra các kết quả
//        cout << "\nMa trận vectơ riêng (cột) V:" << endl;
//        cout << eigenvectors << endl;
//
//        cout << "\nMa trận đường chéo D (chứa giá trị riêng):" << endl;
//        cout << eigenvalues.asDiagonal() << endl;
//
//        cout << "\nMa trận chuyển vị của V:" << endl;
//        cout << eigenvectors.transpose() << endl;
//    }
//    else {
//        cout << "\nMa trận không đối xứng." << endl;
//
//        // Phân rã giá trị riêng cho ma trận không đối xứng
//        EigenSolver<MatrixXd> solver(A);
//        MatrixXd eigenvectors = solver.eigenvectors().real();
//        VectorXd eigenvalues = solver.eigenvalues().real();
//
//        // Tạo ma trận nghịch đảo của vectơ riêng
//        MatrixXd V_inverse = eigenvectors.inverse();
//
//        // In ra các kết quả
//        cout << "\nMa trận vectơ riêng (cột) V:" << endl;
//        cout << eigenvectors << endl;
//
//        cout << "\nMa trận đường chéo D (chứa giá trị riêng):" << endl;
//        cout << eigenvalues.asDiagonal() << endl;
//
//        cout << "\nMa trận nghịch đảo của V:" << endl;
//        cout << V_inverse << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <windows.h> // Thêm thư viện này để xử lý mã hóa
//#include "library/eigen/Eigen/Dense"
//
//using namespace std;
//using namespace Eigen;
//
//// Hàm kiểm tra ma trận có đối xứng không
//bool is_symmetric(const MatrixXd& matrix) {
//    return matrix.isApprox(matrix.transpose());
//}
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8); // Thiết lập mã hóa UTF-8 cho đầu ra console
//
//    int n;
//    cout << "Nhap kich thuoc cua ma tran vuong (n): ";
//    cin >> n;
//
//    // Nhập ma trận A từ người dùng
//    MatrixXd A(n, n);
//    cout << "Nhap ma tran A:" << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << "A[" << i + 1 << "," << j + 1 << "]: ";
//            cin >> A(i, j);
//        }
//    }
//
//    // Kiểm tra nếu ma trận là ma trận đối xứng
//    if (is_symmetric(A)) {
//        cout << "\nMa tran doi xung." << endl;
//
//        // Phân rã giá trị riêng cho ma trận đối xứng
//        SelfAdjointEigenSolver<MatrixXd> solver(A);
//        VectorXd eigenvalues = solver.eigenvalues();
//        MatrixXd eigenvectors = solver.eigenvectors();
//
//        // In ra các kết quả
//        cout << "\nMa tran vector rieng (cot) V:" << endl;
//        cout << eigenvectors << endl;
//
//        cout << "\nMa tran duong cheo D (chua gia tri rieng):" << endl;
//        cout << eigenvalues.asDiagonal().toDenseMatrix() << endl;
//
//        cout << "\nMa tran chuyen vi cua V:" << endl;
//        cout << eigenvectors.transpose() << endl;
//    }
//    else {
//        cout << "\nMa tran khong doi xung." << endl;
//
//        // Phân rã giá trị riêng cho ma trận không đối xứng
//        EigenSolver<MatrixXd> solver(A);
//        MatrixXd eigenvectors = solver.eigenvectors().real();
//        VectorXd eigenvalues = solver.eigenvalues().real();
//
//        // Tạo ma trận nghịch đảo của vectơ riêng
//        MatrixXd V_inverse = eigenvectors.inverse();
//
//        // In ra các kết quả
//        cout << "\nMa tran vector rieng (cot) V:" << endl;
//        cout << eigenvectors << endl;
//
//        cout << "\nMa tran duong cheo D (chua gia tri rieng):" << endl;
//        cout << eigenvalues.asDiagonal().toDenseMatrix() << endl;
//
//        cout << "\nMa tran nghich dao cua V:" << endl;
//        cout << V_inverse << endl;
//    }
//
//    return 0;
//}


