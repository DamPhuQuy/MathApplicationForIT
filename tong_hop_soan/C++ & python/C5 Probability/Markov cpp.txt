#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

Matrix nhap_ma_tran_markov(int n) {
    Matrix mat(n, Vector(n));
    cout << "Nhập ma trận Markov " << n << "x" << n << " (các hàng phải cộng lại bằng 1):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Nhập phần tử tại hàng " << i + 1 << ", cột " << j + 1 << ": ";
            cin >> mat[i][j];
        }
        double row_sum = 0;
        for (int j = 0; j < n; ++j) {
            row_sum += mat[i][j];
        }
        if (fabs(row_sum - 1.0) > 1e-6) {
            throw invalid_argument("Tổng các phần tử của hàng " + to_string(i + 1) + " phải bằng 1!");
        }
    }
    return mat;
}

Vector nhap_trang_thai_ban_dau(int n) {
    Vector vec(n);
    cout << "Nhập từng giá trị trong vector trạng thái ban đầu:" << endl;
    double vec_sum = 0;
    for (int i = 0; i < n; ++i) {
        cout << "Nhập phần tử trạng thái ban đầu tại vị trí " << i + 1 << ": ";
        cin >> vec[i];
        vec_sum += vec[i];
    }
    if (fabs(vec_sum - 1.0) > 1e-6) {
        throw invalid_argument("Tổng các giá trị trong vector trạng thái ban đầu phải bằng 1!");
    }
    return vec;
}

Matrix matrix_power(const Matrix& mat, int n) {
    int size = mat.size();
    Matrix result(size, Vector(size, 0));
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1.0;
    }

    Matrix base = mat;
    while (n) {
        if (n % 2) {
            Matrix temp(size, Vector(size, 0));
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    for (int k = 0; k < size; ++k) {
                        temp[i][j] += result[i][k] * base[k][j];
                    }
                }
            }
            result = temp;
        }
        Matrix temp(size, Vector(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    temp[i][j] += base[i][k] * base[k][j];
                }
            }
        }
        base = temp;
        n /= 2;
    }
    return result;
}

Vector tinh_xac_suat_sau_n_buoc(const Matrix& markov, const Vector& trang_thai_ban_dau, int n) {
    Matrix markov_n = matrix_power(markov, n);
    int size = markov_n.size();
    Vector ket_qua(size, 0);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ket_qua[i] += trang_thai_ban_dau[j] * markov_n[j][i];
        }
    }
    return ket_qua;
}

int main() {
    try {
        int n;
        cout << "Nhập số trạng thái (kích thước ma trận Markov) n = ";
        cin >> n;
        if (n <= 0) {
            throw invalid_argument("Số trạng thái phải lớn hơn 0!");
        }

        Matrix markov = nhap_ma_tran_markov(n);
        cout << "Ma trận Markov đã nhập:" << endl;
        for (const auto& row : markov) {
            for (double value : row) {
                cout << value << " ";
            }
            cout << endl;
        }

        Vector trang_thai_ban_dau = nhap_trang_thai_ban_dau(n);
        cout << "Vector trạng thái ban đầu:" << endl;
        for (double value : trang_thai_ban_dau) {
            cout << value << " ";
        }
        cout << endl;

        int buoc;
        cout << "Nhập số bước n = ";
        cin >> buoc;
        if (buoc < 0) {
            throw invalid_argument("Số bước phải là số không âm!");
        }

        // Tính xác suất trạng thái sau n bước
        Vector ket_qua = tinh_xac_suat_sau_n_buoc(markov, trang_thai_ban_dau, buoc);
        cout << "Xác suất trạng thái sau " << buoc << " bước:" << endl;
        for (double value : ket_qua) {
            cout << value << " ";
        }
        cout << endl;

    } catch (const exception& e) {
        cout << "Lỗi: " << e.what() << endl;
    }

    return 0;
}
