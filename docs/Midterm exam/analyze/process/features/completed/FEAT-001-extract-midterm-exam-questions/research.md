# Research: FEAT-001 Trích xuất và Tổng hợp Đề thi Giữa kỳ

<research_context task_id="FEAT-001-extract-midterm-exam-questions" version="2.1" framework="RIPER-5">

<research_status>
  <phase>RESEARCH</phase>
  <mode>READ-ONLY</mode>
  <research_owner>@phuqy</research_owner>
  <last_updated>2026-10-08T21:34:00+07:00</last_updated>
  <halting_status>HALTED_COMPLETE</halting_status>
</research_status>

---

## 1. Hiện trạng & Khảo sát kho tài liệu đề thi

### 1.1 Danh mục 15 tệp `.docx` trong thư mục `docs/Midterm exam/analyze/`
Qua khảo sát và trích xuất bằng `pandoc`, đối chiếu hình ảnh và OLE binary (`oleObject*.bin`), 15 tệp .docx trong thư mục thuộc về **2 Format cấu trúc đề thi chính**:

| STT | Tên tệp .docx | Loại tệp | Đề số ghi trong tệp | Số câu | Cấu trúc đề | Thông số đặc trưng (N, ma trận) |
|---|---|---|---|---|---|---|
| 1 | `De_0001.docx` | Bài làm sinh viên (có đề gốc) | Đề 01 | 3 câu | Format A | $N = 5769$, hệ 5 PT mod {3,5,7,11,17}, $A_{3\times 3}$ đối xứng |
| 2 | `ĐỀ 001.docx` | Bài làm sinh viên | Đề 01 | 3 câu | Format A | Bản song sinh của `De_0001.docx` ($N = 5769$) |
| 3 | `ĐỀ 002.docx` | Bài làm sinh viên (có ảnh đề) | Đề 02 | 3 câu | Format A | $N = 5121$, hệ 5 PT mod {3,5,7,11,13}, $A = \begin{bmatrix}6&2&1\\2&4&2\\1&2&3\end{bmatrix}$ |
| 4 | `102240319_NguyenThanhLuan (1).docx` | Bài làm sinh viên | Đề 03 | 3 câu | Format A | $N = 12000$, hệ 5 PT mod {5,7,9,13,17}, $A = \begin{bmatrix}4&1&2\\1&8&2\\2&2&10\end{bmatrix}$ |
| 5 | `De_04_GK_102240207.docx` | Bài làm sinh viên | Đề 04 | 3 câu | Format A | $N = 10000$, hệ 5 PT mod {5,7,11,13,17}, $A = \begin{bmatrix}6&1&2\\1&5&2\\2&2&7\end{bmatrix}$ |
| 6 | `ĐỀ-3.docx` | Đề thi + bài làm | Đề 0001 | 4 câu | Format B | $N = 11530$, hệ 4 PT mod {3,5,7,11}, $A_{3\times 3}$ |
| 7 | `102230313_DoanHoangThienPhu.docx` | Bài làm sinh viên | Đề 01 | 4 câu | Format B | $N = 96700$, hệ 5 PT mod {5,7,9,11,13}, $A_{LDL^T}$, $A_{SVD}$ |
| 8 | `De_0002.docx` | Đề thi gốc chuẩn (chỉ có đề) | Đề 0002 | 4 câu | Format B | $N = 403$, hệ 4 PT mod {3,5,7,11}, $A_{3\times 3}$ |
| 9 | `ĐỀ 4.docx` | Bài làm sinh viên | Đề 4 | 4 câu | Format B | Biến thể từ `De_0002.docx` ($N = 403$) |
| 10 | `ĐỀ-4.docx` | Bài làm sinh viên | Đề 0002 | 4 câu | Format B | Bản sinh viên của `De_0002.docx` ($N = 403$) |
| 11 | `Đáp án đề 02.docx` | Bài làm sinh viên / Đáp án | Đề 02 | 4 câu | Format B | $N = 10583$, hệ 4 PT mod {7,9,11,17}, $A_{3\times 3}$ |
| 12 | `ĐỀ 5.docx` | Bài làm sinh viên | Đề 02 | 4 câu | Format B | Bản song sinh của `Đáp án đề 02.docx` ($N = 10583$) |
| 13 | `De_03.docx` | Đề thi gốc chuẩn (chỉ có đề) | Đề 03 | 4 câu | Format B | $N = 97700$, hệ 5 PT mod {5,7,9,11,13}, $A_{3\times 3}$ |
| 14 | `Đáp án đề 03.docx` | Đáp án chuẩn có ảnh đề gốc | Đề 03 | 4 câu | Format B | Bản đầy đủ ảnh công thức gốc của `De_03.docx` |
| 15 | `ĐỀ 6.docx` | Bài làm sinh viên | Đề 03 | 4 câu | Format B | Bản sinh viên của `De_03.docx` ($N = 97700$) |

