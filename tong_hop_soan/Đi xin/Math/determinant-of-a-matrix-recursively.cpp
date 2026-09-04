// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice.

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> matrix;
#define nln '\n'

// Function to calculate the determinant of a square matrix recursively
double determinantNxN(const matrix& mtx) {
    int n = mtx.size();
    
    // Base case: if the matrix is 1x1, return the single element
    if (n == 1) {
        return mtx[0][0];
    }

    double det = 0;
    int sign = 1;

    // Iterate over the first row to calculate the determinant
    for (int i = 0; i < n; ++i) {
        // Calculate the minor matrix by excluding the current row and column
        matrix minor(n - 1, vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k < i) {
                    minor[j - 1][k] = mtx[j][k];
                } else if (k > i) {
                    minor[j - 1][k - 1] = mtx[j][k];
                }
            }
        }

        // Calculate the determinant recursively for the minor matrix
        double minorDet = determinantNxN(minor);

        // Add the contribution of the current element to the determinant
        det += sign * mtx[0][i] * minorDet;

        // Alternate the sign for each element in the first row
        sign *= -1;
    }

    return det;
}

int main(int argc, char* argv[]) {
    vector<vector<double>> mat = {
		{1, 45, 2, 9}, 
		{51, 7, 8, 5}, 
		{2, 1, 3, -3},
		{1, 32, 5, 12}};
    cout << "Determinant of the matrix: " << determinantNxN(mat) << endl;
    return 0;
}