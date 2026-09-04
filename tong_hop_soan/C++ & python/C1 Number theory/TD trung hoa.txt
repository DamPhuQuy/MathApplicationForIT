def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return gcd, x, y

def chinese_remainder_theorem(a, m):
    M = 1
    for mod in m:
        M *= mod
    result = 0
    for ai, mi in zip(a, m):
        Mi = M // mi
        gcd_value, xi, _ = extended_gcd(Mi, mi)
        if gcd_value != 1:
            raise Exception(f"Không thể tìm nghiệm do gcd({Mi}, {mi}) != 1")
        result += ai * xi * Mi
    return result % M, M

def main():
    k = int(input("Nhập số lượng phương trình k: "))
    a = []
    m = []

    for i in range(k):
        a_i = int(input(f"a{i + 1} = "))
        m_i = int(input(f"m{i + 1} = "))
        a.append(a_i)
        m.append(m_i)
    x, M = chinese_remainder_theorem(a, m)
    print(f"Nghiệm tổng quát là: x = {x} (mod {M})")
main()
