#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#include <Eigen/Dense>
 
class Matrix {
   int row, col;
   double **data = nullptr;
public:
   Matrix(int row = 0, int col = 0);
   Matrix(const Matrix &other);
   ~Matrix();
   Matrix Transpose();
   bool IsSquare();
   double Det();
   int Row() const;
   int Col() const;
   Matrix GetColumn(int k);
   Matrix &operator=(const Matrix &other); 
   double &operator()(int row, int col);
   double operator()(int row, int col) const; 
 
   operator Eigen::MatrixXd() const;
   
   friend ostream &operator<<(ostream &os, const Matrix &m);
   friend istream &operator>>(istream &is, Matrix &m);
   friend Matrix operator*(const Matrix &a, const Matrix &b);
 
   friend Matrix operator/(const Matrix &m, double k);
};
 
void Calculate_Sigma_and_V(Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> &solver, Matrix &Sigma, Matrix &V) {
   int m = V.Row();
 
   vector<pair<double, int>> eigen_vals;
   for (int i = 0; i < m; ++i) {
       eigen_vals.push_back({solver.eigenvalues()(i), i});
   }
 
   sort(eigen_vals.begin(), eigen_vals.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
       return a.first > b.first;
   });
 
   for (int i = 0; i < m; ++i) {
       for (int j = 0; j < Sigma.Row(); ++j) {
           Sigma(j, i) = 0; 
       }
 
       double val = eigen_vals[i].first;
       Sigma(i, i) = (val > 1e-5) ? sqrt(val) : 0.0;
 
       int original_idx = eigen_vals[i].second;
       for (int j = 0; j < m; ++j) {
           V(j, i) = solver.eigenvectors()(j, original_idx);
       }
   }
}
 
void Calculate_U(Matrix &Sigma, Matrix &A, Matrix &V, Matrix &U) {
   int n = U.Row();
   int m = V.Col(); 
   int count = 0;   
 
   for(int i = 0; i < m; ++i) {
       if(Sigma(i, i) < 1e-5) continue;
       
       Matrix Vi = V.GetColumn(i);
       Matrix Ui = A * Vi;
       Ui = Ui / Sigma(i, i); 
       
       for(int j = 0; j < n; ++j) {
           U(j, count) = Ui(j, 0);
       }
       count++;
   }
 
   for (int i = 0; i < n && count < n; ++i) {
       Matrix v(n, 1);
       for (int j = 0; j < n; ++j) {
           v(j, 0) = (i == j) ? 1.0 : 0.0;
       }
 
       for (int j = 0; j < count; ++j) {
           double dot_product = 0;
           for (int k = 0; k < n; ++k) {
               dot_product += U(k, j) * v(k, 0);
           }
           for (int k = 0; k < n; ++k) {
               v(k, 0) -= dot_product * U(k, j);
           }
       }
 
       double norm = 0;
       for (int k = 0; k < n; ++k) {
           norm += v(k, 0) * v(k, 0);
       }
       norm = sqrt(norm);
       if (norm > 1e-5) {
           for (int k = 0; k < n; ++k) {
               U(k, count) = v(k, 0) / norm;
           }
           count++;
       }
   }
}
 
void PrintAnswer(Matrix &U, Matrix &Sigma, Matrix &V, bool transpose) {
   if(!transpose) {
       cout << "U: " << endl << U << endl;
       cout << "Sigma: " << endl << Sigma << endl;
       cout << "VT: " << endl << V.Transpose() << endl;
       cout << "U * Sigma * VT: " << endl << U * Sigma * V.Transpose() << endl;
   }
   else {
       cout << "U: " << endl << V << endl;
       cout << "Sigma: " << endl << Sigma.Transpose() << endl;
       cout << "VT: " << endl << U.Transpose() << endl;
       cout << "U * Sigma * VT: " << endl << V * Sigma.Transpose() * U.Transpose() << endl;
   }
}
 
int main() {
   bool isTranspose = false;
   int n, m;
   cout << "Nhap kich thuoc ma tran: ";
   cin >> n >> m;
   Matrix A(n, m);
   cout << "Nhap ma tran A: " << endl;
   cin >> A;
   
   if(n < m) {
       isTranspose = true;
       swap(n, m);
       A = A.Transpose();
   }
   
   Matrix U(n, n), Sigma(n, m), V(m, m);
   Matrix S = A.Transpose() * A;
   
   Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> solver((Eigen::MatrixXd)S);
   
   Calculate_Sigma_and_V(solver, Sigma, V);
   Calculate_U(Sigma, A, V, U);
   PrintAnswer(U, Sigma, V, isTranspose);
   
   return 0;
}
 