---

## 2. Knowledge Reference & Ánh xạ Dạng toán

Căn cứ vào tài liệu giảng dạy chính thức tại `/home/phuqy/Develop/MathApplicationForIT/thầy P.C.Thắng/Slides` và Đề cương chi tiết học phần:

### 2.1 Chương 1: Lý thuyết số (Number Theory) — `Chap_1_corr.pdf`
- **Dạng 1.1: Phân tích thừa số nguyên tố & Ước số nguyên tố**
  - Phân tích số nguyên dương $N$ thành tích các thừa số nguyên tố: $N = p_1^{a_1} p_2^{a_2} \dots p_k^{a_k}$.
  - Tìm ước số nguyên tố lớn nhất $M$ của $N$.
  - Liệt kê các số nguyên tố nhỏ hơn $M$ và tính tổng (Sử dụng sàng Eratosthenes).
- **Dạng 1.2: Số hoàn hảo (Perfect Numbers)**
  - Khái niệm: Số bằng tổng các ước số thực sự của nó ($\sigma(n) = 2n$).
  - Thuật toán kiểm tra số hoàn hảo, liệt kê số hoàn hảo trong khoảng $[1, N]$ hoặc $[1, M]$ và tính tổng.
- **Dạng 1.3: Số nguyên tố cùng nhau & Phi hàm Euler (Euler's Totient Function)**
  - Tìm các số nguyên tố cùng nhau với $N$ (hoặc $K$): $\gcd(x, N) = 1$.
  - Đếm số lượng, liệt kê và tính tổng.
- **Dạng 1.4: Số nguyên tố gần nhất thỏa mãn điều kiện chia hết**
  - Tìm số nguyên tố gần $N$ nhất (hoặc gần $M$ nhất) và chia hết cho một số nguyên (hoặc số nguyên tố gần nhất).
- **Dạng 1.5: Hệ phương trình đồng dư bậc nhất — Định lý số dư Trung Hoa (CRT - Chinese Remainder Theorem)**
  - Dạng tổng quát:
    $$\begin{cases} x \equiv a_1 \pmod{m_1} \\ x \equiv a_2 \pmod{m_2} \\ \vdots \\ x \equiv a_k \pmod{m_k} \end{cases}$$
  - Điều kiện: Các modulo đôi một nguyên tố cùng nhau ($\gcd(m_i, m_j) = 1, \forall i \neq j$).
  - Thuật toán giải: Tìm $M = \prod m_i$, $M_i = M / m_i$, nghịch đảo modulo $y_i = M_i^{-1} \pmod{m_i}$ bằng thuật toán Euclid mở rộng (Extended Euclidean Algorithm), nghiệm $x = \sum (a_i M_i y_i) \pmod M$.

### 2.2 Chương 2: Đại số tuyến tính (Linear Algebra) — `Chap_2_1_anh.pdf`, `Chap_2_2_anh.pdf`, `Chap_2_3_anh.pdf`
- **Dạng 2.1: Phân rã Cholesky biến thể — Phân rã $LDL^T$**
  - Điều kiện áp dụng: Ma trận vuông $A$ đối xứng ($A = A^T$).
  - Dạng phân rã: $A = L D L^T$, trong đó $L$ là ma trận tam giác dưới có đường chéo chính toàn số 1, $D$ là ma trận đường chéo.
  - Yêu cầu đề thi: Cần có hàm kiểm tra điều kiện đối xứng của ma trận trước khi phân rã.
- **Dạng 2.2: Phân rã theo trị riêng và vector riêng (Eigendecomposition & Chéo hóa)**
  - Tìm các giá trị riêng $\lambda_i$ và vector riêng tương ứng $v_i$: $A v_i = \lambda_i v_i$.
  - Dạng phân rã / Chéo hóa: $A = Q \Lambda Q^{-1}$ (hoặc $P D P^{-1}$), trong đó $\Lambda$ là ma trận đường chéo chứa các giá trị riêng, $Q$ là ma trận chứa các vector riêng tương ứng.
  - Kiểm tra độ chính xác với sai số cho trước $\varepsilon = 10^{-5}$.
- **Dạng 2.3: Phân rã giá trị suy biến — SVD (Singular Value Decomposition)**
  - Dạng phân rã: $A = U \Sigma V^T$.
  - Trong đó: $U$ trực giao cấp $m \times m$, $\Sigma$ chứa các giá trị suy biến (singular values $\sigma_i = \sqrt{\lambda_i}$ của $A^T A$), $V$ trực giao cấp $n \times n$.
  - Sai số thực thi $\varepsilon = 10^{-5}$.

---

## 3. Nội dung Đề bài Chi tiết Trích xuất từ 15 Tệp

### PHẦN I: CÁC ĐỀ THI ĐỊNH DẠNG 3 CÂU (FORMAT A - THANG ĐIỂM 10)

#### Đề A-01 (Nguồn: `De_0001.docx`, `ĐỀ 001.docx` - Đề số 01)
- **Câu 1 (3 điểm) [Dạng: Lý thuyết số - Thừa số nguyên tố & Sàng nguyên tố]:**
  Cho số nguyên dương $N = 5769$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Phân tích thừa số nguyên tố đối với số $N$.
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$.
  - Liệt kê các số nguyên tố nhỏ hơn $M$ và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 2 \pmod 3 \\ x \equiv 4 \pmod 5 \\ x \equiv 6 \pmod 7 \\ x \equiv 9 \pmod{11} \\ x \equiv 12 \pmod{17} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (5 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận:
  $$A = \begin{bmatrix} 4 & 1 & 2 \\ 1 & 3 & 0 \\ 2 & 0 & 5 \end{bmatrix}$$
  Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
  a) Phân rã **Cholesky** $LDL^T$ ma trận $A$.
  b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

#### Đề A-02 (Nguồn: `ĐỀ 002.docx` - Đề số 02)
- **Câu 1 (3 điểm) [Dạng: Lý thuyết số - Thừa số nguyên tố & Sàng nguyên tố]:**
  Cho số nguyên dương $N = 5121$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Phân tích thừa số nguyên tố đối với số $N$.
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$.
  - Liệt kê các số nguyên tố nhỏ hơn $M$ và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 2 \pmod 3 \\ x \equiv 4 \pmod 5 \\ x \equiv 6 \pmod 7 \\ x \equiv 7 \pmod{11} \\ x \equiv 8 \pmod{13} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (5 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận:
  $$A = \begin{bmatrix} 6 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 3 \end{bmatrix}$$
  Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
  a) Phân rã **Cholesky** $LDL^T$ ma trận $A$.
  b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

#### Đề A-03 (Nguồn: `102240319_NguyenThanhLuan (1).docx` - Đề số 03)
- **Câu 1 (3 điểm) [Dạng: Lý thuyết số - Số hoàn hảo & Số nguyên tố cùng nhau & Euler]:**
  Cho số nguyên dương $N = 12000$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số lượng các số hoàn hảo nhỏ hơn $N$, liệt kê và tính tổng của chúng.
  - Gọi $M$ là số hoàn hảo lớn nhất vừa tìm được, tìm số $K$ gần $M$ nhất sao cho $K$ chia hết cho 7.
  - Tìm số lượng các số nguyên dương nhỏ hơn $K$ và nguyên tố cùng nhau với $K$. Liệt kê các số đó và tính tổng của chúng.
  - Tìm số $P$ là số nguyên tố gần $K$ nhất.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 2 \pmod 5 \\ x \equiv 4 \pmod 7 \\ x \equiv 6 \pmod 9 \\ x \equiv 9 \pmod{13} \\ x \equiv 12 \pmod{17} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (5 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận:
  $$A = \begin{bmatrix} 4 & 1 & 2 \\ 1 & 8 & 2 \\ 2 & 2 & 10 \end{bmatrix}$$
  Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
  a) Phân rã $LDL^T$ ma trận $A$.
  b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

#### Đề A-04 (Nguồn: `De_04_GK_102240207.docx` - Đề số 04)
- **Câu 1 (3 điểm) [Dạng: Lý thuyết số - Số hoàn hảo & Số nguyên tố cùng nhau & Euler]:**
  Cho số nguyên dương $N = 10000$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số lượng các số hoàn hảo nhỏ hơn $N$, liệt kê và tính tổng của chúng.
  - Gọi $M$ là số hoàn hảo lớn nhất vừa tìm được, tìm số $K$ gần $M$ nhất sao cho $K$ chia hết cho 7.
  - Tìm số lượng các số nguyên dương nhỏ hơn $K$ và nguyên tố cùng nhau với $K$. Liệt kê các số đó và tính tổng của chúng.
  - Tìm số $P$ là số nguyên tố gần $K$ nhất.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 3 \pmod 5 \\ x \equiv 4 \pmod 7 \\ x \equiv 6 \pmod{11} \\ x \equiv 8 \pmod{13} \\ x \equiv 9 \pmod{17} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (5 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận:
  $$A = \begin{bmatrix} 6 & 1 & 2 \\ 1 & 5 & 2 \\ 2 & 2 & 7 \end{bmatrix}$$
  Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
  a) Phân rã $LDL^T$ ma trận $A$.
  b) Phân rã **eigendecomposition** ma trận $A$ (với sai số $\varepsilon = 10^{-5}$).

