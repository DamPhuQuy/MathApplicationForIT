import numpy as np

def nesterov_accelerated_gradient(X, y, learning_rate=0.01, momentum=0.9, num_iterations=100):
    n_samples, n_features = X.shape
    theta = np.zeros(n_features)  # Khởi tạo tham số mô hình với giá trị ban đầu là 0
    velocity = np.zeros(n_features)  # Khởi tạo động lượng ban đầu với giá trị 0

    for iteration in range(num_iterations):
        # Tính toán gradient dựa trên vị trí hiện tại và động lượng
        gradient = compute_gradient(X, y, theta - momentum * velocity)

        # Cập nhật động lượng
        velocity = momentum * velocity + learning_rate * gradient

        # Cập nhật tham số mô hình
        theta -= velocity

    return theta

def compute_gradient(X, y, theta):
    n_samples = X.shape[0]
    gradient = np.zeros(X.shape[1])

    # Tính toán gradient dựa trên từng mẫu dữ liệu
    for i in range(n_samples):
        xi = X[i]
        yi = y[i]
        error = np.dot(xi, theta) - yi
        gradient += 2 * xi * error

    return gradient

X = np.array([[1, 2], [3, 4], [5, 6]])
y = np.array([3, 5, 7])

# Cung cấp tham số
learning_rate = 0.01
momentum = 0.9
num_iterations = 100

# Gọi hàm Nesterov Accelerated Gradient
theta = nesterov_accelerated_gradient(X, y, learning_rate, momentum, num_iterations)

# In ra tham số mô hình tối ưu
print("Tham số mô hình tối ưu:", theta)