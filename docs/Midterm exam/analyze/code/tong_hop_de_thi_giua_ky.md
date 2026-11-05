# TỔNG HỢP ĐỀ THI GIỮA KỲ — MÔN TOÁN ỨNG DỤNG CHO CNTT

> **Tài liệu tham khảo (Knowledge Reference):**
>
> - Slide bài giảng TS. Phạm Công Thắng: `Chap_1_corr.pdf` (Lý thuyết số), `Chap_2_1_anh.pdf`, `Chap_2_2_anh.pdf`, `Chap_2_3_anh.pdf` (Đại số tuyến tính).
> - Đề cương chi tiết học phần: Toán ứng dụng CNTT (Khoa CNTT - ĐH Bách Khoa, ĐH Đà Nẵng).
> - Nguồn dữ liệu: 15 tệp đề thi mẫu `.docx` tại thư mục đề thi giữa kỳ.
> - **Lưu ý:** Toàn bộ code mẫu và bài làm của sinh viên đã được lược bỏ, chỉ giữ lại đề bài gốc, các thông số kỹ thuật ($N$, hệ phương trình đồng dư, ma trận $A$, sai số $\varepsilon$) và phân loại dạng toán.

---

## MỤC LỤC & TỔNG QUAN CẤU TRÚC ĐỀ THI

Các đề thi giữa kỳ được tổ chức theo 2 định dạng (Format) chính:

