#include <iostream>
#include <vector>

using namespace std;

// Hàm nhân ma trận
vector<vector<double>> matrixMultiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int m = A.size(); // Số hàng của ma trận A
    int n = B[0].size(); // Số cột của ma trận B
    int p = B.size(); // Số cột của ma trận A (số hàng của ma trận B)

    vector<vector<double>> result(m, vector<double>(n, 0.0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Ma trận trạng thái
    vector<vector<double>> P = {
        {0.09, 0.31, 0.38, 0.22},
        {0.18, 0.16, 0.44, 0.22},
        {0.17, 0.26, 0.23, 0.34},
        {0.23, 0.37, 0.24, 0.16}
    };

    // Trạng thái ban đầu (hệ thống bắt đầu ở trạng thái 2)
    vector<vector<double>> initial_state = {{0.0, 1.0, 0.0, 0.0}};

    // Số bước thời gian
    int steps = 4;

    // Tính xác suất sau mỗi bước
    vector<vector<double>> current_state = initial_state;
    for (int i = 1; i <= steps; ++i) {
        current_state = matrixMultiply(current_state, P);
        if (i == 3 || i == 4)
            cout << "Xac suat sau " << i << " buoc: " << current_state[0][2] << endl;
    }

    return 0;
}