def extended_euclidean_algorithm(a, b):
    if b == 0:
        return a, 1, 0

    gcd, x_prev, y_prev = extended_euclidean_algorithm(b, a % b)
    x = y_prev
    y = x_prev - (a // b) * y_prev
    return gcd, x, y
# Hàm tính định thức modulo
def modular_inverse(a, m):
    g, x, y = extended_euclidean_algorithm(a, m)
    if g != 1:
        raise ValueError("Không có nghịch đảo modulo")
    return x % m

# Hàm áp dụng Định lý thặng dư Trung Hoa
def chinese_remainder_theorem(congruences):
    # Tính tích của tất cả các môđun
    modulus = 1
    for congruence in congruences:
        modulus *= congruence[1]

    result = 0
    for congruence in congruences:
        ai, mi = congruence[0], congruence[1]
        bi = modulus // mi
        bi_inverse = modular_inverse(bi, mi)
        result += ai * bi * bi_inverse

    return result % modulus

# Nhập các đồng dư từ người dùng
congruences = []
n = int(input("Nhập số lượng đồng dư: "))
for i in range(n):
    a = int(input("Nhập giá trị a{}: ".format(i)))
    m = int(input("Nhập giá trị m{}: ".format(i)))
    congruences.append((a, m))

# Áp dụng Định lý thặng dư Trung Hoa
result = chinese_remainder_theorem(congruences)

# In kết quả
print("Nghiệm của hệ phương trình đồng dư modulo là:", result)