- **[FORMAT A (3 CÂU — THANG ĐIỂM 10)](#phan-i-cac-de-thi-dinh-dang-3-cau-format-a)**
  - Câu 1 (3 điểm): Lý thuyết số (Thừa số nguyên tố / Số hoàn hảo / Số nguyên tố cùng nhau / Euler)
  - Câu 2 (2 điểm): Hệ phương trình đồng dư (Định lý số dư Trung Hoa — CRT)
  - Câu 3 (5 điểm): Đại số tuyến tính (Phân rã Cholesky $LDL^T$ và Phân rã Eigendecomposition)
  - *Gồm 4 bộ đề: Đề A-01, Đề A-02, Đề A-03, Đề A-04*
- **[FORMAT B (4 CÂU — THANG ĐIỂM 10)](#phan-ii-cac-de-thi-dinh-dang-4-cau-format-b)**
  - Câu 1 (2 điểm): Lý thuyết số (Ước nguyên tố lớn nhất / Số hoàn hảo / Sàng số nguyên tố)
  - Câu 2 (2 điểm): Hệ phương trình đồng dư (Định lý số dư Trung Hoa — CRT)
  - Câu 3 (3 điểm): Đại số tuyến tính (Phân rã Cholesky $LDL^T$ và Eigendecomposition)
  - Câu 4 (3 điểm): Đại số tuyến tính (Phân rã ma trận SVD)
  - *Gồm 5 bộ đề: Đề B-01, Đề B-02, Đề B-03, Đề B-04, Đề B-05*

---

## PHẦN I: CÁC ĐỀ THI ĐỊNH DẠNG 3 CÂU (FORMAT A)

### 📌 Đề A-01

*(Trích xuất từ: `De_0001.docx`, `ĐỀ 001.docx` — Mã đề: 01 — Thời gian làm bài: 90 phút)*

#### Câu 1 (3 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Phân tích thừa số nguyên tố & Ước số nguyên tố & Sàng Eratosthenes.

Cho số nguyên dương $N = 5769$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Phân tích thừa số nguyên tố đối với số $N$.
2. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$.
3. Liệt kê các số nguyên tố nhỏ hơn $M$ và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư bậc nhất & Định lý số dư Trung Hoa (Chinese Remainder Theorem — CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 2 \pmod 3 \\
x \equiv 4 \pmod 5 \\
x \equiv 6 \pmod 7 \\
x \equiv 9 \pmod{11} \\
x \equiv 12 \pmod{17}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (5 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã ma trận $LDL^T$ (Cholesky biến thể) & Phân rã trị riêng (Eigendecomposition).

Cho ma trận:

$$
A = \begin{bmatrix}
4 & 1 & 2 \\
1 & 3 & 0 \\
2 & 0 & 5
\end{bmatrix}
$$

Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
a) Phân rã **Cholesky** $LDL^T$ ma trận $A$.
b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

### 📌 Đề A-02

*(Trích xuất từ: `ĐỀ 002.docx` — Mã đề: 02 — Thời gian làm bài: 90 phút)*

#### Câu 1 (3 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Phân tích thừa số nguyên tố & Sàng số nguyên tố.

Cho số nguyên dương $N = 5121$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Phân tích thừa số nguyên tố đối với số $N$.
2. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$.
3. Liệt kê các số nguyên tố nhỏ hơn $M$ và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 2 \pmod 3 \\
x \equiv 4 \pmod 5 \\
x \equiv 6 \pmod 7 \\
x \equiv 7 \pmod{11} \\
x \equiv 8 \pmod{13}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (5 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã ma trận $LDL^T$ & Phân rã trị riêng (Eigendecomposition).

Cho ma trận:

$$
A = \begin{bmatrix}
6 & 2 & 1 \\
2 & 4 & 2 \\
1 & 2 & 3
\end{bmatrix}
$$

Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
a) Phân rã **Cholesky** $LDL^T$ ma trận $A$.
b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

### 📌 Đề A-03

*(Trích xuất từ: `102240319_NguyenThanhLuan (1).docx` — Mã đề: 03 — Thời gian làm bài: 90 phút)*

#### Câu 1 (3 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Số hoàn hảo (Perfect Numbers), Số nguyên tố cùng nhau & Phi hàm Euler, Tìm số nguyên tố lân cận.

Cho số nguyên dương $N = 12000$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số lượng các số hoàn hảo nhỏ hơn $N$, liệt kê và tính tổng của chúng.
2. Gọi $M$ là số hoàn hảo lớn nhất vừa tìm được, tìm số $K$ gần $M$ nhất sao cho $K$ chia hết cho 7.
3. Tìm số lượng các số nguyên dương nhỏ hơn $K$ và nguyên tố cùng nhau với $K$. Liệt kê các số đó và tính tổng của chúng.
4. Tìm số $P$ là số nguyên tố gần $K$ nhất.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 2 \pmod 5 \\
x \equiv 4 \pmod 7 \\
x \equiv 6 \pmod 9 \\
x \equiv 9 \pmod{13} \\
x \equiv 12 \pmod{17}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (5 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận:

$$
A = \begin{bmatrix}
4 & 1 & 2 \\
1 & 8 & 2 \\
2 & 2 & 10
\end{bmatrix}
$$

Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
a) Phân rã $LDL^T$ ma trận $A$.
b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

### 📌 Đề A-04

*(Trích xuất từ: `De_04_GK_102240207.docx` — Mã đề: 04 — Thời gian làm bài: 90 phút)*

#### Câu 1 (3 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Số hoàn hảo, Số nguyên tố cùng nhau, Tìm số nguyên tố lân cận.

Cho số nguyên dương $N = 10000$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số lượng các số hoàn hảo nhỏ hơn $N$, liệt kê và tính tổng của chúng.
2. Gọi $M$ là số hoàn hảo lớn nhất vừa tìm được, tìm số $K$ gần $M$ nhất sao cho $K$ chia hết cho 7.
3. Tìm số lượng các số nguyên dương nhỏ hơn $K$ và nguyên tố cùng nhau với $K$. Liệt kê các số đó và tính tổng của chúng.
4. Tìm số $P$ là số nguyên tố gần $K$ nhất.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 3 \pmod 5 \\
x \equiv 4 \pmod 7 \\
x \equiv 6 \pmod{11} \\
x \equiv 8 \pmod{13} \\
x \equiv 9 \pmod{17}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (5 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận:

$$
A = \begin{bmatrix}
6 & 1 & 2 \\
1 & 5 & 2 \\
2 & 2 & 7
\end{bmatrix}
$$

Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
a) Phân rã $LDL^T$ ma trận $A$.
b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

## PHẦN II: CÁC ĐỀ THI ĐỊNH DẠNG 4 CÂU (FORMAT B)

### 📌 Đề B-01

*(Trích xuất từ: `ĐỀ-3.docx` — Mã đề: 0001 — Thời gian làm bài: 90 phút)*

#### Câu 1 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Ước nguyên tố lớn nhất, Số hoàn hảo & Sàng số nguyên tố.

Cho số nguyên dương $N = 11530$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo nhỏ hơn $M$, liệt kê và tính tổng của chúng.
2. Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 1 \pmod 3 \\
x \equiv 3 \pmod 5 \\
x \equiv 4 \pmod 7 \\
x \equiv 5 \pmod{11}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã Cholesky $LDL^T$ & Eigendecomposition.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
a) Phân rã **Cholesky** $LDL^T$ ma trận $A$ với:

$$
A = \begin{bmatrix}
1 & 2 & 3 \\
2 & 7 & 3 \\
3 & 3 & 3
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

b) Phân rã **eigendecomposition** ma trận $A$ với:

$$
A = \begin{bmatrix}
1 & 2 & 3 \\
6 & 7 & 3 \\
8 & 9 & 3
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

#### Câu 4 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã giá trị suy biến SVD (Singular Value Decomposition).

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:

$$
A = \begin{bmatrix}
1 & 2 & 3 \\
6 & 7 & 3 \\
8 & 9 & 3
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

---

### 📌 Đề B-02

*(Trích xuất từ: `102230313_DoanHoangThienPhu.docx` — Mã đề: 01 — Thời gian làm bài: 90 phút)*

#### Câu 1 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Ước số nguyên tố lớn nhất, Số hoàn hảo & Sàng nguyên tố.

Cho số nguyên dương $N = 96700$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo (giữa 1 và $M$), liệt kê và tính tổng của chúng.
2. Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 3 \pmod 5 \\
x \equiv 5 \pmod 7 \\
x \equiv 7 \pmod 9 \\
x \equiv 9 \pmod{11} \\
x \equiv 11 \pmod{13}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
a) Phân rã $LDL^T$ ma trận $A$ với:

