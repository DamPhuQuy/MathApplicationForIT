#Trong đoạn mã trên, chúng ta sử dụng lại hai hàm extended_euclidean_algorithm và solve_diophantine_equation từ ví dụ trước để giải phương trình Diophantine. Sau khi có kết quả, chúng ta kiểm tra xem nếu không có nghiệm nguyên, in ra chuỗi "No solution". Nếu có nghiệm, chúng ta in ra nghiệm tổng quát với t là một tham số tự do.
def extended_euclidean_algorithm(a, b):
    if b == 0:
        return a, 1, 0

    gcd, x_prev, y_prev = extended_euclidean_algorithm(b, a % b)
    x = y_prev
    y = x_prev - (a // b) * y_prev
    return gcd, x, y

def solve_diophantine_equation(a, b, c):
    gcd, x, y = extended_euclidean_algorithm(a, b)

    if c % gcd != 0:
        return "No solution"

    x *= c // gcd
    y *= c // gcd
    return gcd, x, y

# Nhập các hệ số a, b, c từ người dùng
a = int(input("Nhập hệ số a: "))
b = int(input("Nhập hệ số b: "))
c = int(input("Nhập hệ số c: "))

# Giải phương trình Diophantine
solution = solve_diophantine_equation(a, b, c)

# In kết quả
print("Phương trình Diophantine {}x + {}y = {} có nghiệm:".format(a, b, c))

if solution == "No solution":
    print(solution)
else:
    gcd, x, y = solution
    print("x =", x, "+", b // gcd, "t")
    print("y =", y, "-", a // gcd, "t")