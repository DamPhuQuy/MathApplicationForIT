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
        {0.0, 0.5, 0.3, 0.2},
        {0.1, 0.2, 0.55, 0.15},
        {0.4, 0.3, 0.2, 0.1},
        {0.0, 0.25, 0.35, 0.4}
    };

    // Trạng thái ban đầu (hệ thống bắt đầu ở trạng thái 3)
    vector<vector<double>> initial_state = {{0.0, 0.0, 1.0, 0.0}};

    // Số bước thời gian
    int steps = 3;

    // Tính xác suất sau mỗi bước
    vector<vector<double>> current_state = initial_state;
    for (int i = 1; i <= steps; ++i) {
        current_state = matrixMultiply(current_state, P);
        cout << "Xac suat sau " << i << " buoc: " << current_state[0][0] << endl;
    }

    return 0;
}