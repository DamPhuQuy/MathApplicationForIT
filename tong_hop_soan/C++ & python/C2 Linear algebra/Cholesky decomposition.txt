import math

def nhap_matran(n):
    a = []
    for i in range(n):
        row = []
        for j in range(n):
            val = float(input(f"a[{i}][{j}] = "))
            row.append(val)
        a.append(row)
    return a

def xuat_matran(a):
    print("Ma trận như sau:")
    for row in a:
        for val in row:
            print(f"{val:.2f}", end="\t\t")
        print()

def is_symmetric(a):
    n = len(a)
    for i in range(n):
        for j in range(n):
            if a[i][j] != a[j][i]:
                return False
    return True

def cholesky(a):
    n = len(a)
    L = [[0.0] * n for _ in range(n)]
    if not is_symmetric(a):
        print("Ma trận phải đối xứng")
        return None
    for i in range(n):
        for j in range(i + 1):
            sum_val = 0.0
            if i == j:
                for k in range(j):
                    sum_val += L[j][k] ** 2
                L[j][j] = (a[j][j] - sum_val)
                if L[j][j] <= 0:
                    return None
                L[j][j] = math.sqrt(L[i][j])
            else:
                for k in range(j):
                    sum_val += L[i][k] * L[j][k]
                L[i][j] = (a[i][j] - sum_val) / L[j][j]
    return L

def transpose(L):
    n = len(L)
    LT = [[L[j][i] for j in range(n)] for i in range(n)]
    return LT

def multiply_matrix(L, LT):
    n = len(L)
    result = [[0.0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[i][j] = sum(L[i][k] * LT[k][j] for k in range(n))
    return result

def main():
    n = int(input("Nhập n = "))
    a = nhap_matran(n)
    print("Ma trận gốc A:")
    xuat_matran(a)

    L = cholesky(a)
    if L:
        print("Ma trận L (tam giác dưới):")
        xuat_matran(L)
        LT = transpose(L)
        print("Ma trận chuyển vị của L (L^T):")
        xuat_matran(LT)

        A_reconstructed = multiply_matrix(L, LT)
        print("Ma trận A = L * L^T:")
        xuat_matran(A_reconstructed)
    else:
        print("Ma trận không xác định dương")

main()
