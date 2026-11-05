#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Nhap so trang thai n = ";
    cin >> n;

    vector<vector<double>> P(n, vector<double>(n));

    cout << "\nNhap ma tran chuyen trang thai P:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "P[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> P[i][j];
        }
    }

    int startState, targetState, steps;

    cout << "\nNhap trang thai bat dau = ";
    cin >> startState;

    cout << "Nhap trang thai can tinh xac suat = ";
    cin >> targetState;

    cout << "Nhap so buoc van hanh = ";
    cin >> steps;

    // Đổi từ chỉ số người dùng nhập 1,2,3,... sang chỉ số mảng 0,1,2,...
    startState--;
    targetState--;

    vector<double> pi(n, 0.0);
    pi[startState] = 1.0;

    // Tính pi(k) = pi(0) * P^k
    for (int step = 1; step <= steps; step++) {
        vector<double> nextPi(n, 0.0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nextPi[j] += pi[i] * P[i][j];
            }
        }

        pi = nextPi;
    }

    cout << fixed << setprecision(6);

    cout << "\nVector phan phoi xac suat sau " << steps << " buoc la:\n";
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << pi[i] << " ";
    }
    cout << "]\n";

    cout << "\nXac suat he thong o trang thai " << targetState + 1
         << " sau " << steps << " buoc la: "
         << pi[targetState] << endl;

    // Tìm trạng thái có xác suất lớn nhất
    int maxState = 0;
    for (int i = 1; i < n; i++) {
        if (pi[i] > pi[maxState]) {
            maxState = i;
        }
    }

    cout << "\nTrang thai co xac suat lon nhat sau " << steps << " buoc la: "
         << maxState + 1 << endl;

    cout << "Xac suat lon nhat la: " << pi[maxState] << endl;

    return 0;
}