#include <iostream>
#include <vector>
#include <iomanip>  // For setprecision

using namespace std;

// Function to calculate the determinant of a matrix
double determinant(const vector<vector<double> >& matrix, int n) {
    double det = 0;

    if (n == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }

    // Recursive calculation of determinant using Laplace expansion
    vector<vector<double> > subMatrix(n - 1, vector<double>(n - 1));
    for (int x = 0; x < n; x++) {
        int sub_i = 0;
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                subMatrix[sub_i][sub_j] = matrix[i][j];
                sub_j++;
            }
            sub_i++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(subMatrix, n - 1);
    }

    return det;
}

// Function to check if the matrix is square
bool isSquare(const vector<vector<double> >& matrix) {
    int rows = matrix.size();
    for (int i = 0; i < rows; i++) {
        if (matrix[i].size() != rows) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (n): ";
    cin >> n;

    vector<vector<double> > matrix(n, vector<double>(n));

    cout << "Enter the matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "," << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Check if the matrix is square
    if (!isSquare(matrix)) {
        cout << "Error: The matrix is not square." << endl;
        return -1;
    }

    // Calculate and display the determinant with a precision of 10^-5
    double det = determinant(matrix, n);
    cout << fixed << setprecision(5);  // Set precision to 5 decimal places
    cout << "\nThe determinant of the matrix is: " << det << endl;

    return 0;
}

