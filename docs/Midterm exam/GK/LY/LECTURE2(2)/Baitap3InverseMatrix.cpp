#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to print the matrix with 3 decimal places
void printMatrix(float** matrix, int size) {
    cout << fixed << setprecision(3); // Set precision to 3 decimal places

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to swap two rows of the matrix
void swapRows(float** matrix, int size, int row1, int row2) {
    for (int i = 0; i < size * 2; ++i) {
        float temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// Function to calculate the inverse of a matrix using Gaussian Elimination
bool inverseMatrix(float** matrix, int size, float** inverse) {
    float** augmented = new float*[size];
    for (int i = 0; i < size; ++i) {
        augmented[i] = new float[size * 2];
    }

    // Create the augmented matrix [A | I]
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + size] = (i == j) ? 1 : 0;
        }
    }

    // Apply Gaussian Elimination
    for (int i = 0; i < size; ++i) {
        // Find the row with the maximum element in the current column
        int maxRow = i;
        for (int k = i + 1; k < size; ++k) {
            if (fabs(augmented[k][i]) > fabs(augmented[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap the current row with the row with the maximum element
        if (i != maxRow) {
            swapRows(augmented, size, i, maxRow);
        }

        // Check if the matrix is singular (not invertible)
        if (augmented[i][i] == 0) {
            cout << "Matrix is singular and cannot be inverted!" << endl;
            for (int i = 0; i < size; ++i) delete[] augmented[i];
            delete[] augmented;
            return false;
        }

        // Normalize the row to make the pivot element 1
        float divisor = augmented[i][i];
        for (int j = 0; j < size * 2; ++j) {
            augmented[i][j] /= divisor;
        }

        // Eliminate the other rows
        for (int k = 0; k < size; ++k) {
            if (k != i) {
                float multiplier = augmented[k][i];
                for (int j = 0; j < size * 2; ++j) {
                    augmented[k][j] -= multiplier * augmented[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inverse[i][j] = augmented[i][j + size];
        }
    }
    
    for (int i = 0; i < size; ++i) delete[] augmented[i];
    delete[] augmented;

    return true;
}

int main() {
    int size;

    cout << "Enter the size of the matrix: ";
    cin >> size;

    // Dynamic allocation of matrices
    float** matrix = new float*[size];
    float** inverse = new float*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new float[size];
        inverse[i] = new float[size];
    }

    cout << "Enter a " << size << "x" << size << " matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << endl << "Original matrix:" << endl;
    printMatrix(matrix, size);

    if (inverseMatrix(matrix, size, inverse)) {
        cout << endl << "Inverse matrix is:" << endl;
        printMatrix(inverse, size);
    }

    // Deallocate memory
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
        delete[] inverse[i];
    }
    delete[] matrix;
    delete[] inverse;

    return 0;
}