$$
A = \begin{bmatrix}
-7 & 9 & 20 \\
9 & -7 & 18 \\
20 & 18 & -7
\end{bmatrix}
$$

*(Yêu cầu kiểm tra điều kiện ma trận vuông và đối xứng).*
b) Phân rã **eigendecomposition** ma trận $A$ với:

$$
A = \begin{bmatrix}
-7 & 9 & 20 \\
9 & -7 & 18 \\
20 & 18 & -7
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

#### Câu 4 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã SVD.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:

$$
A = \begin{bmatrix}
5 & 5 & 9 \\
2 & 2 & 5 \\
3 & 4 & 5
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

---

### 📌 Đề B-03

*(Trích xuất từ: `De_0002.docx`, `ĐỀ 4.docx`, `ĐỀ-4.docx` — Mã đề: 0002 / Đề 4 — Thời gian làm bài: 90 phút)*

#### Câu 1 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Số nguyên tố cùng nhau & Đặc trưng số nguyên tố chia hết cho 3.

Cho số nguyên dương $N = 403$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số lượng các số nguyên dương (giữa 1 và $N$) là nguyên tố cùng nhau với $N$ ($N > 1$), liệt kê và tính tổng của chúng.
2. Tìm số nguyên tố gần $N$ nhất và chia hết cho 3.
   *(Ghi chú: Trong tập các số nguyên tố, số nguyên tố duy nhất chia hết cho 3 là số 3).*

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 2 \pmod 3 \\
x \equiv 4 \pmod 5 \\
x \equiv 6 \pmod 7 \\
x \equiv 7 \pmod{11}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
a) Phân rã $LDL^T$ ma trận $A$ với:

$$
A = \begin{bmatrix}
4 & 8 & 6 \\
8 & 8 & 6 \\
9 & 8 & 6
\end{bmatrix}
$$

*(Yêu cầu kiểm tra điều kiện ma trận vuông và đối xứng. Chú ý: phần tử $a_{31}=9 \neq a_{13}=6$ nên ma trận này không đối xứng; chương trình cần thông báo không thể phân rã).*
b) Phân rã **eigendecomposition** ma trận $A$ với ma trận $A$ như trên (sai số $\varepsilon = 10^{-5}$).

#### Câu 4 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã SVD.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:

$$
A = \begin{bmatrix}
4 & 8 & 6 \\
8 & 8 & 6 \\
9 & 8 & 6
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

---

### 📌 Đề B-04

*(Trích xuất từ: `Đáp án đề 02.docx`, `ĐỀ 5.docx` — Mã đề: 02 — Thời gian làm bài: 90 phút)*

#### Câu 1 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Ước số nguyên tố lớn nhất & Số hoàn hảo.

Cho số nguyên dương $N$ ($N > 1$). Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$ ($M < N$), biết rằng $N = 10583$.
2. Tìm số lượng các số hoàn hảo nhỏ hơn $M$, liệt kê và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 5 \pmod 7 \\
x \equiv 7 \pmod 9 \\
x \equiv 9 \pmod{11} \\
x \equiv 13 \pmod{17}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
a) Phân rã $LDL^T$ ma trận $A$ với:

$$
A = \begin{bmatrix}
13 & 3 & 9 \\
3 & 12 & 6 \\
9 & 6 & 13
\end{bmatrix}
$$

*(Yêu cầu kiểm tra điều kiện ma trận vuông và đối xứng).*
b) Phân rã **eigendecomposition** ma trận $A$ với ma trận $A$ như trên (sai số $\varepsilon = 10^{-5}$).

#### Câu 4 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã SVD.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:

$$
A = \begin{bmatrix}
9 & 7 & 3 \\
7 & 8 & 6 \\
8 & 8 & 9
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

---

### 📌 Đề B-05

*(Trích xuất từ: `De_03.docx`, `Đáp án đề 03.docx`, `ĐỀ 6.docx` — Mã đề: 03 — Thời gian làm bài: 90 phút)*