---

### PHẦN II: CÁC ĐỀ THI ĐỊNH DẠNG 4 CÂU (FORMAT B - THANG ĐIỂM 10)

#### Đề B-01 (Nguồn: `ĐỀ-3.docx` - Đề số 0001)
- **Câu 1 (2 điểm) [Dạng: Lý thuyết số - Ước nguyên tố lớn nhất & Số hoàn hảo & Sàng nguyên tố]:**
  Cho số nguyên dương $N = 11530$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo nhỏ hơn $M$, liệt kê và tính tổng của chúng.
  - Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 1 \pmod 3 \\ x \equiv 3 \pmod 5 \\ x \equiv 4 \pmod 7 \\ x \equiv 5 \pmod{11} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ (có hàm kiểm tra điều kiện phân rã):
  a) Phân rã **Cholesky** $LDL^T$ ma trận $A$ với $A = \begin{bmatrix} 1 & 2 & 3 \\ 2 & 7 & 3 \\ 3 & 3 & 3 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
  b) Phân rã **eigendecomposition** ma trận $A$ với $A = \begin{bmatrix} 1 & 2 & 3 \\ 6 & 7 & 3 \\ 8 & 9 & 3 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
- **Câu 4 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận SVD]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:
  $$A = \begin{bmatrix} 1 & 2 & 3 \\ 6 & 7 & 3 \\ 8 & 9 & 3 \end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})$$