Matrix::Matrix(int row, int col) : row(row), col(col) {
   data = new double*[row];
   for(int i = 0; i < row; ++i) {
       data[i] = new double[col];
       for (int j = 0; j < col; ++j) data[i][j] = 0; 
   }
}
 
Matrix::Matrix(const Matrix &other) : row(other.row), col(other.col) {
   data = new double*[row];
   for(int i = 0; i < row; ++i) {
       data[i] = new double[col];
       for(int j = 0; j < col; ++j)
           data[i][j] = other.data[i][j];
   }
}
 
Matrix::~Matrix() {
   for(int i = 0; i < row; ++i) {
       delete[] data[i];
   }
   delete[] data;
}
 
Matrix Matrix::Transpose() {
   Matrix T(col, row);
   for(int i = 0; i < col; ++i) {
       for(int j = 0; j < row; ++j) {
           T.data[i][j] = data[j][i];
       }
   }
   return T;
}
 
bool Matrix::IsSquare() {
   return row == col;
}
 
double Matrix::Det() {
   if(!IsSquare()) throw invalid_argument("Ma tran tinh dinh thuc phai la ma tran vuong");
   double res = 1;
   for(int i = 0; i < row; ++i) {
       if(data[i][i] == 0) {
           for(int j = i + 1; j < row; ++j) {
               if(data[j][i] != 0) {
                   for(int k = 0; k < col; ++k) {
                       double t = data[i][k];
                       data[i][k] = data[j][k];
                       data[j][k] = t;
                   }
               }
           }
       }
       if(data[i][i] == 0) return 0;
       res = res * data[i][i];
       for(int j = i + 1; j < row; ++j) {
           double ratio = -data[j][i]/data[i][i];
           for(int k = i; k < col; ++k) {
               data[j][k] = data[i][k] * ratio + data[j][k];
           }
       }
   }
   return res;
}
 
int Matrix::Row() const { return row; }
int Matrix::Col() const { return col; }
 
Matrix Matrix::GetColumn(int k) {
   Matrix res(row, 1);
   for(int i = 0; i < row; ++i) {
       res(i, 0) = data[i][k];
   }
   return res;
}
 
Matrix &Matrix::operator=(const Matrix& other) { 
   if (this == &other) return *this; 
 
   for(int i = 0; i < row; ++i) {
       delete[] data[i];
   }
   delete[] data; 
 
   row = other.row;
   col = other.col;
   data = new double*[row];
   for(int i = 0; i < row; ++i) {
       data[i] = new double[col];
       for(int j = 0; j < col; ++j) {
           data[i][j] = other.data[i][j];
       }
   }
   return *this;
}
 
double &Matrix::operator()(int row, int col) {
   return data[row][col];
}
 
double Matrix::operator()(int row, int col) const {
   return data[row][col];
}
 
Matrix::operator Eigen::MatrixXd() const {
   Eigen::MatrixXd res(row, col);
   for(int i = 0; i < row; ++i) {
       for(int j = 0; j < col; ++j) {
           res(i, j) = data[i][j];
       }
   }
   return res;
}
 
ostream &operator<<(ostream &os, const Matrix &m) {
   os << fixed << setprecision(5);
   
   for(int i = 0; i < m.row; ++i) {
       for(int j = 0; j < m.col; ++j) {
           double val = m.data[i][j];
           if (abs(val) < 1e-5) val = 0.0; 
           os << setw(12) << val << " ";
       }
       os << endl;
   }
 
   os.unsetf(ios_base::fixed);
   return os;
}
 
istream &operator>>(istream &is, Matrix &m) {
   for(int i = 0; i < m.row; ++i) {
       for(int j = 0; j < m.col; ++j) {
           is >> m.data[i][j];
       }
   }
   return is;
}
 
Matrix operator*(const Matrix &a, const Matrix &b) {
   if(a.col != b.row) 
       throw invalid_argument("Kich thuoc 2 ma tran khi nhan khong hop le");
   Matrix res(a.row, b.col);
   for(int i = 0; i < a.row; ++i) {
       for(int j = 0; j < b.col; ++j) {  
           double sum = 0;              
           for(int k = 0; k < b.row; ++k) {
               sum += a.data[i][k] * b.data[k][j];
           }
           res.data[i][j] = sum;
       }   
   }    
   return res;
}
 
Matrix operator/(const Matrix &m, double k) {
   Matrix res(m.Row(), m.Col());
   for(int i = 0; i < m.Row(); ++i) {
       for(int j = 0; j < m.Col(); ++j) {
           res(i, j) = m(i, j) / k;
       }
   }
   return res;
}
