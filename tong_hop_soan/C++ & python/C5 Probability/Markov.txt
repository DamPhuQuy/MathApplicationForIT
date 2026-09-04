import numpy as np

# Hàm nhập ma trận Markov
def nhap_ma_tran_markov(n):
    print(f"Nhập ma trận Markov {n}x{n} (các hàng phải cộng lại bằng 1):")
    mat = []
    for i in range(n):
        row = []
        for j in range(n):
            value = float(input(f"Nhập phần tử tại hàng {i + 1}, cột {j + 1}: "))
            row.append(value)
        if not np.isclose(sum(row), 1.0):
            raise ValueError(f"Tổng các phần tử của hàng {i + 1} phải bằng 1!")
        mat.append(row)
    return np.array(mat)

# Hàm nhập trạng thái ban đầu
def nhap_trang_thai_ban_dau(n):
    print("Nhập từng giá trị trong vector trạng thái ban đầu:")
    vec = []
    for i in range(n):
        value = float(input(f"Nhập phần tử trạng thái ban đầu tại vị trí {i + 1}: "))
        vec.append(value)
    if not np.isclose(sum(vec), 1.0):
        raise ValueError("Tổng các giá trị trong vector trạng thái ban đầu phải bằng 1!")
    return np.array(vec)

# Hàm tính xác suất trạng thái sau n bước
def tinh_xac_suat_sau_n_buoc(markov, trang_thai_ban_dau, n):
    # Tính ma trận Markov sau n bước (mũ n)
    markov_n = np.linalg.matrix_power(markov, n)

    # Tính xác suất trạng thái sau n bước
    ket_qua = trang_thai_ban_dau @ markov_n
    return ket_qua

def main():
    try:
        # Nhập kích thước ma trận Markov
        n = int(input("Nhập số trạng thái (kích thước ma trận Markov) n = "))
        if n <= 0:
            raise ValueError("Số trạng thái phải lớn hơn 0!")

        # Nhập ma trận Markov
        markov = nhap_ma_tran_markov(n)
        print("Ma trận Markov đã nhập:")
        print(markov)

        # Nhập trạng thái ban đầu
        trang_thai_ban_dau = nhap_trang_thai_ban_dau(n)
        print("Vector trạng thái ban đầu:")
        print(trang_thai_ban_dau)

        # Nhập số bước n
        buoc = int(input("Nhập số bước n = "))
        if buoc < 0:
            raise ValueError("Số bước phải là số không âm!")

        # Tính xác suất trạng thái sau n bước
        ket_qua = tinh_xac_suat_sau_n_buoc(markov, trang_thai_ban_dau, buoc)
        print(f"Xác suất trạng thái sau {buoc} bước:")
        print(ket_qua)

    except Exception as e:
        print(f"Lỗi: {e}")

if __name__ == "__main__":
    main()