---

#### Đề B-02 (Nguồn: `102230313_DoanHoangThienPhu.docx` - Đề số 01)
- **Câu 1 (2 điểm) [Dạng: Lý thuyết số - Ước nguyên tố lớn nhất & Số hoàn hảo & Sàng nguyên tố]:**
  Cho số nguyên dương $N = 96700$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo (giữa 1 và $M$), liệt kê và tính tổng của chúng.
  - Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 3 \pmod 5 \\ x \equiv 5 \pmod 7 \\ x \equiv 7 \pmod 9 \\ x \equiv 9 \pmod{11} \\ x \equiv 11 \pmod{13} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
  a) Phân rã $LDL^T$ ma trận $A$ với $A = \begin{bmatrix} -7 & 9 & 20 \\ 9 & -7 & 18 \\ 20 & 18 & -7 \end{bmatrix}$ (bao gồm điều kiện ma trận đối xứng).
  b) Phân rã **eigendecomposition** ma trận $A$ với $A = \begin{bmatrix} -7 & 9 & 20 \\ 9 & -7 & 18 \\ 20 & 18 & -7 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
- **Câu 4 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận SVD]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:
  $$A = \begin{bmatrix} 5 & 5 & 9 \\ 2 & 2 & 5 \\ 3 & 4 & 5 \end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})$$

