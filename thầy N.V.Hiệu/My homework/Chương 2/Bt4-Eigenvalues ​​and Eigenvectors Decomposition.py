import numpy as np

def eigendecomposition(A):
    """Performs the eigendecomposition of matrix A."""
    # Calculate eigenvalues and eigenvectors
    eigenvalues, eigenvectors = np.linalg.eig(A)

    # Create diagonal matrix from eigenvalues
    Lambda = np.diag(eigenvalues)

    # Calculate inverse of the eigenvector matrix
    V_inv = np.linalg.inv(eigenvectors)

    return eigenvectors, Lambda, V_inv

def print_matrix(matrix, precision=5):
    """Prints a matrix with specified precision."""
    with np.printoptions(precision=precision, suppress=True):
        print(matrix)

def main():
    # Input the size of the square matrix
    n = int(input("Enter the size of the square matrix (n): "))

    # Input matrix A from user
    print("Enter matrix A:")
    A = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            A[i, j] = float(input(f"A[{i+1},{j+1}]: "))

    # Perform eigendecomposition
    V, Lambda, V_inv = eigendecomposition(A)

    # Display the results
    print("\nMatrix A:")
    print_matrix(A, precision=5)
    print("\nMatrix of Eigenvectors (V):")
    print_matrix(V, precision=5)
    print("\nDiagonal Matrix of Eigenvalues (Λ):")
    print_matrix(Lambda, precision=5)
    print("\nInverse of Eigenvector Matrix (V_inv):")
    print_matrix(V_inv, precision=5)

    # Verify decomposition by reconstructing A
    A_reconstructed = np.dot(V, np.dot(Lambda, V_inv))
    print("\nReconstructed Matrix A (VΛV^-1):")
    print_matrix(A_reconstructed, precision=5)

if __name__ == "__main__":
    main()