#### Câu 1 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Ước số nguyên tố lớn nhất, Số hoàn hảo & Sàng nguyên tố.

Cho số nguyên dương $N = 97700$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:

1. Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo (giữa 1 và $M$), liệt kê và tính tổng của chúng.
2. Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.

#### Câu 2 (2 điểm)

> **Dạng toán (Slide Chap 1):** Lý thuyết số — Hệ phương trình đồng dư & Định lý số dư Trung Hoa (CRT).

Cho hệ phương trình đồng dư sau:

$$
\begin{cases}
x \equiv 2 \pmod 5 \\
x \equiv 3 \pmod 7 \\
x \equiv 4 \pmod 9 \\
x \equiv 5 \pmod{11} \\
x \equiv 6 \pmod{13}
\end{cases}
$$

Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.

#### Câu 3 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã $LDL^T$ & Eigendecomposition.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
a) Phân rã $LDL^T$ ma trận $A$ với:

$$
A = \begin{bmatrix}
-10 & 4 & 7 \\
4 & -5 & 8 \\
7 & 8 & -9
\end{bmatrix}
$$

*(Yêu cầu kiểm tra điều kiện ma trận vuông và đối xứng).*
b) Phân rã **eigendecomposition** ma trận $A$ với:

$$
A = \begin{bmatrix}
10 & 2 & 8 \\
9 & 0 & 0 \\
9 & 7 & 6
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

#### Câu 4 (3 điểm)

> **Dạng toán (Slide Chap 2):** Đại số tuyến tính — Phân rã SVD.

Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:

$$
A = \begin{bmatrix}
10 & 2 & 8 \\
9 & 0 & 0 \\
9 & 7 & 6
\end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})
$$

---

## BẢNG TỔNG KẾT & PHÂN LOẠI CÁC DẠNG TOÁN THI GIỮA KỲ

| Dạng toán                                                            | Vị trí xuất hiện                             | Slide tham chiếu                                              | Các yêu cầu cốt lõi                                                                            | Các thuật toán liên quan                                                           |
| ---------------------------------------------------------------------- | ------------------------------------------------ | -------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------- |
| **Lý thuyết số: Phân tích & Ước nguyên tố**             | Câu 1 (Đề A-01, A-02, B-01, B-02, B-04, B-05) | `Chap_1_corr.pdf` (Mục 1.1)                                 | Phân tích$N$, tìm ước nguyên tố lớn nhất $M$, tính tổng số nguyên tố $< M$      | Thử chia (Trial division), Sàng Eratosthenes                                         |
| **Lý thuyết số: Số hoàn hảo & Số nguyên tố cùng nhau** | Câu 1 (Đề A-03, A-04, B-03)                   | `Chap_1_corr.pdf` (Mục 1.1)                                 | Liệt kê số hoàn hảo, tìm số nguyên tố cùng nhau với$K$, tìm số nguyên tố lân cận | Thuật toán kiểm tra số hoàn hảo$\sum d(n) = 2n$, Thuật toán Euclid tính GCD |
| **Lý thuyết số: Hệ đồng dư bậc nhất (CRT)**             | Câu 2 (Tất cả các đề)                      | `Chap_1_corr.pdf` (Mục 1.2)                                 | Giải hệ từ 4 đến 5 phương trình đồng dư$x \equiv a_i \pmod{m_i}$                       | Định lý số dư Trung Hoa, Thuật toán Euclid mở rộng tìm nghịch đảo Modulo  |
| **Đại số tuyến tính: Phân rã $LDL^T$**                  | Câu 3 (Format A), Câu 3a (Format B)            | `Chap_2_2_anh.pdf` & `Chap_2_3_anh.pdf`                    | Phân rã ma trận đối xứng$A = L D L^T$ (hàm kiểm tra đối xứng bắt buộc)               | Biến thể của phân rã Cholesky không dùng căn bậc hai                          |
| **Đại số tuyến tính: Eigendecomposition**                   | Câu 3 (Format A), Câu 3b (Format B)            | `Chap_2_2_anh.pdf` & `HMUD_Matrix_Diagonalization_259.pdf` | Chéo hóa ma trận$A = Q \Lambda Q^{-1}$ hoặc $P D P^{-1}$, sai số $10^{-5}$               | Tìm đa thức đặc trưng hoặc thuật toán Jacobi / thư viện Eigen               |
| **Đại số tuyến tính: Phân rã SVD**                        | Câu 4 (Chỉ có ở Format B)                    | `Chap_2_3_anh.pdf`                                           | Phân rã giá trị suy biến$A = U \Sigma V^T$ với sai số $10^{-5}$                          | Phân rã phổ trên$A^T A$ và $A A^T$ hoặc thuật toán SVD                     |
