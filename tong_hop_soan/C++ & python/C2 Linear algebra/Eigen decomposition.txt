import numpy as np

# Hàm nhập ma trận
def nhap_matran(n):
    print(f"Nhập ma trận {n}x{n}:")
    a = []
    for i in range(n):
        row = []
        for j in range(n):
            val = float(input(f"Nhập phần tử ở vị trí ({i + 1}, {j + 1}): "))
            row.append(val)
        a.append(row)
    return np.array(a)

# Hàm hiển thị ma trận hoặc vector
def xuat_matran(a, name="Ma trận"):
    print(f"{name}:")
    for row in a:
        print(" ".join(f"{val:.2f}" for val in row))
    print()

# Hàm phân rã ma trận theo vector riêng và giá trị riêng
def phan_ra_eigen(a):
    # Tính giá trị riêng và vector riêng
    eigenvalues, eigenvectors = np.linalg.eig(a)

    # Xuất giá trị riêng
    print("Giá trị riêng (Λ):")
    for i, val in enumerate(eigenvalues):
        print(f"λ{i + 1} = {val:.2f}")
    print()

    # Xuất vector riêng
    print("Vector riêng (cột của Q):")
    for i, vec in enumerate(eigenvectors.T):  # Vector riêng là các cột
        print(f"v{i + 1} = [{', '.join(f'{x:.2f}' for x in vec)}]")
    print()

    return eigenvalues, eigenvectors

def main():
    try:
        # Nhập ma trận vuông
        n = int(input("Nhập kích thước ma trận vuông n = "))
        if n <= 0:
            raise ValueError("Kích thước ma trận phải lớn hơn 0!")

        a = nhap_matran(n)
        xuat_matran(a, "Ma trận đã nhập")

        # Phân rã eigen
        eigenvalues, eigenvectors = phan_ra_eigen(a)

        # Xây dựng ma trận Λ (đường chéo chứa giá trị riêng)
        Lambda = np.diag(eigenvalues)

        # Tính ma trận nghịch đảo của Q
        Q_inv = np.linalg.inv(eigenvectors)

        # Hiển thị các thành phần phân rã
        xuat_matran(eigenvectors, "Ma trận vector riêng (Q)")
        xuat_matran(Lambda, "Ma trận giá trị riêng (Λ)")
        xuat_matran(Q_inv, "Ma trận nghịch đảo của vector riêng (Q⁻¹)")

        # Tái cấu tạo ma trận
        reconstruct = eigenvectors @ Lambda @ Q_inv
        xuat_matran(reconstruct, "Ma trận tái cấu tạo (QΛQ⁻¹)")

        # So sánh với ma trận ban đầu
        print("So sánh với ma trận ban đầu:")
        xuat_matran(a, "Ma trận ban đầu")
        xuat_matran(reconstruct, "Ma trận tái cấu tạo")

    except Exception as e:
        print(f"Lỗi: {e}")

if __name__ == "__main__":
    main()
