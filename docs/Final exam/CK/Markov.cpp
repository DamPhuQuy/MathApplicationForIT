#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> multiplyMatrix(
    const vector<vector<double>>& A,
    const vector<vector<double>>& B
) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<double>> matrixPower(vector<vector<double>> P, int steps) {
    int n = P.size();

    // Tao ma tran don vi I
    vector<vector<double>> result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        result[i][i] = 1.0;
    }

    // Nhan lap steps lan: result = P^steps
    for (int i = 0; i < steps; i++) {
        result = multiplyMatrix(result, P);
    }

    return result;
}

void printMatrix(const vector<vector<double>>& A) {
    cout << fixed << setprecision(4);

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << setw(10) << A[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so trang thai cua he: ";
    cin >> n;

    vector<vector<double>> P(n, vector<double>(n));

    cout << "Nhap ma tran chuyen trang thai P:\n";
    for (int i = 0; i < n; i++) {
        double rowSum = 0;

        for (int j = 0; j < n; j++) {
            cout << "P[" << i << "][" << j << "] = ";
            cin >> P[i][j];
            rowSum += P[i][j];
        }

        if (rowSum < 0.9999 || rowSum > 1.0001) {
            cout << "Canh bao: Tong hang " << i << " = " << rowSum
                 << ", khong bang 1.\n";
        }
    }

    int startState, endState, steps;

    cout << "Nhap trang thai bat dau: ";
    cin >> startState;

    cout << "Nhap trang thai can tinh xac suat den: ";
    cin >> endState;

    cout << "Nhap so giai doan: ";
    cin >> steps;

    if (startState < 0 || startState >= n || endState < 0 || endState >= n || steps < 0) {
        cout << "Input khong hop le.\n";
        return 0;
    }

    vector<vector<double>> Pk = matrixPower(P, steps);

    cout << "\nMa tran P^" << steps << " la:\n";
    printMatrix(Pk);

    cout << fixed << setprecision(4);
    cout << "\nXac suat bat dau o trang thai " << startState
         << " va sau " << steps
         << " giai doan o trang thai " << endState
         << " la: " << Pk[startState][endState] << endl;

    cout << "Tuong duong: " << Pk[startState][endState] * 100 << "%" << endl;

    return 0;
}