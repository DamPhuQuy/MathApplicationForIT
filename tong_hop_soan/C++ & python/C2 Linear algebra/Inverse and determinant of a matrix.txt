import numpy as np

# Hoán vị hai giá trị
def hoan_vi(c, b):
    return b, c

# Nhập ma trận
def nhap_matran(n):
    a = []
    for i in range(n):
        row = []
        for j in range(n):
            val = float(input(f"a[{i}][{j}] = "))
            row.append(val)
        a.append(row)
    return np.array(a)

# Xuất ma trận
def xuat_matran(a):
    print("Ma trận như sau:")
    for row in a:
        print("\t".join(f"{val:.2f}" for val in row))

# Tạo ma trận con
def ma_tran_con(a, c, d):
    return np.delete(np.delete(a, c, axis=0), d, axis=1)

# Tính định thức
def det(a):
    n = len(a)
    if n == 1:
        return a[0][0]
    elif n == 2:
        return a[0][0] * a[1][1] - a[0][1] * a[1][0]
    else:
        q = 0
        for i in range(n):
            b = ma_tran_con(a, 0, i)
            det_con = det(b)
            q += (-1) ** i * a[0][i] * det_con
        return q

# Tính ma trận nghịch đảo
def ma_tran_nd(a):
    n = len(a)
    p = det(a)
    if p == 0:
        print("Ma trận suy biến, không thể tính nghịch đảo.")
        return None
    else:
        A = np.zeros_like(a, dtype=float)
        for t in range(n):
            for i in range(n):
                b = ma_tran_con(a, i, t)
                det_con = det(b)
                A[t][i] = (-1) ** (t + i) * det_con
        return A.T / p

def main():
    n = int(input("Nhập n = "))
    a = nhap_matran(n)
    xuat_matran(a)
    print(f"Định thức của ma trận bằng: {det(a):.1f}")
    nghich_dao = ma_tran_nd(a)
    if nghich_dao is not None:
        print("Ma trận nghịch đảo như sau:")
        xuat_matran(nghich_dao)

if __name__ == "__main__":
    main()
