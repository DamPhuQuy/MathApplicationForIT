import math

gamma = 0.01
N = 1000
alpha = 0.9
e = 0.00001

def function(x1, x2):
    return x1 * x1 + x2 * x2

def grad1(x1):
    return 2 * x1

def grad2(x2):
    return 2 * x2

def GradientDescentWithMomentum(x1, x2):
    v1 = 0
    v2 = 0
    for _ in range(N):
        v1 = alpha * v1 + gamma * grad1(x1)
        v2 = alpha * v2 + gamma * grad2(x2)
        x1_new = x1 - v1
        x2_new = x2 - v2

        print(x1_new, x2_new)

        if abs(x1_new - x1) < e and abs(x2_new - x2) < e:
            break

        x1 = x1_new
        x2 = x2_new

    print(f"Hàm số đạt nhỏ nhất tại x1 = {x1}, x2 = {x2}")
    print(f"Min = {function(x1, x2)}")

if __name__ == "__main__":
    x1 = 1
    x2 = -1
    GradientDescentWithMomentum(x1, x2)