---

#### Đề B-03 (Nguồn: `De_0002.docx`, `ĐỀ 4.docx`, `ĐỀ-4.docx` - Đề số 0002 / Đề số 4)
- **Câu 1 (2 điểm) [Dạng: Lý thuyết số - Số nguyên tố cùng nhau & Số nguyên tố chia hết cho 3]:**
  Cho số nguyên dương $N = 403$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số lượng các số nguyên dương (giữa 1 và $N$) là nguyên tố cùng nhau với $N$ ($N > 1$), liệt kê và tính tổng của chúng.
  - Tìm số nguyên tố gần $N$ nhất và chia hết cho 3. *(Lưu ý: số nguyên tố duy nhất chia hết cho 3 là số 3).*
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 2 \pmod 3 \\ x \equiv 4 \pmod 5 \\ x \equiv 6 \pmod 7 \\ x \equiv 7 \pmod{11} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
  a) Phân rã $LDL^T$ ma trận $A$ với $A = \begin{bmatrix} 4 & 8 & 6 \\ 8 & 8 & 6 \\ 9 & 8 & 6 \end{bmatrix}$ (yêu cầu kiểm tra điều kiện đối xứng).
  b) Phân rã **eigendecomposition** ma trận $A$ với $A = \begin{bmatrix} 4 & 8 & 6 \\ 8 & 8 & 6 \\ 9 & 8 & 6 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
- **Câu 4 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận SVD]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:
  $$A = \begin{bmatrix} 4 & 8 & 6 \\ 8 & 8 & 6 \\ 9 & 8 & 6 \end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})$$

---

#### Đề B-04 (Nguồn: `Đáp án đề 02.docx`, `ĐỀ 5.docx` - Đề số 02)
- **Câu 1 (2 điểm) [Dạng: Lý thuyết số - Ước nguyên tố lớn nhất & Số hoàn hảo]:**
  Cho số nguyên dương $N$ ($N > 1$). Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$ ($M < N$), biết rằng $N = 10583$.
  - Tìm số lượng các số hoàn hảo nhỏ hơn $M$, liệt kê và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 5 \pmod 7 \\ x \equiv 7 \pmod 9 \\ x \equiv 9 \pmod{11} \\ x \equiv 13 \pmod{17} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
  a) Phân rã $LDL^T$ ma trận $A$ với $A = \begin{bmatrix} 13 & 3 & 9 \\ 3 & 12 & 6 \\ 9 & 6 & 13 \end{bmatrix}$ (điều kiện ma trận vuông và đối xứng).
  b) Phân rã **eigendecomposition** ma trận $A$ với $A = \begin{bmatrix} 13 & 3 & 9 \\ 3 & 12 & 6 \\ 9 & 6 & 13 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
- **Câu 4 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận SVD]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:
  $$A = \begin{bmatrix} 9 & 7 & 3 \\ 7 & 8 & 6 \\ 8 & 8 & 9 \end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})$$

---

#### Đề B-05 (Nguồn: `De_03.docx`, `Đáp án đề 03.docx`, `ĐỀ 6.docx` - Đề số 03)
- **Câu 1 (2 điểm) [Dạng: Lý thuyết số - Ước nguyên tố lớn nhất & Số hoàn hảo & Sàng nguyên tố]:**
  Cho số nguyên dương $N = 97700$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện:
  - Tìm số $M$ là ước số nguyên tố lớn nhất của $N$; tìm số lượng các số hoàn hảo (giữa 1 và $M$), liệt kê và tính tổng của chúng.
  - Tìm các số nguyên tố bé hơn $M$, liệt kê và tính tổng của chúng.
