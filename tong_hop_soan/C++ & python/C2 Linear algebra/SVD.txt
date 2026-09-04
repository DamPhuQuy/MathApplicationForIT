import numpy as np

# Hàm tính ma trận chuyển vị
def transpose(matrix):
    return np.array(matrix).T

# Hàm tính A^T * A
def compute_at_a(A):
    return np.dot(transpose(A), A)

# Hàm tính trị riêng và vectơ riêng
def compute_eigenvalues_and_vectors(A):
    eig_values, eig_vectors = np.linalg.eig(A)
    return eig_values, eig_vectors

# Hàm sắp xếp trị riêng và vectơ riêng
def sort_eigenpairs(eig_values, eig_vectors):
    idx = np.argsort(eig_values)[::-1]  # Sắp xếp giảm dần
    sorted_eig_values = eig_values[idx]
    sorted_eig_vectors = eig_vectors[:, idx]
    return sorted_eig_values, sorted_eig_vectors

# Hàm tính U từ A và V
def compute_U(A, V, sorted_eig_values):
    U = np.zeros(A.shape)
    for i in range(len(sorted_eig_values)):
        if sorted_eig_values[i] > 1e-10:  # Tránh chia cho 0
            U[:, i] = np.dot(A, V[:, i]) / np.sqrt(sorted_eig_values[i])
    return U

# Hàm chính thực hiện SVD
def svd(A):
    # Bước 1: Tính A^T * A
    AtA = compute_at_a(A)

    # Bước 2: Tính trị riêng và vectơ riêng của A^T * A
    eig_values, eig_vectors = compute_eigenvalues_and_vectors(AtA)

    # Bước 3: Sắp xếp trị riêng và vectơ riêng
    sorted_eig_values, V = sort_eigenpairs(eig_values, eig_vectors)

    # Bước 4: Tính U từ A và V
    U = compute_U(A, V, sorted_eig_values)

    # Tạo ma trận Sigma
    Sigma = np.zeros(A.shape)
    for i in range(len(sorted_eig_values)):
        Sigma[i][i] = np.sqrt(sorted_eig_values[i])

    return U, Sigma, V

# Ví dụ sử dụng
A = np.array([[3, 2], [2, 3], [4, 5]])

U, Sigma, V = svd(A)

print("Ma trận U:")
print(U)
print("\nMa trận Sigma:")
print(Sigma)
print("\nMa trận V:")
print(V)
