import numpy as np

def grad(Xbar, y, w):
    N = Xbar.shape[0]
    return (1.0 / N) * Xbar.T @ (Xbar @ w - y)

def l(Xbar, y, w):
    N = Xbar.shape[0]
    return 0.5 / N * np.linalg.norm(Xbar @ w - y) ** 2

def gradient_descent_with_momentum(Xbar, y, w_init, alpha, gamma, loop, epsilon):
    w_history = [w_init]
    v = np.zeros_like(w_init)

    for i in range(loop):
        grad_val = grad(Xbar, y, w_history[-1])
        v = alpha * v + gamma * grad_val
        w_new = w_history[-1] - v

        if np.linalg.norm(grad(Xbar, y, w_new)) / w_new.shape[0] < epsilon:
            return w_new, i + 1

        w_history.append(w_new)

    return w_history[-1], loop

def main():
    np.random.seed(2)
    N = 1000
    X = np.random.uniform(0, 1, (N, 1))
    noise = np.random.normal(0, 0.2, (N, 1))
    y = 4 + 3 * X + noise

    Xbar = np.hstack((np.ones((N, 1)), X))

    w_init = np.array([[2], [1]])
    alpha = 0.9  # Learning rate
    gamma = 0.01  # Momentum term
    w_gdwm, it1 = gradient_descent_with_momentum(Xbar, y, w_init, alpha, gamma, 1000, 1e-4)

    print(f"Phuong phap Gradient Descent with Momentum: w = \n{w_gdwm.T},\n after {it1} iterations.")
    print(f"l = {l(Xbar, y, w_gdwm)}")

    # Solve using the normal equation (closed-form solution)
    A = Xbar.T @ Xbar
    b = Xbar.T @ y
    w_lr = np.linalg.solve(A, b)

    print(f"Phuong phap nghich dao: w = \n{w_lr.T}")

if __name__ == "__main__":
    main()
