#include <iostream>
#include <vector>
#include <iomanip>
//Không xác định dương
using namespace std;

const int MAX = 100;

void LDLT_Decomposition(float matrix[][MAX], int n) {
    vector<vector<float>> lower(n, vector<float>(n, 0.0f));
    vector<vector<float>> D(n, vector<float>(n, 0.0f));

    for (int j = 0; j < n; j++) {

        float sum_D = 0;
        for (int k = 0; k < j; k++) {
            sum_D += lower[j][k] * lower[j][k] * D[k][k];
        }
        D[j][j] = matrix[j][j] - sum_D;

        lower[j][j] = 1.0f;

        for (int i = j + 1; i < n; i++) {
            float sum_L = 0;
            for (int k = 0; k < j; k++) {
                sum_L += lower[i][k] * lower[j][k] * D[k][k];
            }
            // Chỉ cần tính toán L[i][j] một lần duy nhất
            lower[i][j] = (matrix[i][j] - sum_L) / D[j][j];
        }
    }

    // In kết quả: Ma trận L, D và L^T
    cout << setw(10) << "Matrix L" 
         << setw(35) << "Matrix D" 
         << setw(35) << "Matrix L^T" << endl;
         
    for (int i = 0; i < n; i++) {
        // In ma trận L (Lower Triangular)
        for (int j = 0; j < n; j++)
            cout << setw(7) << setprecision(3) << fixed << lower[i][j] << "\t";
        cout << "\t";
        
        // In ma trận D (Diagonal)
        for(int j = 0; j < n; j++)
            cout << setw(7) << setprecision(3) << fixed << D[i][j] << "\t";
        cout << "\t";
        
        // In ma trận L^T (Transpose of L)
        for (int j = 0; j < n; j++)
            cout << setw(7) << setprecision(3) << fixed << lower[j][i] << "\t";
        cout << endl;
    }
}

int main() {
    int n = 3;
    float matrix[MAX][MAX] = { 
        {  4,  12, -16 },
        { 12,  37, -43 },
        { -16, -43,  98 } 
    };
    
    cout << "--- PHAN RA LDL^T (Square-Root-Free Cholesky) ---" << endl;
    LDLT_Decomposition(matrix, n);
    
    return 0;
}