- **Câu 2 (2 điểm) [Dạng: Lý thuyết số - Định lý số dư Trung Hoa (CRT)]:**
  Cho hệ phương trình đồng dư sau:
  $$\begin{cases} x \equiv 2 \pmod 5 \\ x \equiv 3 \pmod 7 \\ x \equiv 4 \pmod 9 \\ x \equiv 5 \pmod{11} \\ x \equiv 6 \pmod{13} \end{cases}$$
  Viết chương trình C/C++ có sử dụng hàm giải hệ phương trình đồng dư trên.
- **Câu 3 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận $LDL^T$ và Eigendecomposition]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$:
  a) Phân rã $LDL^T$ ma trận $A$ với $A = \begin{bmatrix} -10 & 4 & 7 \\ 4 & -5 & 8 \\ 7 & 8 & -9 \end{bmatrix}$ (yêu cầu điều kiện ma trận vuông và đối xứng).
  b) Phân rã **eigendecomposition** ma trận $A$ với $A = \begin{bmatrix} 10 & 2 & 8 \\ 9 & 0 & 0 \\ 9 & 7 & 6 \end{bmatrix}$ (sai số $\varepsilon = 10^{-5}$).
- **Câu 4 (3 điểm) [Dạng: Đại số tuyến tính - Phân rã ma trận SVD]:**
  Cho ma trận $A$. Viết chương trình bằng C/C++ có sử dụng hàm thực hiện phân rã ma trận $A$ bằng phương pháp **SVD** với:
  $$A = \begin{bmatrix} 10 & 2 & 8 \\ 9 & 0 & 0 \\ 9 & 7 & 6 \end{bmatrix} \quad (\text{sai số } \varepsilon = 10^{-5})$$

---

## 4. Epistemic Ledger (Sổ tay Nhận thức)

### Confirmed (Đã chứng thực 100%)
- Toàn bộ 15 tệp .docx đã được phân loại chính xác thành 2 format (Format A gồm 4 bộ đề, Format B gồm 5 bộ đề).
- Mọi hệ phương trình đồng dư và ma trận đều đã được đối chiếu chéo qua hình ảnh gốc, mã MathType OLE và kết quả thực thi của sinh viên, đảm bảo độ chính xác tuyệt đối.
- Toàn bộ câu hỏi thuộc về phạm vi 2 chương đầu: Chương 1 (Lý thuyết số) và Chương 2 (Đại số tuyến tính) của học phần Toán ứng dụng CNTT (Giảng viên: TS. Phạm Công Thắng).

### Observed (Quan sát thấy)
- Format A (3 câu) gộp $LDL^T$ và Eigendecomposition vào một câu 3 (5 điểm).
- Format B (4 câu) tách $LDL^T$ & Eigendecomposition thành Câu 3 (3 điểm) và SVD thành Câu 4 (3 điểm).
- Đề bài luôn yêu cầu viết chương trình C/C++ có sử dụng hàm, kiểm tra điều kiện ma trận (tính đối xứng cho $LDL^T$), và chấp nhận sai số $\varepsilon = 10^{-5}$ cho các phép tính gần đúng.

---

## 5. Gate G0 — Deterministic Halting Predicate Check

| Tiêu chí | Biểu thức điều kiện | Trạng thái | Minh chứng |
|---|---|---|---|
| L_known | Không gian khảo sát xác định | **PASS** | Đã quét và lập danh mục toàn bộ 15 file .docx |
| B_understood | Hiểu rõ cấu trúc và nội dung đề bài | **PASS** | Đã bóc tách đề bài gốc, loại bỏ code sinh viên, chuyển đổi MathType sang LaTeX |
| C_known | Ràng buộc dạng toán & kiến thức nền | **PASS** | Đã map toàn bộ câu hỏi vào Slide Chap 1 & Chap 2 của Thầy P.C. Thắng |
| P_checked | Không sót trường hợp/biến thể | **PASS** | Đã phân tích đủ 9 bộ đề con đại diện cho 15 tệp |
| V_known | Phương pháp kiểm chứng khả thi | **PASS** | Trích xuất thành công, kiểm chứng chéo hình ảnh/kết quả thực thi |

**Kết luận Gate G0:** Đạt chuẩn hoàn tất giai đoạn Research (`R_complete = PASS`). Sẵn sàng trình kỹ sư phê duyệt để bước sang giai đoạn tiếp theo (INNOVATE / PLAN / EXECUTE).
</research_context>
