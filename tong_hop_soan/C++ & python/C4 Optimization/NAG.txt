import numpy as np

def cost(x):
    return (np.exp(2 * x) + 3 * x**2 + 8 * x) / (35 - x) - 5 * x

def grad(x):
    numerator = (35 - x) * (2 * np.exp(2 * x) + 6 * x + 8) + np.exp(2 * x) + 3 * x * x + 8 * x;
    denominator = (35 - x)**2
    return numerator / denominator - 5

def nesterov_accelerated_gradient(alpha, beta, x0, grad_thresh=1e-5, max_iter=1000):

    x = x0
    v = 0
    history = [x]

    for it in range(max_iter):
        lookahead_x = x - beta * v
        gradient = grad(lookahead_x)
        v = beta * v + alpha * gradient
        x = x - v

        history.append(x)

        if abs(gradient) < grad_thresh:
            print(f"NAG dừng sau {it} vòng lặp.")
            break

    return x, history

if __name__ == "__main__":
    alpha = 0.001
    beta = 0.1
    x0 = 0

    x_min, history = nesterov_accelerated_gradient(alpha, beta, x0)

    print(f"Điểm cực tiểu x = {x_min}, f(x) = {cost(x_min)}")
